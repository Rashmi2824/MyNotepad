#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/nayak/Desktop/My Pictures & Resume/withoutChasma.PNG");
    ui->label_pic->setPixmap(pix.scaled(240,240,Qt::KeepAspectRatio));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    accept();
}

