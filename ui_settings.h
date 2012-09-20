/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Wed Sep 19 21:26:54 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbOK;
    QPushButton *pbCancel;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(414, 140);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/drive.png"), QSize(), QIcon::Normal, QIcon::Off);
        Settings->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(Settings);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(56, 44, 261, 31));
        toolButton = new QToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(315, 44, 31, 31));

        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pbOK = new QPushButton(Settings);
        pbOK->setObjectName(QString::fromUtf8("pbOK"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pbOK->sizePolicy().hasHeightForWidth());
        pbOK->setSizePolicy(sizePolicy1);
        pbOK->setBaseSize(QSize(0, 0));
        pbOK->setDefault(true);
        pbOK->setFlat(false);

        horizontalLayout->addWidget(pbOK);

        pbCancel = new QPushButton(Settings);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));

        horizontalLayout->addWidget(pbCancel);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "UDMon settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Settings", "Set an application to open if a device is plugged in", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("Settings", "...", 0, QApplication::UnicodeUTF8));
        pbOK->setText(QApplication::translate("Settings", "Save", 0, QApplication::UnicodeUTF8));
        pbCancel->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
