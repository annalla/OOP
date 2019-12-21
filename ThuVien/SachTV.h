#pragma once
#ifndef SACHTV_H_
#define SACHTV_H_
#include"Sach.h"
class SachTV:public Sach
{
public:
	SachTV();
	SachTV(string ma, string ten, string tg, string nxb, unsigned gia);
	SachTV(const SachTV& a);

	~SachTV();

	string getType();
	void nhap();
	void xuat();
	
};
#endif
