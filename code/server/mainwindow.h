#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QMessageBox>

#include <clients.h>
#include <console.h>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    void StartListerning(std::string ip);
    void ConnectToClient(SOCKET sListen, int sizeofaddr, SOCKADDR_IN addr);
    void GetDataAboutClient(SOCKET Connection, SOCKADDR_IN addr);
private slots:
    void on_StartListerningButton_clicked();
    void on_TableClientData_cellDoubleClicked(int row, int column);
    void SendMessageClient(QString message);
    void GetScreenClient(int index);
    std::vector<std::string> split(std::string& str, const std::string& delimiter);
    void on_SendButton_clicked();

public:
    std::vector <Clients> ClientVector;
    Ui::MainWindow *ui;
    console ConsoleUI;
};
#endif // MAINWINDOW_H
