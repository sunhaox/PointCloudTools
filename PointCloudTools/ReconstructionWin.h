#pragma once

#include <QDialog>
#include "ui_ReconstructionWin.h"

class ReconstructionClass
{
public:
	int ksearch;
	double searchRadius;
	double mu;
	int maxNeighbors;
	double maxSurfaceAngle;
	double minAngle;
	double maxAngle;
};

class ReconstructionWin : public QDialog
{
	Q_OBJECT

public:
	ReconstructionWin(QWidget *parent = Q_NULLPTR);
	~ReconstructionWin();

signals:
	void infoSend(ReconstructionClass);

public slots:
	void yesBtnPressed();
	void noBtnPressed();

private:
	Ui::ReconstructionWin ui;
};
