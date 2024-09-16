#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::recieveUserData(const QString &name, const QString &last_name, const QString &number)
{
    ui -> label -> setText(name);
    ui -> label_2 -> setText(last_name);
    ui -> label_3 -> setText(number);
}
