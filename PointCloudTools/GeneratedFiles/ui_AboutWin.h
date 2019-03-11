/********************************************************************************
** Form generated from reading UI file 'AboutWin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWIN_H
#define UI_ABOUTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutWin
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AboutWin)
    {
        if (AboutWin->objectName().isEmpty())
            AboutWin->setObjectName(QStringLiteral("AboutWin"));
        AboutWin->resize(430, 267);
        label = new QLabel(AboutWin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 40, 241, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(AboutWin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 60, 121, 141));
        label_2->setPixmap(QPixmap(QString::fromUtf8("Resources/images/logo.png")));
        label_3 = new QLabel(AboutWin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 100, 261, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_3->setFont(font1);
        label_3->setTextFormat(Qt::RichText);
        label_3->setWordWrap(false);
        label_3->setIndent(-1);

        retranslateUi(AboutWin);

        QMetaObject::connectSlotsByName(AboutWin);
    } // setupUi

    void retranslateUi(QDialog *AboutWin)
    {
        AboutWin->setWindowTitle(QApplication::translate("AboutWin", "AboutWin", 0));
        label->setText(QApplication::translate("AboutWin", "Point Cloud Tools", 0));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("AboutWin", "<html><head/><body><p>Version 0.9.0</p><p>Copyright(c) 2019 <span style=\" font-weight:600;\">Haden Sun</span>.</p><p>All rights reserved.</p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutWin: public Ui_AboutWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWIN_H
