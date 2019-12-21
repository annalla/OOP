#pragma once
#ifndef PHIEUMUONSACH_H_
#define PHIEUMUONSACH_H_
#include"Phieu.h"
class PhieuMuonSach:public Phieu
{
public:
	PhieuMuonSach();
	string getType() ;
	void nhap();
	void xuat();
	~PhieuMuonSach();
};
#endif
