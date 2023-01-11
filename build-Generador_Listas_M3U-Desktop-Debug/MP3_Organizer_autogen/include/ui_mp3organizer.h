/********************************************************************************
** Form generated from reading UI file 'mp3organizer.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MP3ORGANIZER_H
#define UI_MP3ORGANIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MP3Organizer
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtPath;
    QPushButton *browseButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListWidget *listMP3;
    QLabel *label_3;
    QListWidget *listM3U;
    QLabel *lblResult;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelButton;
    QPushButton *continueButton;

    void setupUi(QWidget *MP3Organizer)
    {
        if (MP3Organizer->objectName().isEmpty())
            MP3Organizer->setObjectName(QString::fromUtf8("MP3Organizer"));
        MP3Organizer->resize(399, 347);
        verticalLayout_2 = new QVBoxLayout(MP3Organizer);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MP3Organizer);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txtPath = new QLineEdit(MP3Organizer);
        txtPath->setObjectName(QString::fromUtf8("txtPath"));
        txtPath->setReadOnly(true);

        horizontalLayout->addWidget(txtPath);

        browseButton = new QPushButton(MP3Organizer);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        horizontalLayout->addWidget(browseButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(MP3Organizer);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        listMP3 = new QListWidget(MP3Organizer);
        listMP3->setObjectName(QString::fromUtf8("listMP3"));

        verticalLayout->addWidget(listMP3);

        label_3 = new QLabel(MP3Organizer);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        listM3U = new QListWidget(MP3Organizer);
        listM3U->setObjectName(QString::fromUtf8("listM3U"));

        verticalLayout->addWidget(listM3U);


        verticalLayout_2->addLayout(verticalLayout);

        lblResult = new QLabel(MP3Organizer);
        lblResult->setObjectName(QString::fromUtf8("lblResult"));

        verticalLayout_2->addWidget(lblResult);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cancelButton = new QPushButton(MP3Organizer);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        continueButton = new QPushButton(MP3Organizer);
        continueButton->setObjectName(QString::fromUtf8("continueButton"));

        horizontalLayout_2->addWidget(continueButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(MP3Organizer);

        QMetaObject::connectSlotsByName(MP3Organizer);
    } // setupUi

    void retranslateUi(QWidget *MP3Organizer)
    {
        MP3Organizer->setWindowTitle(QCoreApplication::translate("MP3Organizer", "MP3Organizer", nullptr));
        label->setText(QCoreApplication::translate("MP3Organizer", "Direcci\303\263n carpeta:", nullptr));
        browseButton->setText(QCoreApplication::translate("MP3Organizer", "Explorar", nullptr));
        label_2->setText(QCoreApplication::translate("MP3Organizer", "Archivos MP3 encontrados:", nullptr));
        label_3->setText(QCoreApplication::translate("MP3Organizer", "Archivos M3U encontrados / generados:", nullptr));
        lblResult->setText(QCoreApplication::translate("MP3Organizer", "[+]Estado:...", nullptr));
        cancelButton->setText(QCoreApplication::translate("MP3Organizer", "Cancelar", nullptr));
        continueButton->setText(QCoreApplication::translate("MP3Organizer", "Generar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MP3Organizer: public Ui_MP3Organizer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MP3ORGANIZER_H
