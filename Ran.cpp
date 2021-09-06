#include "pch.h"
#include "Ran.h"

Ran::Ran()
{
	int mx = 0, my = 0;
	int setup = 0;
	dau = Hinhtron(mx, my, mx + DAI, my + DAI);
	mattrai = Hinhtron(dau.x1 + 12, dau.y1 + 15, dau.o.x - 10, dau.o.y - 10);
	matphai = Hinhtron(dau.o.x + 10, mattrai.y1, dau.x2 - 11, mattrai.y2);
	n = 1;
	baohieuthemduoi = 0;
	duoi[0] =  Duoi(dau.x1, dau.y2, dau.x1 + DAI, dau.y2 + DAI);
	duoi->setupdoc();
}

Ran::Ran(int mx, int my)
{
	int setup = 0;
	dau = Hinhtron(mx, my, mx + DAI, my + DAI);
	mattrai = Hinhtron(dau.x1 + 12, dau.y1+15 , dau.o.x -10, dau.o.y -10);
	matphai = Hinhtron( dau.o.x+10, mattrai.y1, dau.x2-11 , mattrai.y2);
	n = 1;
	baohieuthemduoi = 0;
	duoi[0] = Duoi(dau.x1, dau.y2, dau.x1 + DAI, dau.y2 + DAI);
	duoi->setupdoc();
}

void Ran::vehinh(CClientDC* pdc)
{
	
	CBrush* brush = new CBrush(RGB(255, 0, 0));
	CBrush* oldbrush;
	pdc->SelectObject(brush);
	dau.vehinh(pdc);
	brush = new CBrush(RGB(220, 216, 0));
	oldbrush = pdc->SelectObject(brush);
	mattrai.vehinh(pdc);
	matphai.vehinh(pdc);
	pdc->SelectObject(oldbrush);
	
	for (int i = 0; i < n; i++)
	{
		
		duoi[i].vehinh(pdc);
	}
}

void Ran::dichchuyenlen()
{
	setup =0 ;
	doicho();
	dau.dichlen(DAI);
	dau.capnhattam();
	mattrai.dichlen(DAI);
	matphai.dichlen(DAI);
	mattrai = Hinhtron(dau.x1 + 12, dau.y1 + 15, dau.o.x - 10, dau.o.y - 10);
	matphai = Hinhtron(dau.o.x + 10, mattrai.y1, dau.x2 - 11, mattrai.y2);
	
	
}

void Ran::dichchuyenxuong()
{
	setup = 0;
	doicho();
	dau.dichxuong(DAI);
	dau.capnhattam();
	mattrai.dichxuong(DAI);
	matphai.dichxuong(DAI);
	mattrai = Hinhtron(dau.x1 + 12, dau.o.y+10, dau.o.x - 10, dau.y2-15);
	matphai = Hinhtron(dau.o.x + 10, mattrai.y1, dau.x2 - 11, mattrai.y2);
}

void Ran::dichchuyentrai()
{
	setup = 1;
	doicho();
	dau.dichtrai(DAI);
	dau.capnhattam();
	mattrai.dichtrai(DAI);
	matphai.dichtrai(DAI);
	mattrai = Hinhtron(dau.x1 + 15, dau.y2 - 11, dau.o.x - 10, dau.o.y + 10);
	matphai = Hinhtron(mattrai.x1, dau.o.y - 10, mattrai.x2, dau.y1 + 11);
}

void Ran::dichchuyenphai()
{
	setup = 1;
	doicho();
	dau.dichphai(DAI);
	dau.capnhattam();
	mattrai.dichphai(DAI);
	matphai.dichphai(DAI);
	mattrai = Hinhtron(dau.x2 - 16, dau.y1 + 13, dau.o.x + 9, dau.o.y - 12);
	matphai = Hinhtron(mattrai.x1, dau.o.y + 12, mattrai.x2, dau.y2 - 13);
}

void Ran::doicho()
{
	if (baohieuthemduoi == 1 && n < 100)
	{
		n++;
		baohieuthemduoi = 0;
	}
	for (int i = n - 1; i > 0; i--)
	{
		duoi[i].x1 = duoi[i - 1].x1;
		duoi[i].y1 = duoi[i - 1].y1;
		duoi[i].x2 = duoi[i - 1].x2;
		duoi[i].y2 = duoi[i - 1].y2;
		duoi[i].capnhattam();
		if(setup==1)
			duoi[i].setupdoc();
		else
			duoi[i].setupngang();
	}
	duoi[0].x1 = dau.x1;
	duoi[0].y1 = dau.y1;
	duoi[0].x2 = dau.x2;
	duoi[0].y2 = dau.y2;
	duoi[0].capnhattam();
	if (setup == 1)
		duoi[0].setupdoc();
	else
		duoi[0].setupngang();
}

void Ran::themduoi()
{
	baohieuthemduoi = 1;
}

int Ran::ktdaudungduoi()
{
	int mx = (dau.x1 + dau.x2) / 2;
	int my = (dau.y1 + dau.y2) / 2;
	for (int i = 1; i < n; i++)
	{
		if (duoi[i].kttronghinh(CPoint(mx, my)) == 1)
			return 1; 
	}
	return 0;
}
int Ran::chamdauran(Hinh* hinh)
{
	if (dau.chamhinh(hinh))
		return 1;
	else
		return 0;
}
int Ran::chamthanran(Hinh* hinh)
{

	for (int i = 0; i < n; i++)
	{
		if (duoi[i].chamhinh(hinh) == 1)
			return 1;
	}
	return 0;
}
