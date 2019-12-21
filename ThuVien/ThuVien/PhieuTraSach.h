#pragma once
#ifndef PHIEUTRASACH_H_
#define PHIEUTRASACH_H_
#include"Phieu.h"
class PhieuTraSach:public Phieu
{
protected:
	Date _ngaytra;
	unsigned _tienphat;
public:
	PhieuTraSach();
	~PhieuTraSach();
	void setNgaytra(Date _ngTra);
	void setFine(unsigned fine);
	string getType();
	Date getNgaytra();
	unsigned getFine();
	unsigned calFine();
	void nhap(Phieu* phieumuon);
	void xuat();
	friend ostream& operator<<(ostream& out, const PhieuTraSach &a);
};
#endif
