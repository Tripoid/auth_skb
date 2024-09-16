#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private slots:
    void on_pushButton_clicked();

    bool check_phone(const QString& str);
    bool check_name(const QString& str);

    void saveData(const QString &data);

signals:
    void send_data(const QString &name, const QString &last_name, const QString &number);

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
