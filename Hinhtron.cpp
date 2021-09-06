#include "pch.h"
#include "Hinhtron.h"

Hinhtron::Hinhtron()
{
	x1 = 0, y1 = 0;
	x2 = 0, y2 = 0;
	r = 0;
	o.x = 0;
	o.y = 0;
}

Hinhtron::Hinhtron(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1, y1 = my1;
	x2 = mx2, y2 = my2;
	o.x = (x1 + x2) / 2;
	o.y = (y1 + y2) / 2;
	int r1 = (x2 - x1) / 2;
	int r2 = (y2 - y1) / 2;
	if (r1 < r2)
		r = r1;
	else
		r = r2;
}

void Hinhtron::setX1Y1(int mx1, int my1)
{
	x1 = mx1, y1 = my1;
	o.x = (x1 + x2) / 2;
	o.y = (y1 + y2) / 2;
	int r1 = (x2 - x1) / 2;
	int r2 = (y2 - y1) / 2;
	if (r1 < r2)
		r = r1;
	else
		r = r2;
}

void Hinhtron::setX2Y2(int mx2, int my2)
{
	x2 = mx2, y2 = my2;
	o.x = (x1 + x2) / 2;
	o.y = (y1 + y2) / 2;
	int r1 = (x2 - x1) / 2;
	int r2 = (y2 - y1) / 2;
	if (r1 < r2)
		r = r1;
	else
		r = r2;
}

void Hinhtron::vehinh(CClientDC* pdc)
{
	capnhattam();
	pdc->Ellipse(o.x - r, o.y - r, o.x + r, o.y + r);
	
}

void Hinhtron::capnhattam()
{
	o.x = (x1 + x2) / 2;
	o.y = (y1 + y2) / 2;
	int r1 = (x2 - x1) / 2;
	int r2 = (y2 - y1) / 2;
	if (r1 < r2)
		r = r1;
	else
		r = r2;
}

