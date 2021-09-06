#pragma once
#include "Hinhtron.h"
class MOI :
    public Hinhtron
{
public:
    MOI() :Hinhtron()
    {}
    MOI(int mx1, int my1, int mx2, int my2) :Hinhtron( mx1, my1,  mx2, my2)
    {}
    void vehinh(CClientDC* pdc);
};

