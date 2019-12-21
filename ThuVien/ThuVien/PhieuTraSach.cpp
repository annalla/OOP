#include "PhieuTraSach.h"



PhieuTraSach::PhieuTraSach():Phieu()
{
	_tienphat = 0;
}


PhieuTraSach::~PhieuTraSach()
{
}
void PhieuTraSach::setNgaytra(Date _ngTra)
{
	_ngaytra = _ngTra;
}
void PhieuTraSach::setFine(unsigned fine)
{
	_tienphat = fine;
}
string PhieuTraSach::getType()
{
	return "TS";
}
Date PhieuTraSach::getNgaytra()
{
	return _ngaytra;
}
unsigned PhieuTraSach::getFine()
{
	return _tienphat;
}
unsigned PhieuTraSach::calFine()
{

	int day = _ngaytra - _ngaymuon;

	if (day <= 7)
		 _tienphat = 0;
	else
	{
		int d = day - 7;
		_tienphat=d*_slSachTV * 10000 + d * (_sl - _slSachTV) * 20000;
	}
	return _tienphat;
}
void PhieuTraSach::nhap(Phieu* phieumuon)
{
	_tenDocGia = phieumuon->getTenDG();
	_maDocGia = phieumuon->getMaDG();
	_ngaymuon = phieumuon->getNgayMuon();
	_sl = phieumuon->getSoLuong();
	_slSachTV = phieumuon->getSoLuongSTV();
	_sach = phieumuon->getSach();
	cout << "Nhap ngay tra sach theo cau truc --/--/--:";
	cin >> _ngaytra;
}
void PhieuTraSach::xuat()
{
	Phieu::xuat();
	cout << "\nNgay tra sach: "<<_ngaytra;
	calFine();
	cout << "\nTien Phat: " << _tienphat;
}
