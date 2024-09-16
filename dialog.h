#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void recieveUserData(const QString &name, const QString &last_name, const QString &number);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
