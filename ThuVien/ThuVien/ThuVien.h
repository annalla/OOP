#pragma once
#include"DocGia.h"
#include"SachNgoaiVan.h"
#include"SachTV.h"
//Sach.txt va Docgia.txt chứa thông tin sách và đọc giả
//ThongTinSach.txt va ThongTinDocgia.txt chứa thông tin sách và đọc giả cho người quản lý thư viện kiểm tra
//Đọc giả mượn 1 lần tối đa 3 quyền sách
//Đọc giả sau khi trả sách mới được mượn tiếp
class ThuVien
{
private:
	vector<Sach*> _dsSach;
	vector<DocGia> _dsDG;
public:

	void ThemSach();
	vector<Sach*> TimSach();
	void XoaSach();
	void SuaSach();
	void lietkeSach();

	void ThemDocgia();
	void SuaDocgia();
	void XoaDocgia();
	vector<DocGia> TimDocgia();
	void lietkeDocgia();

	void lapPhieuMuonSach();
	void lapPhieuTraSach();
	void LKDocGiaMuonQuaHan();
	void luuSach();
	void luuDocGia();
	void layThongTinSach();
	void layThongTinDocGia();
	ThuVien();
	~ThuVien();
};

