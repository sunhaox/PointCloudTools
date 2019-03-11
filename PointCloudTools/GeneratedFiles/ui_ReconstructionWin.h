/********************************************************************************
** Form generated from reading UI file 'ReconstructionWin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECONSTRUCTIONWIN_H
#define UI_RECONSTRUCTIONWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ReconstructionWin
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *normalKEdit;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLineEdit *greedyMuEdit;
    QLabel *label_2;
    QLineEdit *greedySearchRadiusEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *greedyMaxSurAngEdit;
    QLineEdit *greedyMinAngEdit;
    QLabel *label_6;
    QLineEdit *greedyMaxNeighborsEdit;
    QLabel *label_7;
    QLineEdit *greedyMaxAngEdit;
    QPushButton *yesBtn;

    void setupUi(QDialog *ReconstructionWin)
    {
        if (ReconstructionWin->objectName().isEmpty())
            ReconstructionWin->setObjectName(QStringLiteral("ReconstructionWin"));
        ReconstructionWin->resize(400, 219);
        gridLayout = new QGridLayout(ReconstructionWin);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(ReconstructionWin);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 60));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(102, 0));

        horizontalLayout_2->addWidget(label);

        normalKEdit = new QLineEdit(groupBox);
        normalKEdit->setObjectName(QStringLiteral("normalKEdit"));

        horizontalLayout_2->addWidget(normalKEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(ReconstructionWin);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        greedyMuEdit = new QLineEdit(groupBox_2);
        greedyMuEdit->setObjectName(QStringLiteral("greedyMuEdit"));

        gridLayout_3->addWidget(greedyMuEdit, 0, 3, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        greedySearchRadiusEdit = new QLineEdit(groupBox_2);
        greedySearchRadiusEdit->setObjectName(QStringLiteral("greedySearchRadiusEdit"));

        gridLayout_3->addWidget(greedySearchRadiusEdit, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 1, 2, 1, 1);

        greedyMaxSurAngEdit = new QLineEdit(groupBox_2);
        greedyMaxSurAngEdit->setObjectName(QStringLiteral("greedyMaxSurAngEdit"));

        gridLayout_3->addWidget(greedyMaxSurAngEdit, 1, 1, 1, 1);

        greedyMinAngEdit = new QLineEdit(groupBox_2);
        greedyMinAngEdit->setObjectName(QStringLiteral("greedyMinAngEdit"));

        gridLayout_3->addWidget(greedyMinAngEdit, 1, 3, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        greedyMaxNeighborsEdit = new QLineEdit(groupBox_2);
        greedyMaxNeighborsEdit->setObjectName(QStringLiteral("greedyMaxNeighborsEdit"));

        gridLayout_3->addWidget(greedyMaxNeighborsEdit, 2, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 2, 2, 1, 1);

        greedyMaxAngEdit = new QLineEdit(groupBox_2);
        greedyMaxAngEdit->setObjectName(QStringLiteral("greedyMaxAngEdit"));

        gridLayout_3->addWidget(greedyMaxAngEdit, 2, 3, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        yesBtn = new QPushButton(ReconstructionWin);
        yesBtn->setObjectName(QStringLiteral("yesBtn"));

        gridLayout->addWidget(yesBtn, 2, 0, 1, 1);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(normalKEdit);
        label_2->setBuddy(greedySearchRadiusEdit);
        label_3->setBuddy(greedyMuEdit);
        label_4->setBuddy(greedyMaxSurAngEdit);
        label_5->setBuddy(greedyMinAngEdit);
        label_6->setBuddy(greedyMaxNeighborsEdit);
        label_7->setBuddy(greedyMaxAngEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(normalKEdit, greedySearchRadiusEdit);
        QWidget::setTabOrder(greedySearchRadiusEdit, greedyMaxSurAngEdit);
        QWidget::setTabOrder(greedyMaxSurAngEdit, greedyMaxNeighborsEdit);
        QWidget::setTabOrder(greedyMaxNeighborsEdit, greedyMuEdit);
        QWidget::setTabOrder(greedyMuEdit, greedyMinAngEdit);
        QWidget::setTabOrder(greedyMinAngEdit, greedyMaxAngEdit);
        QWidget::setTabOrder(greedyMaxAngEdit, yesBtn);

        retranslateUi(ReconstructionWin);

        QMetaObject::connectSlotsByName(ReconstructionWin);
    } // setupUi

    void retranslateUi(QDialog *ReconstructionWin)
    {
        ReconstructionWin->setWindowTitle(QApplication::translate("ReconstructionWin", "ReconstructionWin", 0));
        groupBox->setTitle(QApplication::translate("ReconstructionWin", "Normal Estimation", 0));
        label->setText(QApplication::translate("ReconstructionWin", "K Search", 0));
        normalKEdit->setText(QApplication::translate("ReconstructionWin", "20", 0));
        groupBox_2->setTitle(QApplication::translate("ReconstructionWin", "Greedy Projection Triangulation", 0));
        greedyMuEdit->setText(QApplication::translate("ReconstructionWin", "2.5", 0));
        label_2->setText(QApplication::translate("ReconstructionWin", "Search Radius", 0));
        greedySearchRadiusEdit->setText(QApplication::translate("ReconstructionWin", "25", 0));
        label_3->setText(QApplication::translate("ReconstructionWin", "Mu", 0));
        label_4->setText(QApplication::translate("ReconstructionWin", "Max Surface Angle\357\274\210rad)", 0));
        label_5->setText(QApplication::translate("ReconstructionWin", "Min Angle(rad)", 0));
        greedyMaxSurAngEdit->setText(QApplication::translate("ReconstructionWin", "1.5707963", 0));
        greedyMinAngEdit->setText(QApplication::translate("ReconstructionWin", "0.1745329222222222", 0));
        label_6->setText(QApplication::translate("ReconstructionWin", "Max Neighbors", 0));
        greedyMaxNeighborsEdit->setText(QApplication::translate("ReconstructionWin", "100", 0));
        label_7->setText(QApplication::translate("ReconstructionWin", "Max Angle(rad)", 0));
        greedyMaxAngEdit->setText(QApplication::translate("ReconstructionWin", "2.094395066666667", 0));
        yesBtn->setText(QApplication::translate("ReconstructionWin", "Yes", 0));
    } // retranslateUi

};

namespace Ui {
    class ReconstructionWin: public Ui_ReconstructionWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECONSTRUCTIONWIN_H
