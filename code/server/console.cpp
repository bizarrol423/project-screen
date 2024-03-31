#include "console.h"
#include "ui_console.h"

console::console(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::console)
{
    ui->setupUi(this);
}

console::~console()
{
    delete ui;
}

void console::SetSize(){
    this->setGeometry(this->x(),this->y()+31,this->width(),this->height());
    ui->label->setGeometry(0,0,this->width(),this->height());
}

void console::SetPhoto(char *photo, int size){
    try{
        QByteArray byteArray(photo, size);
        QPixmap pixmap;
        pixmap.loadFromData(byteArray);
        ui->label->setPixmap(pixmap);
    }catch(int error){
        qDebug() << error;
    }
}
