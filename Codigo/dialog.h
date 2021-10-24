#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


    std::string getUsuario() const;

    std::string getContra() const;

signals:
    //QString texto();
    void back();


private slots:
    void on_aceptar1_clicked();

private:
    Ui::Dialog *ui;
    std::string usuario="", contra="";
};

#endif // DIALOG_H
