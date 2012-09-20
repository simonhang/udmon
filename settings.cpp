#include "settings.h"
#include "ui_settings.h"

#include <QFileDialog>
#include <QSettings>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());

    QSettings cfg("udmon", "udmon");
    ui->lineEdit->setText(cfg.value("execute").toString());
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_toolButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select executable");
    if(!fileName.isEmpty()) {
        ui->lineEdit->setText(fileName);
    }
}

void Settings::on_pbOK_clicked()
{
    // save settings
    if(!ui->lineEdit->text().isEmpty()) {
        QSettings cfg("udmon", "udmon");
        cfg.setValue("execute", QString(ui->lineEdit->text()));
        this->setResult(QDialog::Accepted);
        this->close();
    }
}

void Settings::on_pbCancel_clicked()
{
    this->setResult(QDialog::Rejected);
    this->close();
}
