#ifndef CLIENTS_H
#define CLIENTS_H

#include <QMainWindow>
#include <QThread>

#include <iostream>
#include <winsock2.h>
#include <Windows.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <thread>

namespace Ui {class Clients;}

class Clients {
public:
    Clients();
    ~Clients();

public:
    void GetSocket();
    std::string GetSizeScreen();
    int GetDPI();

public:
    SOCKET socket;
    std::string SizeScreen;
    int DPI = 1;
};
#endif // CLIENTS_H
