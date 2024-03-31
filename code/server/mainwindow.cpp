#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->TableClientData->setRowCount(ui->TableClientData->rowCount()+1);
    //ui->TableClientData->setItem(0,0,new QTableWidgetItem(QString("1")));
    //ui->TableClientData->setItem(0,1,new QTableWidgetItem(QString("127.0.0.1")));
    //ui->TableClientData->setItem(0,2,new QTableWidgetItem(QString("1920 1080")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartListerningButton_clicked()
{
    /*
    starts listerning
    */
    std::string ip_address = (ui->IpAddress->text()).toStdString();
    if (ip_address == ""){
        QMessageBox::warning(this,"ERROR IP ADDRESS","введите IP адрес сервера");
        return;
    }
    ui->statusbar->showMessage("start listerning");
    QThread* ListerningThread = QThread::create([this, ip_address](){
        StartListerning(ip_address);
    });
    ListerningThread->start();
}


void MainWindow::on_TableClientData_cellDoubleClicked(int row, int column)
{
    /*
    doubleclick starts console
    */
    if (ConsoleUI.isVisible()){
        QMessageBox::warning(this,"Stream is open!","Close the live stream and try again");
        return;
    }
    ConsoleUI.show();
    QThread* thread_screen = QThread::create([this, row](){
        GetScreenClient(row);
    });
    thread_screen->start();
}


void MainWindow::on_SendButton_clicked()
{
    /*
    send button work
    */
    if (ui->TableClientData->currentRow() < 0){
        QMessageBox::warning(this,"Client Not Selected","Select a customer with a single click on a row in the table");
        return;
    }
    QString message = ui->CommandLine->text();
    QString InfoMessage = QString::number(ui->TableClientData->currentRow());
    InfoMessage+=" - ";
    InfoMessage+=message;
    ui->statusbar->showMessage(message);
    SendMessageClient(message);
    ui->CommadBrowser->append(InfoMessage);
    qDebug() << ui->TableClientData->currentRow();
}

