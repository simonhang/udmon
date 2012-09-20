#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    
private slots:
    void on_toolButton_clicked();

    void on_pbOK_clicked();

    void on_pbCancel_clicked();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
