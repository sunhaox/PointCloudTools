/********************************************************************************
** Form generated from reading UI file 'VoxelGridWin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOXELGRIDWIN_H
#define UI_VOXELGRIDWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VoxelGridWin
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *xEdit;
    QLabel *label_2;
    QLineEdit *yEdit;
    QLabel *label_3;
    QLineEdit *zEdit;
    QPushButton *yesBtn;

    void setupUi(QDialog *VoxelGridWin)
    {
        if (VoxelGridWin->objectName().isEmpty())
            VoxelGridWin->setObjectName(QStringLiteral("VoxelGridWin"));
        VoxelGridWin->resize(482, 98);
        verticalLayout = new QVBoxLayout(VoxelGridWin);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(VoxelGridWin);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        xEdit = new QLineEdit(VoxelGridWin);
        xEdit->setObjectName(QStringLiteral("xEdit"));

        horizontalLayout->addWidget(xEdit);

        label_2 = new QLabel(VoxelGridWin);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        yEdit = new QLineEdit(VoxelGridWin);
        yEdit->setObjectName(QStringLiteral("yEdit"));

        horizontalLayout->addWidget(yEdit);

        label_3 = new QLabel(VoxelGridWin);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        zEdit = new QLineEdit(VoxelGridWin);
        zEdit->setObjectName(QStringLiteral("zEdit"));

        horizontalLayout->addWidget(zEdit);


        verticalLayout->addLayout(horizontalLayout);

        yesBtn = new QPushButton(VoxelGridWin);
        yesBtn->setObjectName(QStringLiteral("yesBtn"));

        verticalLayout->addWidget(yesBtn);


        retranslateUi(VoxelGridWin);

        QMetaObject::connectSlotsByName(VoxelGridWin);
    } // setupUi

    void retranslateUi(QDialog *VoxelGridWin)
    {
        VoxelGridWin->setWindowTitle(QApplication::translate("VoxelGridWin", "VoxelGridWin", 0));
        label->setText(QApplication::translate("VoxelGridWin", "Leaf size of X:", 0));
        label_2->setText(QApplication::translate("VoxelGridWin", "Leaf size of Y:", 0));
        label_3->setText(QApplication::translate("VoxelGridWin", "Leaf size of Z:", 0));
        yesBtn->setText(QApplication::translate("VoxelGridWin", "Yes", 0));
    } // retranslateUi

};

namespace Ui {
    class VoxelGridWin: public Ui_VoxelGridWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOXELGRIDWIN_H
