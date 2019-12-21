#include"SachNgoaiVan.h"
#include"SachTV.h"
#include"ThuVien.h"
#include<vector>
int main()
{
	ThuVien TV;
	while(1)
	{
		int h,choose;
		system("cls");
		cout << "----------------------QUAN LY THU VIEN---------------------\n";
		cout << "\n0.Dung chuong trinh";
		cout << "\n1.Sach";
		cout << "\n2.Doc Gia";
		cout << "\n3.Lap phieu muon/tra sach";
		cout << "\n4.Liet ke danh sach doc gia dang muon sach qua han";
		cout << "\n5.Luu sach va Doc gia";
		cout << "\n6.Lay thong tin Sach va Doc gia tu Tap Tin";
		cout << "\nSu lua chon: ";
		cin >> h;
		if (h == 0)
			break;
		switch (h)
		{
		case 1:
			while (1)
			{
				system("cls");
				cout << "\n-----------1.Sach---------------\n";
				cout << "\n0.Tro ve menu";
				cout << "\n1.Them Sach";
				cout << "\n2.Tim Sach";
				cout << "\n3.Sua Sach";
				cout << "\n4.Xoa Sach";
				cout << "\n5.Liet ke sach hien co";
				cout << "\nSu lua chon: ";
				cin >> choose;
				vector<Sach*> dsTim;
				if (choose == 0)
					break;
				switch (choose)
				{
				case 1:
					system("cls");
					cout << "\n--------1.Them Sach-------------";
					TV.ThemSach();
					break;
				case 2:
					system("cls");
					cout << "\n--------2Tim Sach---------------";
					
					dsTim=TV.TimSach();
					if (dsTim.size() == 0)
					{
						cout << "\ntrong thu vien khong co sach tren!!";
					}
					else
					{
						cout << "\nThong tin sach can tim :";
						for (int i = 0; i < dsTim.size(); i++)
						{
							cout << "\n\nSach thu " << i + 1 << "::::::" ;
							dsTim[i]->xuat();
						}
					}
					cout << endl;
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "\n----------3.Sua Sach-------------";
					TV.SuaSach();
					cout << endl;
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "\n-----4.Xoa Sach------------";
					TV.XoaSach();
					cout << endl;
					system("pause");
					break;
				case 5:
					system("cls");
					cout << "\n---------5.Liet ke sach hien co-------------------";
					TV.lietkeSach();
					cout << endl;
					system("pause");
					break;
				default:
					cout << "\nChon lai!!!";
					system("pause");
					break;
				}
			}
			
			break;
		case 2:
			while (1)
			{
				system("cls");
				cout << "\n-------2.Doc Gia------------------------\n";
				cout << "\n0.Tro ve menu";
				cout << "\n1.Them Doc gia";
				cout << "\n2.Tim Doc gia";
				cout << "\n3.Sua Doc gia";
				cout << "\n4.Xoa Doc gia";
				cout << "\n5.Liet ke Danh sach Doc gia";
				cout << "\nSu lua chon:";
				cin >> choose;
				vector<DocGia> dsTimDG;
				if (choose == 0)
					break;
				switch (choose)
				{
				case 1:
					system("cls");
					cout << "\n---------1.Them Doc gia------------\n";
					TV.ThemDocgia();
					break;
				case 2:
					system("cls");
					cout << "\n----------2.Tim Doc gia------------\n";

					dsTimDG = TV.TimDocgia();
					if (dsTimDG.size() == 0)
					{
						cout << "\nTrong thu vien khong co doc gia tren!!";
					}
					else
					{
						cout << "\nThong tin Doc gia can tim :";
						for (int i = 0; i < dsTimDG.size(); i++)
						{
							cout << "\n\nDoc gia thu " << i + 1 << "::::::";
							dsTimDG[i].xuat();
						}
					}
					cout << endl;
					system("pause");
					break;
				case 3:
					system("cls");
					cout << "\n--------------3.Sua Doc gia-----------\n";
					TV.SuaDocgia();
					cout << endl;
					system("pause");
					break;
				case 4:
					system("cls");
					cout << "\n-----------4.Xoa Doc gia--------\n";
					TV.XoaDocgia();
					cout << endl;
					system("pause");
					break;
				case 5:
					system("cls");
					cout << "\n----5.Liet ke danh sach Doc gia:------------\n";
					TV.lietkeDocgia();
					cout << endl;
					system("pause");
					break;
				default:
					cout << "\nChon lai!!!"; system("pause");
					break;
				}
			}
			break;
		case 3:
			while (1)
			{
				system("cls");
				cout << "\n-------------3.Lap phieu muon/tra sach--------\n";
				cout << "\n0.Dung lap phieu";
				cout << "\n1.Lap Phieu muon sach";
				cout << "\n2.Lap Phieu tra sach";
				cout << "\nSu lua chon: ";
				cin >> choose;
				if (choose == 0)
					break;
				switch (choose)
				{
				case 1:
					system("cls");
					cout << "\n--------1.Lap Phieu muon sach----------\n";
					TV.lapPhieuMuonSach();
					break;
				case 2:
					system("cls");
					cout << "\n-----------2.Lap Phieu tra sach-----------\n";
					TV.lapPhieuTraSach();
					break;
				default:
					cout << "\nChon lai!!!";
					system("pause");
					break;
				}
			}
			break;
		case 4:
			system("cls");
			cout << "\n---------4.Liet ke danh sach doc gia dang muon sach qua han---------\n";
			TV.LKDocGiaMuonQuaHan();
			break;
		case 5:
			TV.luuSach();
			TV.luuDocGia();
			break;
		case 6:
			TV.layThongTinSach();
			TV.layThongTinDocGia();
			break;
		default:
			cout << "\nChon lai!!!";
			system("pause");
			break;
		}
	}
	
	system("pause");
	return 0;
}