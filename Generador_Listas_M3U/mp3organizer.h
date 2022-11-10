#ifndef MP3ORGANIZER_H
#define MP3ORGANIZER_H

#include <QWidget>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MP3Organizer; }
QT_END_NAMESPACE

class MP3Organizer : public QWidget
{
    Q_OBJECT

public:
    MP3Organizer(QWidget *parent = nullptr);
    ~MP3Organizer();

private slots:
    void on_browseButton_clicked();

    void on_cancelButton_clicked();

    void on_continueButton_clicked();

private:
    Ui::MP3Organizer *ui;
    QString Path;
    void refresh_ui_list();
};
#endif // MP3ORGANIZER_H
