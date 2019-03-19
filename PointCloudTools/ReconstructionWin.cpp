#include "ReconstructionWin.h"

ReconstructionWin::ReconstructionWin(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.yesBtn, SIGNAL(clicked()), this, SLOT(yesBtnPressed()));
}

ReconstructionWin::~ReconstructionWin()
{
}

void ReconstructionWin::yesBtnPressed()
{
	ReconstructionClass rc;

	//获取输入数据
	rc.ksearch = ui.normalKEdit->text().toInt();
	rc.maxAngle = ui.greedyMaxAngEdit->text().toDouble();
	rc.minAngle = ui.greedyMinAngEdit->text().toDouble();
	rc.mu = ui.greedyMuEdit->text().toDouble();
	rc.maxNeighbors = ui.greedyMaxNeighborsEdit->text().toInt();
	rc.maxSurfaceAngle = ui.greedyMaxSurAngEdit->text().toDouble();
	rc.searchRadius = ui.greedySearchRadiusEdit->text().toDouble();

	this->hide();
	//发送信号
	emit infoSend(rc);

	this->close();
}

void ReconstructionWin::noBtnPressed()
{
	this->close();
}