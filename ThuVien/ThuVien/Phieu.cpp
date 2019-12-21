#include "Phieu.h"



Phieu::Phieu()
{
	_tenDocGia="";
	_maDocGia="";
	_sl = 0;
}
void Phieu::setDocGia(string ten, string ma)
{
	_tenDocGia = ten;
	_maDocGia = ma;
}
void Phieu::setNgayMuon(Date day)
{
	_ngaymuon = day;
}
void Phieu::setSl(unsigned sl,  unsigned slTV)
{
	if (sl > 3)
		_sl = 3;
	_sl = sl;
	_slSachTV = slTV;
}
void Phieu::setSach( string maS, string tenS)
{
	_sach.insert(pair<string,string>(maS, tenS));
}

string Phieu::getTenDG()
{
	return _tenDocGia;
}
string Phieu::getMaDG()
{
	return _maDocGia;
}
Date Phieu::getNgayMuon()
{
	return _ngaymuon;
}
unsigned Phieu::getSoLuong()
{
	return _sl;
}
unsigned Phieu::getSoLuongSTV()
{
	return _slSachTV;
}
map<string, string> Phieu::getSach()
{
	return _sach;
}
void Phieu::nhap()
{
	cout << "\nNhap ma doc gia:";
	getline(cin, _maDocGia);
	cout << "Nhap ten doc gia:";
	unsigned sl, slTV;
	getline(cin, _tenDocGia);
	do
	{
		cout << "Nhap so luong sach muon:";
		cin >> sl;
		cout << "Nhap so luong sach TV muon:";
		cin >> slTV;
		if (sl > 3 || slTV > 3)
			cout << "\nThu vien cho muon toi da 3 quyen sach!!";
	} while (sl > 3 && slTV>3);
	
	cin.ignore();
	setSl(sl,slTV);
	string MaSach, TenSach;
	for (unsigned i = 0; i < _sl; i++)
	{
		cout << "Nhap ma sach thu "<<i+1<<" :";
		
		getline(cin, MaSach);
		cout << "Nhap ten sach " << i + 1 << " :";
		getline(cin,TenSach);
		setSach(MaSach, TenSach);

	}
	
	cout << "Nhap ngay muon theo cau truc --/--/--: ";
	cin >> _ngaymuon;
}
void Phieu::xuat()
{
	cout << "\nMa doc gia:" << _maDocGia;
	cout << "\nTen doc gia:" << _tenDocGia;
	cout << "\nSo luong sach muon:" << _sl;
	cout << "\nSo luong sach TV muon:" << _slSachTV;
	cout << "\nSo luong sach Ngoai Van muon:" << _sl-_slSachTV;
	unsigned j = 0;
	for (map<string, string>::iterator i =_sach.begin(); i != _sach.end(); i++)
	{
		cout << "\nMa sach thu " << j + 1 << " :"<<i->first;
		cout << "\nTen sach thu " << j + 1 << " :"<<i->second;
		j++;
	}
	cout << "\nNgay muon: "<<_ngaymuon;
}
Phieu::~Phieu()
{
}
ostream& operator<<(ostream& out, const Phieu &a)
{
	out << a._maDocGia << endl;
	out << a._tenDocGia << endl;
	out << a._sl << endl;
	out << a._slSachTV << endl;
	map<string, string> sach;
	for (auto&ch : a._sach)
	{
		out << ch.first << endl;
		out<< ch.second << endl;
	}
	out << a._ngaymuon << endl;
	return out;
}