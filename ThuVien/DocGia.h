#pragma once
#ifndef DOCGIA_H_
#define DOCGIA_H_
#include<vector>
#include"PhieuMuonSach.h"
#include"PhieuTraSach.h"
class DocGia
{
private:
	string _maDocGia;
	string  _ten;
	string _diachi;
	bool _status;
	vector <Phieu*> _ds;
public:
	DocGia();
	~DocGia();

	void setMaDocGia(string ma);
	void setTen(string ten);
	void setDiachi(string dc);
	void setStatus(bool sta);
	void setPhieu(Phieu* ph);

	string getMaDocgia();
	string getTen();
	string getDC();
	bool getStatus();
	vector<Phieu*> getdsPhieu();
	Phieu* getPhieu();

	void nhap();
	void xuat();
	friend ostream& operator<<(ostream& out, const DocGia &a);
};
#endif

