#include "pch.h"
#include "Duoi.h"


void Duoi::setupdoc()
{
	//hinh tron tren
	TREN.x1 = o.x - r / 2;
	TREN.y1 = y1;
	TREN.x2 = o.x + r / 2;
	TREN.y2 = o.y;
	//hinh tron duoi
	DUOI.x1 = o.x - r / 2;
	DUOI.y1 = o.y;
	DUOI.x2 = o.x + r / 2;
	DUOI.y2 = y2;
	//hinh tron trai
	TRAI.x1 = x1;
	TRAI.y1 = y1 + r / 2;
	TRAI.x2 = o.x;
	TRAI.y2 = o.y + r / 2;
	//hinh tron phai
	PHAI.x1 = o.x;
	PHAI.y1 = y1 + r / 2;
	PHAI.x2 = x2;
	PHAI.y2 = o.y + r / 2;
}

void Duoi::setupngang()
{
	//hinh tron tren
	TREN.x1 = x1;
	TREN.y1 = y1 + r / 2;
	TREN.x2 = o.x;
	TREN.y2 = o.y + r / 2;
	//hinh tron duoi
	DUOI.x1 = o.x;
	DUOI.y1 = y1 + r / 2;
	DUOI.x2 = x2;
	DUOI.y2 = o.y + r / 2;
	//hinh tron trai
	TRAI.x1 = o.x - r / 2;
	TRAI.y1 = y1;
	TRAI.x2 = o.x + r / 2;
	TRAI.y2 = o.y;
	//hinh tron phai
	PHAI.x1 = o.x - r / 2;
	PHAI.y1 = o.y;
	PHAI.x2 = o.x + r / 2;
	PHAI.y2 = y2;
	
}

void Duoi::vehinh(CClientDC* pdc)
{
	TREN.vehinh(pdc);
	DUOI.vehinh(pdc);
	CBrush* brush = new CBrush(RGB(220, 216, 0));
	CBrush* oldbrush;
	oldbrush=pdc->SelectObject(brush);
	TRAI.vehinh(pdc);
	PHAI.vehinh(pdc);
	pdc->SelectObject(oldbrush);
}
