#pragma once
#ifndef SACH_H_
#define SACH_H_
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Sach
{
protected:
	string _masach;
	string _tensach;
	string _tacgia;
	string _nxb;
	unsigned _giasach;
public:
	Sach();
	Sach(string ma,string ten,string tg,string nxb,unsigned gia);
	Sach(const Sach&a);

	~Sach();

	void setMaSach(string ma);
	void setTenSach(string ten);
	void setTacGia(string tg);
	void setNXB(string nxb);
	void setGiaSach(unsigned gia);

	string getMaSach();
	string getTenSach();
	string getTacGia();
	string getNXB();
	unsigned getGiaSach();

	virtual string getType() = 0;
	virtual void nhap();
	virtual void xuat();
	friend ostream& operator<<(ostream& out,const Sach &s);
};
#endif

