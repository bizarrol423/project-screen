#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void MainWindow::StartListerning(std::string ip){
    /*
    listerning
    */
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2,1);
    WSAStartup(DLLVersion, &wsaData);
    if (WSAStartup(DLLVersion, &wsaData) != 0){
        ui->statusbar->showMessage("[ERROR] download error");
        return;
    }
    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());
    addr.sin_port = htons(1111); // передаём порт
    addr.sin_family = AF_INET; // семейство протоколов

    // включаем прослушивание
    SOCKET sListen = socket(AF_INET, SOCK_STREAM, 0);
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); // связывает локальный адресс с сокетом
    listen(sListen, SOMAXCONN); // максимально возможное кол-во запросов
    ConnectToClient(sListen, sizeofaddr, addr);
    // далее передаём сокет в функции и работаем с ними

}

void MainWindow::ConnectToClient(SOCKET sListen, int sizeofaddr, SOCKADDR_IN addr){
    /*
    wait connection to client
    */
    SOCKET newConnection;
    qDebug() << "[INFO] wait connections";
    for(auto i = ClientVector.begin(); i<ClientVector.end() || !ClientVector.size(); i++){
        newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
        qDebug() << "[INFO] client" << newConnection;
        if (newConnection !=0 ){
            GetDataAboutClient(newConnection, addr);
        }
    }

}

void MainWindow::GetDataAboutClient(SOCKET Connection, SOCKADDR_IN addr){
    /*
    reading client information
    */
    int SizeMsg = 0;
    qDebug() << "step 2";
    if (recv(Connection, (char *)&SizeMsg, sizeof(int), 0) > 0){
        char *MessageFromClient = new char[SizeMsg];
        MessageFromClient[SizeMsg] = '\0';
        recv(Connection, MessageFromClient, SizeMsg, 0);
        qDebug() << "[INFO] " << MessageFromClient;
        if (MessageFromClient != ""){
            Clients client;
            client.socket = Connection;
            client.SizeScreen = MessageFromClient;
            ClientVector.push_back(client);
            ui->statusbar->showMessage("[INFO] client connected");
            ui->TableClientData->setRowCount(ui->TableClientData->rowCount()+1);
            int row = ui->TableClientData->rowCount()-1;
            QString IpAddress = QString::number(addr.sin_addr.S_un.S_un_b.s_b1);
            IpAddress+=".";
            IpAddress+=QString::number(addr.sin_addr.S_un.S_un_b.s_b2);
            IpAddress+=".";
            IpAddress+=QString::number(addr.sin_addr.S_un.S_un_b.s_b3);
            IpAddress+=".";
            IpAddress+=QString::number(addr.sin_addr.S_un.S_un_b.s_b4);
            ui->TableClientData->setItem(row,0,new QTableWidgetItem(QString::number(row)));
            ui->TableClientData->setItem(row,1,new QTableWidgetItem(IpAddress));
            ui->TableClientData->setItem(row,2,new QTableWidgetItem(QString(MessageFromClient)));
        }
        delete[] MessageFromClient;
    }
    qDebug() << "end";
    return;
}

void MainWindow::SendMessageClient(QString message){
    int index = ui->TableClientData->currentRow();
    char MessageClient[255] = "";
    strcpy(MessageClient, message.toStdString().c_str());
    send(ClientVector[index].socket, MessageClient,sizeof(MessageClient),0);
    ui->statusbar->showMessage("[INFO] message send");
}


void MainWindow::GetScreenClient(int index){
    /*
    get screen from client
    */
    long long unsigned int SizeMessageBuffer = 0;
    long long unsigned int PhotoSize = 0;
    int SizeMsg = 0;
    while (ConsoleUI.isVisible()){
        ConsoleUI.SetSize();
        SizeMessageBuffer = recv(ClientVector[index].socket, (char *)&SizeMsg, sizeof(long long unsigned int), MSG_WAITALL);
        if (SizeMessageBuffer > 0){
            char *photo = new char[SizeMsg+1];
            PhotoSize = recv(ClientVector[index].socket, photo, SizeMsg, MSG_WAITALL);
            ConsoleUI.SetPhoto(photo, SizeMsg);
            delete[] photo;
        }
    }
}

std::vector<std::string> MainWindow::split(std::string& str, const std::string& delimiter) {
    /*
    функция split из python
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
