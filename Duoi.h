#pragma once
#include"Hinhtron.h"
class Duoi:
	public Hinhtron
{
public:
	Hinhtron TREN, DUOI, TRAI, PHAI;
	Duoi() :Hinhtron()
	{}
	Duoi(int mx1, int my1, int mx2, int my2) :Hinhtron(mx1, my1, mx2, my2)
	{}
	void setupdoc();
	void setupngang();
	void vehinh(CClientDC* pdc);

};

