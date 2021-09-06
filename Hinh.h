#pragma once
class Hinh
{
public:
	int x1, y1, x2, y2;
	Hinh()
	{
		x1 = 0, y1 = 0;
		x2 = 0, y2 = 0;
	}
	void virtual setX1Y1(int mx1, int my1)
	{

	}
	void virtual setX2Y2(int mx2, int my2)
	{

	}
	void virtual dichlen(int d)
	{
		y1 -= d;
		y2 -= d;
	}
	void virtual dichxuong(int d)
	{
		y1 += d;
		y2 += d;
	}
	void virtual dichtrai(int d)
	{
		x1 -= d;
		x2 -= d;
	}
	void virtual dichphai(int d)
	{
		x1 += d;
		x2 += d;
	}
	void virtual vehinh(CClientDC* pdc)
	{
		//khong thuc hien ve
	}
	int virtual kttronghinh(CPoint p)
	{
		if (p.x > x1 && p.y > y1 && p.x < x2 && p.y < y2)
		{
			return 1;
		}
		return 0;
	}
	int chamhinh(Hinh* phinh)
	{

		if (x2 < phinh->x1 || x1 > phinh->x2 || y2 < phinh->y1 || y1 > phinh->y2)
			return 0;
		else
			return 1;
	}
	
};

