#include "FilterWin.h"

FilterWin::FilterWin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.yesBtn, SIGNAL(clicked()), this, SLOT(yesBtnPressed()));
}

FilterWin::~FilterWin()
{
}

void FilterWin::yesBtnPressed()
{
	FilterClass fc;
	fc.nr_k = ui.nr_k->text().toInt();
	fc.stddev_mult = ui.stddev_mult->text().toFloat();

	this->hide();

	emit infoSend(fc);

	this->close();
}