#include "SachNgoaiVan.h"



SachNgoaiVan::SachNgoaiVan():Sach()
{
	_ISBN = "";
}
SachNgoaiVan::SachNgoaiVan(string ma, string ten, string tg, string nxb, unsigned gia,string isbn):Sach(ma,ten,tg,nxb,gia)
{
	_ISBN = isbn;
}
SachNgoaiVan::SachNgoaiVan(const SachNgoaiVan&a):Sach(a)
{
	_ISBN = a._ISBN;
}

SachNgoaiVan::~SachNgoaiVan()
{
}

void SachNgoaiVan::setISBN(string isbn)
{
	_ISBN = isbn;
}
string SachNgoaiVan::getISBN()
{
	return _ISBN;
}

string SachNgoaiVan::getType()
{
	return "NV";
}
void SachNgoaiVan::nhap()
{
	Sach::nhap();
	cout << "Nhap ISBN: ";
	getline(cin, _ISBN);
}
void SachNgoaiVan::xuat()
{
	Sach::xuat();
	cout << "\nISBN: " << _ISBN;
}


