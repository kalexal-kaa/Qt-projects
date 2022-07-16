#include "radio.h"
#include "ui_radio.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QDir>
QMediaPlayer *player;
QString path, currentItem = NULL;
Radio::Radio(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Radio)
{
    ui->setupUi(this);
    path = QDir::toNativeSeparators(QDir::homePath()+"/RadioStations/");
           QDir dir(path);
           if(!dir.exists()){
               dir.mkdir(path);
           }
           QStringList filesList = dir.entryList(QDir::Files);
           ui->listWidget->addItems(filesList);
           ui->stopButton->setEnabled(false);
}

Radio::~Radio()
{
    delete ui;
    delete player;
}


void Radio::on_playButton_clicked()
{
    if(currentItem==NULL){
            QMessageBox::warning(this,"Attention!","Nothing is selected");
            return;
        }
    QFile file(path+currentItem);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << file.errorString();
            return;
        }
        QTextStream stream(&file);
        QString urlStation = stream.readLine();
        file.close();
    player = new QMediaPlayer;
    player->setMedia(QUrl(urlStation));
    player->play();
    ui->nameStation->setText(currentItem);
    ui->playButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}

void Radio::on_stopButton_clicked()
{
    player->stop();
    ui->nameStation->clear();
    ui->playButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
}

void Radio::on_addButton_clicked()
{
    QString name = ui->nameEdit->text();
    if(name.trimmed().length()==0){
            QMessageBox::warning(this,"Attention!","Enter the station name");
            ui->nameEdit->setFocus();
            return;
        }
    QFile file(path+name);
    if(file.exists()){
        QMessageBox::warning(this,"Attention!","A station with this name already exists");
        ui->nameEdit->setFocus();
        return;
    }
    QString url = ui->urlEdit->text();
    if(url.trimmed().length()==0){
            QMessageBox::warning(this,"Attention!","Enter the station URL");
            ui->urlEdit->setFocus();
            return;
        }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                      qDebug() << file.errorString();
                      return;
                  }
              file.write(url.toUtf8());
              file.close();
              QDir dir(path);
                      QStringList filesList = dir.entryList(QDir::Files);
                      ui->listWidget->clear();
                      ui->listWidget->addItems(filesList);
                      QListWidgetItem *item;
                          QList<QListWidgetItem *> found = ui->listWidget->findItems(name, Qt::MatchExactly);
                          for (int i=0;i<found.count();i++){
                              item = found.at(i);
                          }
                      item->setSelected(true);
                      currentItem = name;
}

void Radio::on_deleteButton_clicked()
{
    if(currentItem==NULL){
            QMessageBox::warning(this,"Attention!","Nothing is selected");
            return;
        }
        QFile file(path+currentItem);
        QFileInfo fileInfo(file.fileName());
        QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Question", "Delete station "+fileInfo.fileName()+" ?", QMessageBox::Yes|QMessageBox::No);
          if (reply == QMessageBox::Yes) {
              if(file.remove()){
                  QDir dir(path);
                  QStringList filesList = dir.entryList(QDir::Files);
                  ui->listWidget->clear();
                  ui->listWidget->addItems(filesList);
                  currentItem = "";
              }
          }
}

void Radio::on_listWidget_itemClicked()
{
    currentItem = ui->listWidget->currentItem()->text();
}
