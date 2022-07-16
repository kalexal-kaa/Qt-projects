#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QTextBrowser>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QDir>
QString path, currentItem = NULL;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    path = QDir::toNativeSeparators(QDir::homePath()+"/MyNotes/");
        QDir dir(path);
        if(!dir.exists()){
            dir.mkdir(path);
        }
        QStringList filesList = dir.entryList(QDir::Files);
        ui->listWidget->addItems(filesList);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(currentItem==NULL){
        QMessageBox::warning(this,"Attention!","Nothing is selected");
        return;
    }
    QString s = ui->textBrowser->toPlainText();
    if(s.trimmed().length()==0){
        QMessageBox::warning(this,"Attention!","Nothing to save");
        return;
    }
    QFile file(path+currentItem);
    QFileInfo fileInfo(file.fileName());
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Question", "Save note "+fileInfo.fileName()+" ?", QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                  qDebug() << file.errorString();
                  return;
              }
          file.write(s.toUtf8());
          file.close();
      }
}

void MainWindow::on_pushButton_2_clicked()
{
    QDateTime dt = QDateTime::currentDateTime();
    QFile file(path+dt.toString());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << file.errorString();
            return;
        }else{
        currentItem = dt.toString();
        QDir dir(path);
        QStringList filesList = dir.entryList(QDir::Files);
        ui->listWidget->clear();
        ui->listWidget->addItems(filesList);
        QListWidgetItem *item;
            QList<QListWidgetItem *> found = ui->listWidget->findItems(currentItem, Qt::MatchExactly);
            for (int i=0;i<found.count();i++){
                item = found.at(i);
            }
        item->setSelected(true);
        ui->textBrowser->clear();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(currentItem==NULL){
        QMessageBox::warning(this,"Attention!","Nothing is selected");
        return;
    }
    QFile file(path+currentItem);
    QFileInfo fileInfo(file.fileName());
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Question", "Delete note "+fileInfo.fileName()+" ?", QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          if(file.remove()){
              QDir dir(path);
              QStringList filesList = dir.entryList(QDir::Files);
              ui->listWidget->clear();
              ui->listWidget->addItems(filesList);
              ui->textBrowser->clear();
              currentItem = "";
          }
      }
}

void MainWindow::on_listWidget_itemClicked()
{
    currentItem = ui->listWidget->currentItem()->text();
        QFile file(path+currentItem);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                qDebug() << file.errorString();
                return;
            }
            QString text;
            QTextStream in(&file);
            while (!in.atEnd()) {
               text += in.readLine()+"\n";
            }
           file.close();
           ui->textBrowser->setText(text);
}
