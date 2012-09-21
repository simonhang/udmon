/********************************************************************************
** Form generated from reading UI file 'utray.ui'
**
** Created: Fri Sep 21 20:08:23 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UTRAY_H
#define UI_UTRAY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Utray
{
public:

    void setupUi(QDialog *Utray)
    {
        if (Utray->objectName().isEmpty())
            Utray->setObjectName(QString::fromUtf8("Utray"));
        Utray->resize(240, 320);

        retranslateUi(Utray);

        QMetaObject::connectSlotsByName(Utray);
    } // setupUi

    void retranslateUi(QDialog *Utray)
    {
        Utray->setWindowTitle(QApplication::translate("Utray", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Utray: public Ui_Utray {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UTRAY_H
