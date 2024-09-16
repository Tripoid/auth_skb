#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerwindow.h"

#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    RegisterWindow window;
    window.setModal(true);
    window.exec();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString user_login = ui -> login -> text();
    QString user_password = ui -> password -> text();

    findData(user_login, user_password);
}

void MainWindow::findData(const QString &login, const QString &pass)
{
    bool login_flag = false;
    bool pass_flag = false;

    QFile file("C:/Users/Admin/Desktop/qt_projects/auth_skb/data.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        int login_index = content.indexOf(login, 0, Qt::CaseInsensitive);
        int pass_index = content.indexOf(pass, 0, Qt::CaseInsensitive);

        if (login_index != -1) {
            qDebug() << "Логин найден";
            login_flag = true;
        } else {
            qDebug() << "Логин не найден!";
        }

        if (pass_index != -1) {
            qDebug() << "Пароль найден";
            pass_flag = true;
        } else {
            qDebug() << "Пароль не найден!";
        }

        file.close();
    } else {
        qDebug() << "Ошибка открытия файла!";
    }

    if (login_flag && pass_flag){
        QMessageBox::information(this, "Авторизация", "Ваш аккаунт создан! Авторизация успешна");

    } else {
        QMessageBox::information(this, "Авторизация", "Ваш аккаунт ещё не создан. Зарегистрируйтесь!");

    }
}
