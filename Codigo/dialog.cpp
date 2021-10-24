#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_aceptar1_clicked()
{
    usuario=ui->us->text().toStdString();
    contra=ui->co->text().toStdString();
    emit Dialog::back();
}

std::string Dialog::getContra() const
{
    return contra;
}

std::string Dialog::getUsuario() const
{
    return usuario;
}


