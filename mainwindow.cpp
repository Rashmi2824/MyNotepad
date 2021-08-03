#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>

int countBold = 0;
int countSuper = 0;
int countSub = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{

    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionBold_triggered()
{
    countBold++;
    if(countBold % 2 != 0)
        ui->textEdit->setFontWeight(QFont::Bold);
    else
        ui->textEdit->setFontWeight(QFont::Normal);


}


void MainWindow::on_actionSuperscript_triggered()
{
    countSuper++;
    if(countSuper %2 != 0){
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
        if(ui->textEdit->hasFocus())
            ui->textEdit->mergeCurrentCharFormat(format);

    }
    else{
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
        if(ui->textEdit->hasFocus())
            ui->textEdit->mergeCurrentCharFormat(format);
    }


}


void MainWindow::on_actionsubscript_triggered()
{
    countSub++;
    if(countSub %2 != 0){
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
        if(ui->textEdit->hasFocus())
            ui->textEdit->mergeCurrentCharFormat(format);

    }
    else{
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
        if(ui->textEdit->hasFocus())
            ui->textEdit->mergeCurrentCharFormat(format);
    }
}


void MainWindow::on_actionAboutMe_triggered()
{
      //Dialog resume;
      //resume.setModal(true);
      //resume.exec();
      resume = new Dialog(this);
      resume->show();
}

