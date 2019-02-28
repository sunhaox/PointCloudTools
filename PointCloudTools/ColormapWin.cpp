#include "ColormapWin.h"

ColormapWin::ColormapWin(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	
	connect(ui.yesBtn, SIGNAL(clicked()), this, SLOT(yesBtnPressed()));
	connect(ui.noBtn, SIGNAL(clicked()), this, SLOT(noBtnPressed()));
}

ColormapWin::~ColormapWin()
{
}

void ColormapWin::yesBtnPressed()
{
	ColormapClass cc;
	cc.max = ui.maxLineedit->text().toShort();
	cc.min = ui.minLineedit->text().toShort();

	if (ui.radioButton_0->isChecked())
		cc.type = 0;
	else if (ui.radioButton_1->isChecked())
		cc.type = 1;
	else if (ui.radioButton_2->isChecked())
		cc.type = 2;
	else if (ui.radioButton_4->isChecked())
		cc.type = 4;
	else if (ui.radioButton_9->isChecked())
		cc.type = 9;
	else if (ui.radioButton_11->isChecked())
		cc.type = 11;
	else
		this->close();

	emit infoSend(cc);

	this->close();
}

void ColormapWin::noBtnPressed()
{
	this->close();
}
