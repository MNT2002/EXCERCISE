#include "pch.h"
#include "HCN.h"

HCN::HCN()
{
	x1 = 0, y1 = 0;
	x2 = 0, y2 = 0;
}

HCN::HCN(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1, y1 = my1;
	x2 = mx2, y2 = my2;
}

void HCN::vehinh(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}


void HCN::setX1Y1(int mx1, int my1)
{
	x1 = mx1;
	y1 = my1;
}

void HCN::setX2Y2(int mx2, int my2)
{
	x2 = mx2;
	y2 = my2;
}
