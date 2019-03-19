#pragma once

#include <QDialog>
#include "ui_AboutWin.h"

class AboutWin : public QDialog
{
	Q_OBJECT

public:
	AboutWin(QWidget *parent = Q_NULLPTR);
	~AboutWin();

private:
	Ui::AboutWin ui;
};
