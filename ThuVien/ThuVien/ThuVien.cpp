#include "ThuVien.h"



ThuVien::ThuVien()
{

}
ThuVien::~ThuVien()
{
}

void ThuVien::ThemSach()
{
	int n, h;
	cout << "\nNhap so luong sach can them:";
	cin >> n;
	Sach* p;
	for (int i = 0; i < n; i++)
	{
	a:
		system("cls");
		cout << "\n1. Sach Tieng Viet";
		cout << "\n2. Sach Ngoai Van";
		cout << "\n:Su lua chon:";
		cin >> h;
		switch (h)
		{
		case 1:
			p = new SachTV;
			p->nhap();
			_dsSach.push_back(p);
			break;
		case 2:
			p = new SachNgoaiVan;
			p->nhap();
			_dsSach.push_back(p);
			break;
		default:
			cout << "\nNhap lai lua chon\n";
			cin.ignore();
			goto a;
		}
	}
	
}
vector<Sach*> ThuVien::TimSach()
{
	vector<Sach*> ds;
	int h;
	Sach* p;
	string masach,tensach,tacgia;
	tim:
	system("cls");
	cout << "\n1. Tim sach theo Ma Sach";
	cout << "\n2. Tim sach theo Ten Sach";
	cout << "\n3. Tim sach theo Tac Gia";
	cout << "\n:Su lua chon:";
	cin >> h;
	switch(h)
	{
	case 1:
		cout << "\nNhap Ma Sach:";
		cin.ignore();
		getline(cin, masach);
		for (int i = 0; i < _dsSach.size(); i++)
		{
			if (masach == _dsSach[i]->getMaSach())
			{
				ds.push_back(_dsSach[i]);
				break;
			}
		}
		break;
	case 2:
		cout << "\nNhap Ten Sach:";
		cin.ignore();
		getline(cin, tensach);
		for (int i = 0; i < _dsSach.size(); i++)
		{
			if (tensach == _dsSach[i]->getTenSach())
			{
				ds.push_back(_dsSach[i]);
			}
		}
		break;
	case 3:
		cout << "\nNhap Tac gia:";
		cin.ignore();
		getline(cin, tacgia);
		for (int i = 0; i < _dsSach.size(); i++)
		{
			if (tacgia == _dsSach[i]->getTacGia())
			{
				ds.push_back(_dsSach[i]);
			}
		}
		break;
	default:
		cout << "\nNhap lai lua chon\n";
		goto tim;
	}
	return ds;
}
void ThuVien::XoaSach()
{
	int h;
	bool flag = 0;
	string masach, tensach;
xoa:
	system("cls");
	cout << "\n1. Xoa sach theo Ma Sach";
	cout << "\n2. Xoa sach theo Ten Sach";
	cout << "\n:Su lua chon:";
	cin >> h;
	switch (h)
	{
	case 1:
		cout << "\nNhap Ma Sach:";
		cin.ignore();
		getline(cin, masach);
		for (int i = 0; i < _dsSach.size(); i++)
		{
			if (masach == _dsSach[i]->getMaSach())
			{
				_dsSach.erase(_dsSach.begin() + i);
				flag = 1;
				break;
			}
		}
		break;
	case 2:
		cout << "\nNhap Ten Sach:";
		cin.ignore();
		getline(cin, tensach);
		for (int i = 0; i < _dsSach.size(); i++)
		{
			if (tensach == _dsSach[i]->getTenSach())
			{
				_dsSach.erase(_dsSach.begin() + i);
				flag = 1;
			}
		}
		break;
	
	default:
		cout << "\nNhap lai lua chon\n";
		goto xoa;
	}
	if (flag == 1)
		cout << "\nXoa sach thanh cong!!";
	else
		cout << "\nKhong tim thay quyen sach nay!!!";
}
void ThuVien::SuaSach()
{
	int h;
	bool flag = 0;
	string masach,ma,ten,tg,nxb,isbn;
	unsigned giasach;
	cout << "\nNhap Ma Sach:";
	cin.ignore();
	getline(cin, masach);
	for (int i = 0; i < _dsSach.size(); i++)
	{
		if (masach == _dsSach[i]->getMaSach())
		{
			while (1)
			{
				if (_dsSach[i]->getType() == "NV")
				{
					sua:
					system("cls");
					cout << "\n0.Ngung sua.";
					cout << "\n1.Sua Ma sach.";
					cout << "\n2.Sua Ten sach.";
					cout << "\n3.Sua Ten Tac Gia.";
					cout << "\n4.Sua NXB.";
					cout << "\n5.Sua Gia Sach.";
					cout << "\n6.Sua ISBN.";
					cout << "\nSu lua chon:";
					cin >> h;
					if (h == 6)
					{
						cout << "\nNhap ISBN: ";
						cin.ignore();
						getline(cin, isbn);
						Sach*p;
						((SachNgoaiVan*)_dsSach[i])->setISBN(isbn);
						goto sua;
					}
				

				}
				else
				{
					system("cls");
					cout << "\n0.Ngung sua.";
					cout << "\n1.Sua Ma sach.";
					cout << "\n2.Sua Ten sach.";
					cout << "\n3.Sua Ten Tac Gia.";
					cout << "\n4.Sua NXB.";
					cout << "\n5.Sua Gia Sach.";
					cin >> h;
				}
				if (h == 0)
					break;
				switch (h)
				{
				case 1:
					cout << "\nNhap ma sach: ";
					cin.ignore();
					getline(cin,ma);
					_dsSach[i]->setMaSach(ma);
					break;
				case 2:
					cout << "\nNhap ten sach: ";
					cin.ignore();
					getline(cin, ten);
					_dsSach[i]->setTenSach(ten);
					break;
				case 3:
					cout << "\nNhap tac gia: ";
					cin.ignore();
					getline(cin, tg);
					_dsSach[i]->setTacGia(ma);
					break;
				case 4:
					cout << "\nNhap NXB: ";
					cin.ignore();
					getline(cin, nxb);
					_dsSach[i]->setNXB(nxb);
					break;
				case 5:
					cout << "\nNhap gia sach: ";
					cin.ignore();
					cin >> giasach;
					_dsSach[i]->setGiaSach(giasach);
					break;
				default:
					cout << "\nSai lua chon:";
					system("pause");
					break;
				}
			}
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		cout << "\nSua sach thanh cong!!";
	else
		cout << "\nKhong tim thay quyen sach nay!!!";
}
void ThuVien::lietkeSach()
{
	for (int i = 0; i < _dsSach.size(); i++)
	{
		cout << "\n-----------------------------------------------";
		cout << "\n\nSach thu " << i + 1 <<"::::::";
		_dsSach[i]->xuat();
		cout << "\n------------------------------------------------";
	}
}

void ThuVien::ThemDocgia()
{
	int n, h;
	cout << "\nNhap so luong Doc gia can them:";
	cin >> n;
	cin.ignore();
	DocGia p;
	for (int i = 0; i < n; i++)
	{
		p.nhap();
		_dsDG.push_back(p);
	}
}
void ThuVien::SuaDocgia()
{
	int h,choose;
	bool flag = 0;
	string ma, ten;
	string maDG, tenDG,diachiDG;
suaDG:
	system("cls");
	cout << "\n1. Nhap Ma Doc Gia";
	cout << "\n2. Nhap ten Doc gia";
	cout << "\n:Su lua chon:";
	cin >> h;
	switch (h)
	{
	case 1:
		cout << "\n1. Nhap Ma Doc Gia: ";
		cin.ignore();
		getline(cin, ma);
		for (int i = 0; i < _dsDG.size(); i++)
		{
			if (ma == _dsDG[i].getMaDocgia())
			{
				while (1)
				{
					
						system("cls");
						cout << "\n0.Ngung sua.";
						cout << "\n1.Sua Ma Doc gia.";
						cout << "\n2.Sua Ten Doc gia.";
						cout << "\n3.Sua Dia chi Doc gia.";
						cout << "\nSu lua chon:";
						cin >> choose;
						if (choose == 0)
							break;
						switch (choose)
						{
						case 1:
							cout << "\nNhap ma Doc gia: ";
							cin.ignore();
							getline(cin, maDG);
							_dsDG[i].setMaDocGia(maDG);
							flag = 1;
							break;
						case 2:
							cout << "\nNhap ten Doc gia: ";
							cin.ignore();
							getline(cin, tenDG);
							_dsDG[i].setTen(tenDG);
							flag = 1;
							break;
						case 3:
							cout << "\nNhap Dia chi Doc gia: ";
							cin.ignore();
							getline(cin, diachiDG);
							_dsDG[i].setDiachi(diachiDG);
							flag = 1;
							break;
						
						default:
							cout << "\nSai lua chon: ";
							system("pause");
							break;
						}
				}
				break;
			}
		}
		break;
	case 2:
		cout << "\n2. Nhap ten Doc gia: ";
		cin.ignore();
		getline(cin, ten);
		for (int i = 0; i < _dsDG.size(); i++)
		{
			if (ten == _dsDG[i].getTen())
			{
				
				while (1)
				{
					system("cls");
					cout << "\n0.Ngung sua.";
					cout << "\n1.Sua Ma Doc gia.";
					cout << "\n2.Sua Ten Doc gia.";
					cout << "\n3.Sua Dia chi Doc gia.";
					cout << "\nSu lua chon:";
					cin >> choose;
					if (choose == 0)
						break;
					switch (choose)
					{
					case 1:
						cout << "\nNhap ma Doc gia: ";
						cin.ignore();
						getline(cin, maDG);
						_dsDG[i].setMaDocGia(maDG);
						flag = 1;
						break;
					case 2:
						cout << "\nNhap ten Doc gia: ";
						cin.ignore();
						getline(cin, tenDG);
						_dsDG[i].setTen(tenDG);
						flag = 1;
						break;
					case 3:
						cout << "\nNhap Dia chi Doc gia: ";
						cin.ignore();
						getline(cin, diachiDG);
						_dsDG[i].setDiachi(diachiDG);
						flag = 1;
						break;

					default:
						cout << "\nSai lua chon:";
						system("pause");
						break;
					}


				}
			}
		}
		break;

	default:
		cout << "\nNhap lai lua chon\n";
		system("pause");
		goto suaDG;
	}
	if (flag == 1)
		cout << "\nSua Doc gia thanh cong!!";
	else
		cout << "\nKhong tim thay doc gia nay!!!";
}
void ThuVien::XoaDocgia()
{
	int h;
	bool flag = 0;
	string ma, ten;
xoaDG:
	system("cls");
	cout << "\n1. Nhap Ma Doc Gia";
	cout << "\n2. Nhap ten Doc gia";
	cout << "\n:Su lua chon:";
	cin >> h;
	switch (h)
	{
	case 1:
		cout << "\n1. Nhap Ma Doc Gia: ";
		cin.ignore();
		getline(cin, ma);
		for (int i = 0; i < _dsDG.size(); i++)
		{
			if (ma == _dsDG[i].getMaDocgia())
			{
				_dsDG.erase(_dsDG.begin() + i);
				flag = 1;
				break;
			}
		}
		break;
	case 2:
		cout << "\n2. Nhap ten Doc gia: ";
		cin.ignore();
		getline(cin, ten);
		for (int i = 0; i < _dsDG.size(); i++)
		{
			if (ten == _dsDG[i].getTen())
			{
				_dsDG.erase(_dsDG.begin() + i);
				flag = 1;
			}
		}
		break;

	default:
		cout << "\nNhap lai lua chon\n";
		system("pause");
		goto xoaDG;
	}
	if (flag == 1)
		cout << "\nXoa Doc gia thanh cong!!";
	else
		cout << "\nKhong tim thay doc gia nay!!!";
}
vector<DocGia> ThuVien::TimDocgia()
{
	vector<DocGia> ds;
	int h;
	Sach* p;
	string ma, ten;
timDG:
	system("cls");
	cout << "\n1. Tim Doc gia theo Ma";
	cout << "\n2. Tim Doc gia theo Ten";
	cout << "\n:Su lua chon:";
	cin >> h;
	switch (h)
	{
	case 1:
		cout << "\nNhap Ma Doc gia:";
		cin.ignore();
		getline(cin, ma);
		for (int i = 0; i < _dsDG.size(); i++)
		{
			if (ma == _dsDG[i].getMaDocgia())
			{
				ds.push_back(_dsDG[i]);
				break;
			}
		}
		break;
	case 2:
		cout << "\nNhap Ten Doc gia:";
		cin.ignore();
		getline(cin, ten);
		for (int i = 0; i < _dsDG.size(); i++)
		{
			if (ten == _dsDG[i].getTen())
			{
				ds.push_back(_dsDG[i]);
			}
		}
		break;
	default:
		cout << "\nNhap lai lua chon\n";
		system("pause");
		goto timDG;
	}
	return ds;
}
void ThuVien::lietkeDocgia()
{
	for (int i = 0; i < _dsDG.size(); i++)
	{
		cout << "\n------------------------------------------------";
		cout << "\n\nDoc Gia thu " << i + 1 << "::::::" ;
		_dsDG[i].xuat();
		cout << "\n------------------------------------------------";
	}
}

void ThuVien::lapPhieuMuonSach()
{
	Phieu* p;
	bool flag = 0;
	DocGia dg;
	int choose;
	while (1)
	{
		system("cls");
		cout << "\n0. Dung.";
		cout << "\n1. Lap Phieu cho Doc gia cu!";
		cout << "\n2. Lap Phieu cho Doc gia moi!";
		cout << "\nSu lua chon:";
		cin >> choose;
		if (choose == 0)
			break;
		switch (choose)
		{
		case 1:
			system("cls");
			cout << "\n---------1. Lap Phieu cho Doc gia cu!-----------";
			p = new PhieuMuonSach;
			cin.ignore();
			p->nhap();
			for (int i = 0; i < _dsDG.size(); i++)
			{
				if (p->getMaDG() == _dsDG[i].getMaDocgia())
				{
					flag = 1;
					_dsDG[i].setPhieu(p);
					_dsDG[i].setStatus(1);
				}
			}

			break;
		case 2:
			system("cls");
			cout << "\n-------------2. Lap Phieu cho Doc gia moi!-------";
			cout << "\nThem thong tin doc gia:";
			cin.ignore();
			dg.nhap();
			_dsDG.push_back(dg);
			p = new PhieuMuonSach;
			p->nhap();	

			flag = 1;
			_dsDG[_dsDG.size()-1].setPhieu(p);
			_dsDG[_dsDG.size() - 1].setStatus(1);
			break;
		default:
			cout << "\nSai lua chon!!";
			system("pause");
			break;
		}
		if (flag == 0)
			cout << "\nKhong lap duoc phieu\n";
		else
			cout << "\nLap phieu muon thanh cong\n";
		system("pause");
	}
	
}
void ThuVien::lapPhieuTraSach()
{
	int choose;
	Phieu* p,*phMuon;
	unsigned phat = 0;
	string madg;
	bool flag = 0;

	
		cout << "\n1.Nhap ma doc gia: ";
		cin.ignore();
		getline(cin, madg);
		for (int i = 0; i < _dsDG.size(); i++)
		{
			if (madg == _dsDG[i].getMaDocgia())
			{
				phMuon=_dsDG[i].getPhieu();
				p = new PhieuTraSach;
				((PhieuTraSach*)p)->nhap(phMuon);
				phat=((PhieuTraSach*)p)->calFine();
				_dsDG[i].setPhieu(p);
				_dsDG[i].setStatus(0);
				if (phat == 0)
					cout << "\nTra sach thanh cong!!";
				else
					cout << "\n\nTien phat cua ban la:  " << phat << endl;
				flag = 1;
				system("pause");
			}
		}
		if (flag == 0)
		{
			cout << "\nKhong tim thay Doc gia. Vui long nhap lai!! ";
			system("pause");
		}
}

void ThuVien::LKDocGiaMuonQuaHan()
{
	cout << "\nNhap ngay hien tai: ";
	Date today,_daymuon;
	Phieu* phMuon;
	unsigned fine = 0;
	vector<DocGia> dsDGQH;
	cin >> today;
	int count = 1;
	for (int i = 0; i < _dsDG.size(); i++)
	{
		if (_dsDG[i].getStatus() == 1)
		{
			phMuon = _dsDG[i].getPhieu();
			_daymuon=phMuon->getNgayMuon();
			int songay = today - _daymuon;
			if (songay>7)
			{
				songay -= 7;
				fine = 0;
				dsDGQH.push_back(_dsDG[i]);
				fine = songay *10000*phMuon->getSoLuongSTV()+ songay * 20000 * (phMuon->getSoLuong() - phMuon->getSoLuongSTV());
				cout << "\n\nDoc Gia thu " << count << " : ";
				cout << "\nMa doc gia: " << _dsDG[i].getMaDocgia() << "\nTen Doc gia: " << _dsDG[i].getTen();
				cout << "\nDia chi: " << _dsDG[i].getDC();
				cout << "\nTien phat: " << fine<<"\n";
				count++;
			}
		}
	}
	if (dsDGQH.size() == 0)
		cout << "\n\nKhong co doc gia muon qua han!";
	system("pause");
}

void ThuVien::luuSach()
{
	ofstream output;
	output.open("Sach.txt", ios::out);
	if (output.fail())
	{
		cout << "\nLuu Sach That bai!!";
		system("pause");
	}
	else
	{
		output << _dsSach.size()<<endl;
		for (int i = 0; i < _dsSach.size(); i++)
		{
			if (_dsSach[i]->getType() == "NV")
				output << "NV" << endl;
			else
				output << "TV" << endl;
			output << *_dsSach[i];
			if (_dsSach[i]->getType() == "NV")
				output << ((SachNgoaiVan*)_dsSach[i])->getISBN() << endl;
		}
		system("pause");
	}
	output.close();
	ofstream out;
	out.open("ThongTinSach.txt", ios::out);
	if (out.fail())
	{
		cout << "\nLuu Sach That bai!!";
		system("pause");
	}
	else
	{
		out << "--------------------------------------SACH--------------------------------------------------\n";
		out <<"So luong sach: "<< _dsSach.size() << endl;
		for (int i = 0; i < _dsSach.size(); i++)
		{
			out << "------------------------------------------------------------------------------\n";
			if (_dsSach[i]->getType() == "NV")
				out << i+1<<". Sach Ngoai Van" << endl;
			else
				out << i + 1 << ". Sach Tieng Viet" << endl;
			out << "Ma sach: " << _dsSach[i]->getMaSach() << endl;
			out << "Ten sach: " << _dsSach[i]->getTenSach() << endl;
			out << "Tac gia: " << _dsSach[i]->getTacGia() << endl;
			out << "NXB: " << _dsSach[i]->getNXB() << endl;
			out << "Gia sach: " << _dsSach[i]->getGiaSach() << endl;
			if (_dsSach[i]->getType() == "NV")
				out << "ISBN: "<<((SachNgoaiVan*)_dsSach[i])->getISBN() << endl;
			out << "------------------------------------------------------------------------------\n";
		}
		system("pause");
	}
	out.close();
}
void ThuVien::luuDocGia()
{
	ofstream output;
	output.open("Docgia.txt", ios::out);
	if (output.fail())
	{
		cout << "\nLuu Doc Gia That bai!!";
		system("pause");
	}
	else
	{
		
		output << _dsDG.size() << endl;
		for (int i = 0; i < _dsDG.size(); i++)
		{
			output << _dsDG[i];
		}
	}
	output.close();
	ofstream out;
	out.open("ThongTinDocgia.txt", ios::out);
	if (out.fail())
	{
		cout << "\nLuu Doc Gia That bai!!";
		system("pause");
	}
	else
	{
		out << "--------------------------------------DOC GIA--------------------------------------------------------------\n";
		out <<"So luong doc gia: "<< _dsDG.size() << endl;
		for (int i = 0; i < _dsDG.size(); i++)
		{
			out << "----------------------------------------------------------------------------------\n";
			out <<"Ma doc gia: "<< _dsDG[i].getMaDocgia()<<endl;
			out << "Ten doc gia: " << _dsDG[i].getTen() << endl;
			out << "Dia Chi doc gia: " << _dsDG[i].getDC() << endl;
			if(_dsDG[i].getStatus()==1)
				out << "Doc gia dang muon sach." << endl;
			else
				out << "Doc gia khong dang muon sach." << endl;
			out << "So phieu: " << _dsDG[i].getdsPhieu().size()<<endl;
			vector<Phieu*> ds = _dsDG[i].getdsPhieu();
			for (int j = 0; j < ds.size(); j++)
			{
				out << "------------------------------------\n";
				if (ds[j]->getType() == "MS")
				{
					out <<j+1<< ". Phieu Muon sach\n";
				}
				else
				{
					out << j + 1 << ". Phieu Tra sach\n";
				}
				out<<"Ma doc gia: "<<ds[j]->getMaDG() << endl;
				out<< "Ten doc gia: " << ds[j]->getTenDG()<<endl;
				out << "So luong Sach muon: " << ds[j]->getSoLuong() << endl;
				out << "So luong Sach TV muon: " << ds[j]->getSoLuongSTV() << endl;
				
				unsigned m = 0;
				for (auto&ch: ds[j]->getSach())
				{
					out << m + 1 << ".----------------------\n";
					out << "Ma sach: " << ch.first<<endl;
					out << "Ten sach: " << ch.second<<endl;
					m++;
				}
				out << "Ngay muon: " << ds[j]->getNgayMuon() << endl;
				if (ds[j]->getType() == "TS")
				{
					out<< "Ngay tra: " << ((PhieuTraSach*)ds[j])->getNgaytra() << endl;
					out << "Tien phat: " << ((PhieuTraSach*)ds[j])->getFine() << endl;
				}
				out << "------------------------------------\n";
			}
			out << "----------------------------------------------------------------------------------\n";
		}
	}
	out.close();
}

void ThuVien::layThongTinSach()
{
	ifstream in;
	in.open("Sach.txt", ios::in);
	if (in.fail())
	{
		cout << "\nKhong ton ta file sach.";
		system("pause");
		return;
	}
		
	int n;
	string loai,ma,ten,tg,nxb,isbn,rac;
	unsigned gia;
	in >> n;
	getline(in, rac);
	Sach*p;
	for (int i = 0; i < n; i++)
	{
		in >> loai;
		//
		getline(in, rac);
		if (loai == "TV")
			p = new SachTV;
		else
			p = new SachNgoaiVan;
		getline(in, ma);
		getline(in, ten);
		getline(in, tg);
		getline(in, nxb);
		in >> gia;
		//
		getline(in, rac);
		p->setMaSach(ma);
		p->setTenSach(ten);
		p->setTacGia(tg);
		p->setNXB(nxb);
		p->setGiaSach(gia);
		if (loai == "NV")
		{
			getline(in, isbn);
			((SachNgoaiVan*)p)->setISBN(isbn);
		}
		_dsSach.push_back(p);
	}
	in.close();
}
void ThuVien::layThongTinDocGia()
{
	ifstream in;
	in.open("Docgia.txt", ios::in);
	if (in.fail())
	{
		cout << "\nKhong ton ta file Doc gia.";
		system("pause");
		return;
	}
	
	unsigned fine;
	int n,soPh,SoSach,SoSachTV;
	string loaiPh, ma, ten, dc, maSach,tenSach,rac;
	Date muon, tra;
	Phieu* ph;
	bool status;
	unsigned gia;
	in >> n;
	//
	getline(in, rac);
	for (int i = 0; i < n; i++)
	{
		DocGia dg;
		getline(in, ma);
		getline(in, ten);
		getline(in, dc);
		in >> status;
		//
		getline(in, rac);
		dg.setMaDocGia(ma);
		dg.setTen(ten);
		dg.setDiachi(dc);
		dg.setStatus(status);
		in >> soPh;
		//
		getline(in, rac);
		for (int j = 0; j < soPh; j++)
		{
			in >> loaiPh;
			//
			getline(in, rac);
			if (loaiPh == "MS")
				ph = new PhieuMuonSach;
			else
				ph = new PhieuTraSach;
			getline(in, ma);
			getline(in, ten);
			ph->setDocGia(ten, ma);
			in >> SoSach;
			//
			getline(in, rac);
			in >> SoSachTV;
			//
			getline(in, rac);
			ph->setSl(SoSach, SoSachTV);
			for (int h = 0; h < SoSach; h++)
			{
				getline(in, maSach);
				getline(in, tenSach);
				ph->setSach(maSach, tenSach);
			}
			in >> muon; getline(in, rac);

			
			ph->setNgayMuon(muon);
			
			if (loaiPh == "TS")
			{
				in >> tra;getline(in, rac);
				in >> fine; getline(in, rac);
				((PhieuTraSach*)ph)->setNgaytra(tra);
				((PhieuTraSach*)ph)->setFine(fine);
				
			}
		
			dg.setPhieu(ph);
		}
		_dsDG.push_back(dg);
	}
	system("pause");
	in.close();
}