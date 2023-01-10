#include "mp3organizer.h"
#include "./ui_mp3organizer.h"
#include <QFile>
#include <QTextStream>
#include <QCollator>

MP3Organizer::MP3Organizer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MP3Organizer)
{
    ui->setupUi(this);
}

MP3Organizer::~MP3Organizer()
{
    delete ui;
}

void MP3Organizer::refresh_ui_list()
{
    ui->listMP3->clear();
    ui->listM3U->clear();

    QDir dir(Path);

    dir.setNameFilters(QStringList()<<"*.mp3");
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    dir.setSorting(QDir::NoSort);  // will sort manually with std::sort

    auto entryList = dir.entryList();

    QCollator collator;
    collator.setNumericMode(true);

    std::sort(
        entryList.begin(),
        entryList.end(),
        [&](const QString &file1, const QString &file2)
        {
            return collator.compare(file1, file2) < 0;
        });


    QFileInfoList list = dir.entryInfoList();
    for(int i=0; i < list.size(); i++)
    {
        ui->listMP3->addItem(list.at(i).fileName());
    }

    dir.setNameFilters(QStringList()<<"*.m3u");
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    dir.setSorting(QDir::NoSort);  // will sort manually with std::sort

    entryList = dir.entryList();

    collator.setNumericMode(true);

    std::sort(
        entryList.begin(),
        entryList.end(),
        [&](const QString &file1, const QString &file2)
        {
            return collator.compare(file1, file2) < 0;
        });

    list = dir.entryInfoList();
    for(int i=0; i < list.size(); i++)
    {
        ui->listM3U->addItem(list.at(i).fileName());
    }
}

void MP3Organizer::on_browseButton_clicked()
{
    Path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                             ".", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->txtPath->setText(Path);

    refresh_ui_list();
}

void MP3Organizer::on_cancelButton_clicked()
{
    ui->lblResult->setText("[!] List Cleared !");
    ui->listMP3->clear();
    ui->listM3U->clear();
    ui->txtPath->clear();
}


void MP3Organizer::on_continueButton_clicked()
{
    if(ui->listMP3->count() > 0)
    {
        ui->lblResult->setText("Creating .m3u files ...");

        // make a copy of listMP3
        QStringList copyList;
        for(int i=0; i < ui->listMP3->count(); i++)
        {
            QListWidgetItem *item = ui->listMP3->item(i);
            copyList << item->text();
        }

        // loop to go through rows in list
        for(int i=0; i < copyList.count() && copyList.count() > 0; i++)
        {
            QString name = copyList.at(i);

            // how many times appears char '-'
            // in format yyyy-mm-dd, appears 2 times:
            int matches = name.count('-');
            if(matches == 2)
            {
                int index = name.indexOf('-');
                QString year = name.mid(index-4,4);
                QString month = name.mid(index+1,2);
                QString day = name.mid(index+4,2);

                // search content in file
                QFile file(ui->txtPath->text()+QDir::separator()+year+"-"+month+"-"+day+".m3u");
                if(file.open(QIODevice::WriteOnly | QIODevice::Text)){file.close();};

                foreach(const QString var, copyList)
                {
                    if(var.contains(year+'-'+month+'-'+day))
                    {
                        // write name to file
                        QFile file(ui->txtPath->text()+QDir::separator()+year+"-"+month+"-"+day+".m3u");
                        if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                        {
                                  // We're going to streaming text to the file
                                  QTextStream stream(&file);

                                  stream << var << "\n";

                                  file.close();
                                  qDebug() << "Writing finished !";
                        }
                    }
                }
            }
        }

        ui->lblResult->setText("[!] Done !");
        refresh_ui_list();
    }
    else
    {
        ui->lblResult->setText("[!] List is empty");
    }
}

