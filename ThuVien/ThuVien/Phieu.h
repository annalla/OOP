#pragma once
#ifndef PHIEU_H_
#define PHIEU_H_
#include"Date.h"
#include<string>
#include<iostream>
#include<map>
using namespace std;
class Phieu
{
protected:
	string _maDocGia;
	string _tenDocGia;
	Date _ngaymuon;// muon toi da 3 cuon tren 1 lan
	unsigned _sl;//so luong sach muon
	unsigned _slSachTV;
	map<string, string> _sach;// luu ma sach , luu ten sach
public:
	Phieu();
	~Phieu();

	void setDocGia(string ten,string ma);
	void setNgayMuon(Date day);
	void setSl(unsigned sl,unsigned slTV);
	void setSach( string maS, string tenS);

	string getTenDG();
	string getMaDG();
	Date getNgayMuon();
	unsigned getSoLuong();
	unsigned getSoLuongSTV();
	map<string, string> getSach();

	virtual string getType()=0;
	virtual void nhap();
	virtual void xuat();
	friend ostream& operator<<(ostream& out, const Phieu &a);
};
#endif
