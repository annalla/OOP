#include "SachTV.h"



SachTV::SachTV():Sach()
{
}
SachTV::SachTV(string ma, string ten, string tg, string nxb, unsigned gia):Sach(ma,ten,tg,nxb,gia)
{
}
SachTV::SachTV(const SachTV& a):Sach(a)
{
}

SachTV::~SachTV()
{
}

string SachTV::getType()
{
	return "TV";
}
void SachTV::nhap()
{
	Sach::nhap();
}
void SachTV::xuat()
{
	Sach::xuat();
}


