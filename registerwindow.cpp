#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include "dialog.h"

#include <QFile>
#include <QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButton_clicked()
{
    QString user_name = ui -> name -> text();
    QString user_last_name = ui -> last_name -> text();
    QString user_email = ui -> email -> text();
    QString user_phone = ui -> phone -> text();
    QString user_password = ui -> password -> text();


    QString user_info = "Имя пользователя: " + user_name + "\nФамилия пользователя: " + user_last_name + "\nНомер телефона: " + user_phone;
    QString user_data = "Данные пользователя:\nЛогин: " + user_email + "\nПароль: " + user_password;
    QString lp_form = user_email + ";" + user_password + "|";


    bool phone_status = check_phone(user_phone);
    int phone_length = user_phone.size();
    bool name_status = check_name(user_name);
    bool last_name_status = check_name(user_last_name);
    int password_length = user_password.size();


    if (name_status == false || last_name_status == false){
        QMessageBox::information(this, "Авторизация", "Найдены цифры в имени или фамилии");
    } else if (phone_status == false || phone_length < 7){
        QMessageBox::information(this, "Авторизация", "Номер введён неверно!");
    } else if (password_length < 5){
        QMessageBox::information(this, "Авторизация", "Пароль должен быть состоять не менее чем из 5 символов!");

    } else {
        saveData(lp_form);
        QFile file("C:/Users/Admin/Desktop/qt_projects/auth_skb/info.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << user_info << Qt::endl;
            file.close();
            qDebug() << "Инфа записана в файл";
        } else {
            qDebug() << "Ошибка!";
        }
        Dialog *window = new Dialog();
        connect(this, &RegisterWindow::send_data, window, &Dialog::recieveUserData);
        emit send_data(user_name, user_last_name, user_phone);
        window -> exec();
    }
}

bool RegisterWindow::check_phone(const QString& str){

    for (int i = 0; i < str.size(); ++i){
        if (!str[i].isDigit()){
            return false;
        }
    }
    return true;
}

bool RegisterWindow::check_name(const QString& name){
    for (int i = 0; i < name.size(); ++i){
        if (name[i].isDigit()){
            return false;
        }
    }
    return true;

}

void RegisterWindow::saveData(const QString &data)
{
    QFile file("C:/Users/Admin/Desktop/qt_projects/auth_skb/data.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << data << Qt::endl;
        file.close();
        qDebug() << "Логин и пароль сохранены!";
    } else {
        qDebug() << "Ошибка при сохранении логина и пароля!";
    }

}
