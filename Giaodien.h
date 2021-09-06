#pragma once
#include"HCN.h"
#include"Moi.h"
#include"Ran.h"
#define RONG 450
#define XDAU 20
#define YDAU 20
class Giaodien
{
public:
	int dk;
	int diem, thang;
	int huongdi, dinhhuong;
	HCN duongvien;
	MOI moi;
	Ran ran;
	Giaodien();
	void thietlap();
	void vehinh(CClientDC* pdc);
	void batdau();
	void dichuyen();
	void kiemtrabien();
	void capnhathinh(CClientDC* pdc);
	void rananmoi();
	void taomoi();
	void ktdungduoi();
};

