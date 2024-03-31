#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>
#include <iostream>

namespace Ui {
class console;
}

class console : public QWidget
{
    Q_OBJECT

public:
    explicit console(QWidget *parent = nullptr);
    ~console();
    void SetSize();
    void SetPhoto(char *photo, int size);
private:
    Ui::console *ui;
};

#endif // CONSOLE_H
