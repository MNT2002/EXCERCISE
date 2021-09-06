#pragma once

#include"Duoi.h"
#include"Hinhtron.h"
#include<Windows.h>
#include<mmsystem.h>
#define DAI 30
class Ran
{
public:
	int setup;
	Duoi duoi[100];
	Hinhtron dau, mattrai, matphai;
	int baohieuthemduoi;
	int n;
	Ran();
	Ran(int mx, int my);
	void vehinh(CClientDC* pdc);
	void dichchuyenlen();
	void dichchuyenxuong();
	void dichchuyentrai();
	void dichchuyenphai();
	void doicho();
	void themduoi();
	int ktdaudungduoi();
	int chamdauran(Hinh* hinh);
	int chamthanran(Hinh* hinh);
};

