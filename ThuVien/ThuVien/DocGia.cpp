#include "DocGia.h"



DocGia::DocGia()
{
	_maDocGia="";
	 _ten="";
	_diachi="";
	_status=0;
}
DocGia::~DocGia()
{
}

void DocGia::setMaDocGia(string ma)
{
	_maDocGia = ma;
}
void DocGia::setTen(string ten)
{
	_ten = ten;
}
void DocGia::setDiachi(string dc)
{
	_diachi = dc;
}
void DocGia::setStatus(bool sta)
{
	_status = sta;
}
void DocGia::setPhieu(Phieu* ph)
{
	_ds.push_back(ph);
}

string DocGia::getMaDocgia()
{
	return _maDocGia;
}
string DocGia::getTen()
{
	return _ten;
}
string DocGia::getDC()
{
	return _diachi;
}
bool DocGia::getStatus()
{
	return _status;
}
vector<Phieu*> DocGia::getdsPhieu()
{
	return _ds;
}
Phieu* DocGia::getPhieu()
{
	return _ds.back();
}

void DocGia::nhap()
{
	
	cout << "\nNhap Ma doc gia: ";
	getline(cin, _maDocGia);
	cout << "Nhap ten: ";
	getline(cin, _ten);
	cout << "Nhap dia chi: ";
	getline(cin, _diachi);
}
void DocGia::xuat()
{
	cout << "\nMa Doc Gia: " << _maDocGia;
	cout << "\nTen: " << _ten;
	cout << "\nDia Chi: " << _diachi;
	cout << "\nTinh trang muon sach: ";
	if (_status == 1)
		cout << "Co.";
	else
		cout << "Khong.";
	if (_ds.size() != 0)
	{
		cout << "\nDanh sach phieu:";
		for (unsigned i = 0; i < _ds.size(); i++)
		{
			cout << "\n------------------------------------";
			if (_ds[i]->getType() == "MS")
				cout << "\n\nPhieu muon sach::::";
			else
				cout << "\n\nPhieu tra sach::::";
			_ds[i]->xuat();
			cout << "\n------------------------------------";
		}
			
	}

}
ostream& operator<<(ostream& out, const DocGia &a)
{
	out << a._maDocGia << endl;
	out << a._ten << endl;
	out << a._diachi << endl;
	out << a._status << endl;
	out << a._ds.size()<<endl;
	for (int i = 0; i < a._ds.size(); i++)
	{
		
		if (a._ds[i]->getType() == "TS")
			out << "TS" << endl;
		else
			out << "MS" << endl;
		out << *a._ds[i];
		if (a._ds[i]->getType() == "TS")
		{
			out << ((PhieuTraSach*)a._ds[i])->getNgaytra() << endl;
			out << ((PhieuTraSach*)a._ds[i])->getFine() << endl;
		}

	}
	return out;
}
