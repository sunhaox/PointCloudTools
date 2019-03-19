#include "VoxelGridWin.h"

VoxelGridWin::VoxelGridWin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.yesBtn, SIGNAL(clicked()), this, SLOT(yesBtnPressed()));
}

VoxelGridWin::~VoxelGridWin()
{
}

void VoxelGridWin::yesBtnPressed()
{
	VoxelGridClass vc;
	vc.lx = ui.xEdit->text().toFloat();
	vc.ly = ui.yEdit->text().toFloat();
	vc.lz = ui.zEdit->text().toFloat();

	this->hide();

	emit infoSend(vc);

	this->close();

}