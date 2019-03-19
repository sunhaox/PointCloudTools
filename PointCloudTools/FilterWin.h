#pragma once

#include <QDialog>
#include "ui_FilterWin.h"

class FilterClass
{
public:
	int nr_k;
	double stddev_mult;
};

class FilterWin : public QDialog
{
	Q_OBJECT

public:
	FilterWin(QWidget *parent = Q_NULLPTR);
	~FilterWin();

signals:
	void infoSend(FilterClass);

	public slots:
	void yesBtnPressed();

private:
	Ui::FilterWin ui;
};
