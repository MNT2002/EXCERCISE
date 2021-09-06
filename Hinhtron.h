#pragma once
#include "Hinh.h"
class Hinhtron :
    public Hinh
{
public:
    int r;
    CPoint o;
    Hinhtron();
    Hinhtron(int mx1, int my1, int mx2, int my2);
    void setX1Y1(int mx1, int my1);
    void setX2Y2(int mx2, int my2);
    void vehinh(CClientDC* pdc);
    void capnhattam();

};

