#pragma once
#include <iostream>
#include <winsock2.h>
#include <Windows.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <thread>
#include <stdio.h>
#include <future>


void send_screen(char* data, long long unsigned int size);

extern "C" __declspec(dllexport) void mai();

std::vector<std::string> split(std::string& str, const std::string& delimiter) {
    /*
    ������� split �� python
    */
    std::vector<std::string> result;
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(str);
    return result;
}

std::vector<std::string> keyboard_split(std::string& str, const std::string& delimiter) {
    std::cout << "split_keyboard\n";
    std::vector<std::string> result = {};
    std::string token = "";
    std::cout << "string_start = " << str << "\n";
    token = str.substr(0, str.find(delimiter));
    result.push_back(token);
    std::cout << "token1 = " << token << "\n";
    token = str.erase(0, str.find(delimiter) + 1);
    std::cout << "token_end = " << token << "\n";
    result.push_back(token);
    return result;
}

int mouse_work(std::vector <std::string> command) {
    /*
    ������ ������
    */
    std::cout << command.size() << std::endl;
    if (command.size() == 3) {
        int x = atoi(command[1].c_str());
        int y = atoi(command[2].c_str());
        SetCursorPos(x, y);
        ;// ������ ����������� �����
    }
    else if (command.size() == 4) {
        int x = atoi(command[1].c_str());
        int y = atoi(command[2].c_str());
        SetCursorPos(x, y);
        if (command[3] == "lclick") {
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
        }
        else {
            mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
        }
        ;// ������������ � ������ 
    }
    return 0;
}

void click_Key(char key) {
    /*
    ������� ������ �� ����������
    */
    switch (key) {
        case ';':
            keybd_event(VK_OEM_1, 0, 0, 0);
            keybd_event(VK_OEM_1, 0, KEYEVENTF_KEYUP, 0);
            break;
        case ':':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_1, 0, 0, 0);
            keybd_event(VK_OEM_1, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '+':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_PLUS, 0, 0, 0);
            keybd_event(VK_OEM_PLUS, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '=':
            keybd_event(VK_OEM_PLUS, 0, 0, 0);
            keybd_event(VK_OEM_PLUS, 0, KEYEVENTF_KEYUP, 0);
            break;
        case ',':
            keybd_event(VK_OEM_COMMA, 0, 0, 0);
            keybd_event(VK_OEM_COMMA, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '-':
            keybd_event(VK_OEM_MINUS, 0, 0, 0);
            keybd_event(VK_OEM_MINUS, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '_':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_MINUS, 0, 0, 0);
            keybd_event(VK_OEM_MINUS, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '.':
            keybd_event(VK_OEM_PERIOD, 0, 0, 0);
            keybd_event(VK_OEM_PERIOD, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '/':
            keybd_event(VK_OEM_2, 0, 0, 0);
            keybd_event(VK_OEM_2, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '?':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_2, 0, 0, 0);
            keybd_event(VK_OEM_2, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '`':
            keybd_event(VK_OEM_3, 0, 0, 0);
            keybd_event(VK_OEM_3, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '~':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_3, 0, 0, 0);
            keybd_event(VK_OEM_3, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '[':
            keybd_event(VK_OEM_4, 0, 0, 0);
            keybd_event(VK_OEM_4, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '{':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_4, 0, 0, 0);
            keybd_event(VK_OEM_4, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case ']':
            keybd_event(VK_OEM_6, 0, 0, 0);
            keybd_event(VK_OEM_6, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '}':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_6, 0, 0, 0);
            keybd_event(VK_OEM_6, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '\\':
            keybd_event(VK_OEM_5, 0, 0, 0);
            keybd_event(VK_OEM_5, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '|':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_5, 0, 0, 0);
            keybd_event(VK_OEM_5, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '\'':
            keybd_event(VK_OEM_7, 0, 0, 0);
            keybd_event(VK_OEM_7, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '\"':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_7, 0, 0, 0);
            keybd_event(VK_OEM_7, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '<':
            keybd_event(VK_OEM_102, 0, 0, 0);
            keybd_event(VK_OEM_102, 0, KEYEVENTF_KEYUP, 0);
            break;
        case '>':
            keybd_event(VK_SHIFT, 0, 0, 0);
            keybd_event(VK_OEM_102, 0, 0, 0);
            keybd_event(VK_OEM_102, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            break;
        default:
            if (key >= 97 && key <= 122) { // ������� a-z ������� ������
                key = toupper(key);
            }
            else if (key >= 65 && key <= 90) { // ������ � ������� ��������
                keybd_event(VK_SHIFT, 0, 0, 0);
            }
            std::cout << key << " = " << int(key) << "\n";
            keybd_event(key, 0, 0, 0);
            keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
            // прописать switch case
            if (key >= 65 && key <= 90) { // ������ � ������� ��������
                keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            }
    }
}

void click_enter() {
    /*
    ������� enter
    */
    keybd_event(VK_RETURN, 0, 0, 0);
    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
}

void click_ctrl(std::string command) {
    /*
    ������ ctrl
    */
    keybd_event(VK_CONTROL, 0, 0, 0);
    std::vector <std::string> key_command = split(command, "+"); // ���������� ����� +
    for (auto key = ++key_command.begin(); key != key_command.end(); key++) { // ���������� �� ������� �������� �������
        std::cout << *key << std::endl;
        for (size_t i = 0; i < (*key).size(); i++) {
            click_Key((*key)[i]);
        }
    }
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}

void click_alt(std::string command) {
    /*
    ������ alt
    */
    keybd_event(VK_MENU, 0, 0, 0);
    std::vector <std::string> key_command = split(command, "+"); // ���������� ����� +
    for (auto key = ++key_command.begin(); key != key_command.end(); key++) { // ���������� �� ������� �������� �������
        std::cout << *key << std::endl;
        for (size_t i = 0; i < (*key).size(); i++) {
            click_Key((*key)[i]);
        }
    }
    keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0);
}

void click_shift(std::string command) {
    /*
    ������ shft
    */
    std::vector <std::string> key_command = split(command, "+"); // ���������� ����� +
    for (auto key = ++key_command.begin(); key != key_command.end(); key++) { // ���������� �� ������� �������� �������
        std::cout << *key << std::endl;
        for (size_t i = 0; i < (*key).size(); i++) {
            keybd_event(VK_SHIFT, 0, 0, 0);
            click_Key((*key)[i]);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
        }
    }
}

int keyboard_work(std::vector <std::string> command) {
    /*
    ������ ����������
    */
    auto key = ++command.begin();
    if (command[1].find("enter") != std::string::npos) {
        click_enter();
        return 1;
    }
    else if (command[1].find("ctrl") != std::string::npos) { // ������� ctrl keyboard_ctrl+s
        click_ctrl(command[1]);
        key++;
    }
    else if (command[1].find("alt") != std::string::npos) { // ������� alt keyboard_alt+s
        click_alt(command[1]);
        key++;
    }
    else if (command[1].find("shift") != std::string::npos) { // ������� shift keyboard_shift+asdfg->ASDFG
        click_shift(command[1]);
        key++;
    }
    else if (command[1].find("space") != std::string::npos) { // ������� ������� keyboard_space
        keybd_event(VK_SPACE, 0, 0, 0);
        keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
        key++;
    }
    else if (command[1].find("WINDOWS") != std::string::npos) { // ������� ������� windows
        keybd_event(VK_LWIN, 0, 0, 0);
        keybd_event(VK_LWIN, 0, KEYEVENTF_KEYUP, 0);
        key++;
    }
    for (;key != command.end();key++) {
        std::cout << *key << std::endl;
        for (size_t i = 0; i < (*key).size(); i++) {
            click_Key((*key)[i]);
        }
    }
    return 1;
}
std::string command = "";

void execute_msg(char* message) {
    /*
    ��������� ������� �����
    */
    std::cout << message << '\n';
    std::string message_copy = message; // ������ ����� ���������� ��� ����� ����� ������
    std::vector <std::string> words = split(message_copy, "_");
    std::cout << words[0] << '\n';
    if (words[0] == "mouse") {
        mouse_work(words);
    }
    else if (words[0] == "keyboard") {
        std::string message_copy_key = message;
        std::vector <std::string> keyboard_words = keyboard_split(message_copy_key, "_");
        keyboard_work(keyboard_words);
    }
    else {
        std::cout << "start_command\n";
        std::string sys_command(message);
        sys_command += " 2>>error.log";
        //system(sys_command.c_str());
        command = sys_command;
        std::future<void> result = std::async(std::launch::async, []() {
            //std::cout << "async\n";
            system(command.c_str());
            });
        sys_command.clear();
        std::cout << "command_complete\n";
    }
}
// необходимо обрабоать  <> и _ сделаю это завтра утром
// вход keyboard_123_!321 -> keyboard 123_!321 обрезаем только первый _ и делим по нему\
// если первое это mouse, то входящую строку разделить ещё по _ и пустить в оборот
