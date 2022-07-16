#ifndef RADIO_H
#define RADIO_H

#include <QMainWindow>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class Radio; }
QT_END_NAMESPACE

class Radio : public QMainWindow
{
    Q_OBJECT

public:
    Radio(QWidget *parent = nullptr);
    ~Radio();

private slots:
    void on_playButton_clicked();

    void on_stopButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_listWidget_itemClicked();

private:
    Ui::Radio *ui;
    QMediaPlayer   *player;
};
#endif // RADIO_H
