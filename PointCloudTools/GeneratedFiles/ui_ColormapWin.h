/********************************************************************************
** Form generated from reading UI file 'ColormapWin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORMAPWIN_H
#define UI_COLORMAPWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColormapWin
{
public:
    QPushButton *yesBtn;
    QPushButton *noBtn;
    QLabel *label;
    QLineEdit *minLineedit;
    QLabel *label_2;
    QLineEdit *maxLineedit;
    QLabel *label_3;
    QRadioButton *radioButton_0;
    QLabel *label_4;
    QRadioButton *radioButton_1;
    QLabel *label_5;
    QRadioButton *radioButton_11;
    QLabel *label_6;
    QRadioButton *radioButton_9;
    QRadioButton *radioButton_2;
    QLabel *label_7;
    QLabel *label_8;
    QRadioButton *radioButton_4;

    void setupUi(QWidget *ColormapWin)
    {
        if (ColormapWin->objectName().isEmpty())
            ColormapWin->setObjectName(QStringLiteral("ColormapWin"));
        ColormapWin->resize(350, 170);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColormapWin->sizePolicy().hasHeightForWidth());
        ColormapWin->setSizePolicy(sizePolicy);
        ColormapWin->setMinimumSize(QSize(350, 170));
        ColormapWin->setMaximumSize(QSize(350, 170));
        yesBtn = new QPushButton(ColormapWin);
        yesBtn->setObjectName(QStringLiteral("yesBtn"));
        yesBtn->setGeometry(QRect(90, 140, 75, 23));
        noBtn = new QPushButton(ColormapWin);
        noBtn->setObjectName(QStringLiteral("noBtn"));
        noBtn->setGeometry(QRect(180, 140, 75, 23));
        label = new QLabel(ColormapWin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 54, 12));
        minLineedit = new QLineEdit(ColormapWin);
        minLineedit->setObjectName(QStringLiteral("minLineedit"));
        minLineedit->setGeometry(QRect(20, 30, 113, 20));
        label_2 = new QLabel(ColormapWin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 54, 12));
        maxLineedit = new QLineEdit(ColormapWin);
        maxLineedit->setObjectName(QStringLiteral("maxLineedit"));
        maxLineedit->setGeometry(QRect(20, 80, 113, 20));
        label_3 = new QLabel(ColormapWin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 10, 121, 16));
        label_3->setMaximumSize(QSize(16777214, 16777215));
        label_3->setPixmap(QPixmap(QString::fromUtf8("Resources/images/colorscale_autumn.jpg")));
        label_3->setScaledContents(true);
        radioButton_0 = new QRadioButton(ColormapWin);
        radioButton_0->setObjectName(QStringLiteral("radioButton_0"));
        radioButton_0->setGeometry(QRect(280, 10, 89, 16));
        label_4 = new QLabel(ColormapWin);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 30, 121, 16));
        label_4->setMaximumSize(QSize(16777214, 16777215));
        label_4->setPixmap(QPixmap(QString::fromUtf8("Resources/images/colorscale_bone.jpg")));
        label_4->setScaledContents(true);
        radioButton_1 = new QRadioButton(ColormapWin);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));
        radioButton_1->setGeometry(QRect(280, 30, 89, 16));
        label_5 = new QLabel(ColormapWin);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(150, 50, 121, 16));
        label_5->setMaximumSize(QSize(16777214, 16777215));
        label_5->setPixmap(QPixmap(QString::fromUtf8("Resources/images/colorscale_hot.jpg")));
        label_5->setScaledContents(true);
        radioButton_11 = new QRadioButton(ColormapWin);
        radioButton_11->setObjectName(QStringLiteral("radioButton_11"));
        radioButton_11->setGeometry(QRect(280, 50, 89, 16));
        label_6 = new QLabel(ColormapWin);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 70, 121, 16));
        label_6->setMaximumSize(QSize(16777214, 16777215));
        label_6->setPixmap(QPixmap(QString::fromUtf8("Resources/images/colorscale_hsv.jpg")));
        label_6->setScaledContents(true);
        radioButton_9 = new QRadioButton(ColormapWin);
        radioButton_9->setObjectName(QStringLiteral("radioButton_9"));
        radioButton_9->setGeometry(QRect(280, 70, 89, 16));
        radioButton_2 = new QRadioButton(ColormapWin);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(280, 90, 89, 16));
        radioButton_2->setChecked(true);
        label_7 = new QLabel(ColormapWin);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 90, 121, 16));
        label_7->setMaximumSize(QSize(16777214, 16777215));
        label_7->setPixmap(QPixmap(QString::fromUtf8("Resources/images/colorscale_jet.jpg")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(ColormapWin);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(150, 110, 121, 16));
        label_8->setMaximumSize(QSize(16777214, 16777215));
        label_8->setPixmap(QPixmap(QString::fromUtf8("Resources/images/colorscale_rainbow.jpg")));
        label_8->setScaledContents(true);
        radioButton_4 = new QRadioButton(ColormapWin);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));
        radioButton_4->setGeometry(QRect(280, 110, 89, 16));
        QWidget::setTabOrder(minLineedit, maxLineedit);
        QWidget::setTabOrder(maxLineedit, radioButton_0);
        QWidget::setTabOrder(radioButton_0, radioButton_1);
        QWidget::setTabOrder(radioButton_1, radioButton_11);
        QWidget::setTabOrder(radioButton_11, radioButton_9);
        QWidget::setTabOrder(radioButton_9, radioButton_2);
        QWidget::setTabOrder(radioButton_2, radioButton_4);
        QWidget::setTabOrder(radioButton_4, yesBtn);
        QWidget::setTabOrder(yesBtn, noBtn);

        retranslateUi(ColormapWin);

        QMetaObject::connectSlotsByName(ColormapWin);
    } // setupUi

    void retranslateUi(QWidget *ColormapWin)
    {
        ColormapWin->setWindowTitle(QApplication::translate("ColormapWin", "Colormap", 0));
        yesBtn->setText(QApplication::translate("ColormapWin", "Yes", 0));
        noBtn->setText(QApplication::translate("ColormapWin", "No", 0));
        label->setText(QApplication::translate("ColormapWin", "Min", 0));
        minLineedit->setText(QApplication::translate("ColormapWin", "0", 0));
        label_2->setText(QApplication::translate("ColormapWin", "Max", 0));
        maxLineedit->setText(QApplication::translate("ColormapWin", "3000", 0));
        label_3->setText(QString());
        radioButton_0->setText(QApplication::translate("ColormapWin", "AUTUMN", 0));
        label_4->setText(QString());
        radioButton_1->setText(QApplication::translate("ColormapWin", "BONE", 0));
        label_5->setText(QString());
        radioButton_11->setText(QApplication::translate("ColormapWin", "HOT", 0));
        label_6->setText(QString());
        radioButton_9->setText(QApplication::translate("ColormapWin", "HSV", 0));
        radioButton_2->setText(QApplication::translate("ColormapWin", "JET", 0));
        label_7->setText(QString());
        label_8->setText(QString());
        radioButton_4->setText(QApplication::translate("ColormapWin", "RAINBOW", 0));
    } // retranslateUi

};

namespace Ui {
    class ColormapWin: public Ui_ColormapWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORMAPWIN_H
