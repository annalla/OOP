#include "Sach.h"



Sach::Sach()
{
	_masach = "";
	_tensach = "";
	 _tacgia = "";
	_nxb = "";
	 _giasach = 0;
}
Sach::Sach(string ma, string ten, string tg, string nxb, unsigned gia)
{
	_masach = ma;
	_tensach = ten;
	_tacgia = tg;
	_nxb = nxb;
	_giasach = gia;
}
Sach::Sach(const Sach&a)
{
	_masach = a._masach;
	_tensach = a._tensach;
	_tacgia = a._tacgia;
	_nxb = a._nxb;
	_giasach = a._giasach;
}

Sach::~Sach()
{
}

void Sach::setMaSach(string ma)
{
	_masach = ma;
}
void Sach::setTenSach(string ten)
{
	_tensach = ten;
}
void Sach::setTacGia(string tg)
{
	_tacgia = tg;
}
void Sach::setNXB(string nxb)
{
	_nxb = nxb;
}
void Sach::setGiaSach(unsigned gia)
{
	_giasach = gia;
}

string Sach::getMaSach()
{
	return _masach;
}
string Sach::getTenSach()
{
	return _tensach;
}
string Sach::getTacGia()
{
	return _tacgia;
}
string Sach::getNXB()
{
	return _nxb;
}
unsigned Sach::getGiaSach()
{
	return _giasach;
}

void Sach::nhap()
{
	
	cout << "Nhap Ma Sach:";
	cin.ignore();
	getline(cin, _masach);
	cout << "Nhap Ten Sach:";
	getline(cin, _tensach);
	cout << "Nhap Tac gia:";
	getline(cin, _tacgia);
	cout << "Nhap NXB:";
	getline(cin, _nxb);
	cout << "Nhap Gia Sach:";
	cin >> _giasach;
	cin.ignore();
}
void Sach::xuat()
{
	cout << "\nMa Sach: " << _masach;
	cout << "\nTen Sach: " << _tensach;
	cout << "\nTac gia: " << _tacgia;
	cout << "\nNXB: " << _nxb;
	cout << "\nGia Sach: " << _giasach;
}
ostream& operator<<(ostream& out, const Sach &s)
{
	out<< s._masach<<endl;
	out<< s._tensach << endl;
	out<< s._tacgia << endl;
	out<< s._nxb << endl;
	out<< s._giasach << endl;
	return out;
}