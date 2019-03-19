#pragma once

#include <QDialog>
#include "ui_ColormapWin.h"

class ColormapClass
{
public:
	int max;
	int min;
	int type;
};

class ColormapWin : public QDialog
{
	Q_OBJECT

public:
	ColormapWin(QWidget *parent = Q_NULLPTR);
	~ColormapWin();

signals:
	void infoSend(ColormapClass);

private:
	Ui::ColormapWin ui;

	public slots:
	void yesBtnPressed();
	void noBtnPressed();
};

