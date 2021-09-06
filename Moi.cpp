#include "pch.h"
#include "Moi.h"

void MOI::vehinh(CClientDC* pdc)
{
	CBrush* brush = new CBrush(RGB(255, 255, 255));
	CBrush* oldbrush;
	oldbrush = pdc->SelectObject(brush);
	pdc->Ellipse(o.x - r+8, o.y - r+8, o.x + r-8, o.y + r-8);
	pdc->SelectObject(oldbrush);
}
