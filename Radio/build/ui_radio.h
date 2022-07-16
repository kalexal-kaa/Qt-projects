/********************************************************************************
** Form generated from reading UI file 'radio.ui'
**
** Created by: Qt User Interface Compiler version 5.15.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RADIO_H
#define UI_RADIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Radio
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *deleteButton;
    QListWidget *listWidget;
    QGridLayout *gridLayout;
    QLabel *nameStation;
    QPushButton *playButton;
    QPushButton *stopButton;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label;
    QLineEdit *urlEdit;
    QPushButton *addButton;

    void setupUi(QMainWindow *Radio)
    {
        if (Radio->objectName().isEmpty())
            Radio->setObjectName(QString::fromUtf8("Radio"));
        Radio->resize(358, 311);
        centralwidget = new QWidget(Radio);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setSortingEnabled(true);

        verticalLayout->addWidget(listWidget);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nameStation = new QLabel(centralwidget);
        nameStation->setObjectName(QString::fromUtf8("nameStation"));
        nameStation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nameStation, 0, 0, 1, 2);

        playButton = new QPushButton(centralwidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));

        gridLayout->addWidget(playButton, 1, 0, 1, 1);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));

        gridLayout->addWidget(stopButton, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        urlEdit = new QLineEdit(centralwidget);
        urlEdit->setObjectName(QString::fromUtf8("urlEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, urlEdit);


        horizontalLayout->addLayout(formLayout);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 2);

        Radio->setCentralWidget(centralwidget);

        retranslateUi(Radio);

        QMetaObject::connectSlotsByName(Radio);
    } // setupUi

    void retranslateUi(QMainWindow *Radio)
    {
        Radio->setWindowTitle(QCoreApplication::translate("Radio", "Radio", nullptr));
        deleteButton->setText(QCoreApplication::translate("Radio", "delete", nullptr));
        nameStation->setText(QString());
        playButton->setText(QCoreApplication::translate("Radio", "play", nullptr));
        stopButton->setText(QCoreApplication::translate("Radio", "stop", nullptr));
        label_2->setText(QCoreApplication::translate("Radio", "name:", nullptr));
        label->setText(QCoreApplication::translate("Radio", "url:", nullptr));
        addButton->setText(QCoreApplication::translate("Radio", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Radio: public Ui_Radio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RADIO_H
