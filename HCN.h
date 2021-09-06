#pragma once
#include "Hinh.h"
class HCN :
    public Hinh
{
public:
    HCN();
    HCN(int mx1, int my1, int mx2, int my2);
    void vehinh(CClientDC* pdc);
    void setX1Y1(int mx1,int my1);
    void setX2Y2(int mx2,int my2);
};

