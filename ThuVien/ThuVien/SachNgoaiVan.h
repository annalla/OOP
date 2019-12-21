#pragma once
#ifndef SACHNGOAIVAN_H_
#define SACHNGOAIVAN_H_
#include"Sach.h"
class SachNgoaiVan:public Sach
{
private:
	string _ISBN;
public:
	SachNgoaiVan();
	SachNgoaiVan(string ma, string ten, string tg, string nxb, unsigned gia,string isbn);
	SachNgoaiVan(const SachNgoaiVan&a);

	~SachNgoaiVan();

	void setISBN(string isbn);
	string getISBN();
	
	string getType();
	void nhap();
	void xuat();
};
#endif

