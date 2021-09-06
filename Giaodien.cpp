#include "pch.h"
#include "Giaodien.h"

Giaodien::Giaodien()
{
	thietlap();
}

void Giaodien::thietlap()
{
	duongvien = HCN(XDAU, YDAU, XDAU + RONG, YDAU + RONG);
	dk = 0;
	diem = 0;
	thang = 0;
	huongdi = 38;
	dinhhuong = 38;
	moi = MOI(XDAU + 10 * DAI, YDAU + 10 * DAI, XDAU + 11 * DAI, YDAU + 11 * DAI);
	ran = Ran(XDAU + 10 * DAI, YDAU + 10 * DAI);
}

void Giaodien::vehinh(CClientDC* pdc)
{
	CString strdiem;
	strdiem.Format(_T("Diem:%d   "), diem);
	pdc->TextOutW(XDAU, YDAU-17, strdiem);
	if (ran.ktdaudungduoi() != 1)
	{
		CBrush* brush =new CBrush(RGB(0, 0 , 0));
		CBrush* oldbrush;
		oldbrush=pdc->SelectObject(brush);
		duongvien.vehinh(pdc);
		pdc->SelectObject(oldbrush);
		moi.vehinh(pdc);
		ran.vehinh(pdc);
	}
	if(thang==-1)
	{
		PlaySound(TEXT("h.wav"), NULL, SND_ASYNC);
		CString strthua;
		strthua.Format(_T("Tro choi ket thuc!"));
		pdc->TextOutW(XDAU + 6 * DAI-10, YDAU + 7 * DAI, strthua);
		strdiem.Format(_T("Diem ban da dat duoc la %d   "), diem);
		pdc->TextOutW(XDAU + 5 * DAI-15, YDAU + 8 * DAI-15, strdiem);
		dk = 0;
	}
}

void Giaodien::batdau()
{
	dk = 1;
	diem = 0;
	taomoi();
}

void Giaodien::dichuyen()
{
	while (dk == 1)
	{
		if (huongdi == 38)
		{
			ran.dichchuyenlen();
			dinhhuong = 38;
		}
		if (huongdi == 40)
		{
			ran.dichchuyenxuong();
			dinhhuong = 40;
		}
			
		if (huongdi == 39)
		{
			ran.dichchuyenphai();
			dinhhuong = 39;
		}
		if(huongdi==37)
		{
			ran.dichchuyentrai();
			dinhhuong=37;
		}
		rananmoi();
		kiemtrabien();
		ktdungduoi();
		Sleep(150);
	}
}

void Giaodien::kiemtrabien()
{
	if (ran.dau.y2 <= duongvien.y1)//kiem tra bien tren
	{
		ran.dau.y2 = duongvien.y2;
		ran.dau.y1 = ran.dau.y2 - DAI;
		ran.dau.capnhattam();
		ran.mattrai.y1 = ran.dau.y1 + 15, ran.mattrai.y2 = ran.dau.o.y - 10;
		ran.matphai.y1 = ran.mattrai.y1, ran.matphai.y2 = ran.mattrai.y2;

		
		return;
	}
	if (ran.dau.y1 >= duongvien.y2)//kiem tra bien duoi
	{
		ran.dau.y1 = duongvien.y1;
		ran.dau.y2 = ran.dau.y1 + DAI;
		ran.dau.capnhattam();
		ran.mattrai.y1 = ran.dau.o.y + 10, ran.mattrai.y2 = ran.dau.y2 - 15;
		ran.matphai.y1 = ran.mattrai.y1, ran.matphai.y2 = ran.mattrai.y2;
		return;
	}
	if (ran.dau.x2 <= duongvien.x1)//kiem tra bien tra trai
	{
		ran.dau.x2 = duongvien.x2;
		ran.dau.x1 = ran.dau.x2 - DAI;
		ran.dau.capnhattam();
		ran.mattrai.x1 = ran.dau.x1 + 15, ran.mattrai.x2 = ran.dau.o.x - 10;
		ran.matphai.x1 = ran.mattrai.x1, ran.matphai.x2 = ran.mattrai.x2;
		return;
	}
	if (ran.dau.x1 >= duongvien.x2)//kiem tra bien phai
	{
		ran.dau.x1 = duongvien.x1;
		ran.dau.x2 = ran.dau.x1 + DAI;
		ran.dau.capnhattam();
		ran.mattrai.x1 = ran.dau.x2 - 16, ran.mattrai.x2 = ran.dau.o.x + 9;
		ran.matphai.x1 = ran.mattrai.x1, ran.matphai.x2 = ran.mattrai.x2;
		return;
	}
}

void Giaodien::capnhathinh(CClientDC* pdc)
{
	while (dk == 1 )
	{
		vehinh(pdc);
		Sleep(50);
	}
}

void Giaodien::rananmoi()
{
	int mx = (moi.x1 + moi.x2) / 2;
	int my = (moi.y1 + moi.y2) / 2;
	if (ran.dau.kttronghinh(CPoint(mx, my)) == 1 ||ran.duoi[0].kttronghinh(CPoint(mx,my))==1)
	{
		PlaySound(TEXT("t.wav"), NULL, SND_ASYNC);
		diem+=5;
		ran.themduoi();
		Sleep(70);
		taomoi();
	}
}

void Giaodien::taomoi()
{
	if (dk == 0)
		return;
	int g = 0;
	int r = 0;
	int mx = moi.x1;
	int my = moi.y1;
	while (mx == moi.x1 || my == moi.x2)
	{
		g = RONG / DAI;
		r = rand() % g;
		mx = XDAU + r * DAI;
		r = rand() % g;
		my = YDAU + r * DAI;
	}
	//lap lai cho toi khi moi(new) khong xuat hien trong than ran hoac dau ran
	while (ran.chamdauran(&moi)==1 || ran.chamthanran(&moi)==1)
	{
		r = rand() % g;
		mx = XDAU + r * DAI;
		r = rand() % g;
		my = YDAU + r * DAI;
		moi.setX1Y1(mx, my);
		moi.setX2Y2(mx + DAI, my + DAI);
	}
	
}

void Giaodien::ktdungduoi()
{
	if (ran.ktdaudungduoi() == 1)
	{
		thang = -1;
	}
}

