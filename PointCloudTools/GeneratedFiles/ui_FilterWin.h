/********************************************************************************
** Form generated from reading UI file 'FilterWin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERWIN_H
#define UI_FILTERWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FilterWin
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nr_k;
    QLabel *label_2;
    QLineEdit *stddev_mult;
    QPushButton *yesBtn;

    void setupUi(QDialog *FilterWin)
    {
        if (FilterWin->objectName().isEmpty())
            FilterWin->setObjectName(QStringLiteral("FilterWin"));
        FilterWin->resize(448, 109);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        FilterWin->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(FilterWin);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(FilterWin);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nr_k = new QLineEdit(FilterWin);
        nr_k->setObjectName(QStringLiteral("nr_k"));

        gridLayout->addWidget(nr_k, 0, 2, 1, 1);

        label_2 = new QLabel(FilterWin);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        stddev_mult = new QLineEdit(FilterWin);
        stddev_mult->setObjectName(QStringLiteral("stddev_mult"));

        gridLayout->addWidget(stddev_mult, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        yesBtn = new QPushButton(FilterWin);
        yesBtn->setObjectName(QStringLiteral("yesBtn"));

        verticalLayout->addWidget(yesBtn);


        retranslateUi(FilterWin);

        QMetaObject::connectSlotsByName(FilterWin);
    } // setupUi

    void retranslateUi(QDialog *FilterWin)
    {
        FilterWin->setWindowTitle(QApplication::translate("FilterWin", "Filter", 0));
        label->setText(QApplication::translate("FilterWin", "The number of points to use for mean distance estimation", 0));
        nr_k->setText(QApplication::translate("FilterWin", "50", 0));
        label_2->setText(QApplication::translate("FilterWin", "The standard deviation multiplier", 0));
        stddev_mult->setText(QApplication::translate("FilterWin", "1", 0));
        yesBtn->setText(QApplication::translate("FilterWin", "Yes", 0));
    } // retranslateUi

};

namespace Ui {
    class FilterWin: public Ui_FilterWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERWIN_H
