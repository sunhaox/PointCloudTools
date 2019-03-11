#pragma once

#include <QDialog>
#include "ui_VoxelGridWin.h"


class VoxelGridClass
{
public:
	float lx;
	float ly;
	float lz;
};

class VoxelGridWin : public QDialog
{
	Q_OBJECT

public:
	VoxelGridWin(QWidget *parent = Q_NULLPTR);
	~VoxelGridWin();

signals:
	void infoSend(VoxelGridClass);

	public slots:
	void yesBtnPressed();

private:
	Ui::VoxelGridWin ui;
};
