#include <iostream>
#include <vector>
#include <fstream>
#include "benh_nhan/benhnhan.h"
#include "bac_si/bacsi.h"
#include "ho_so/hososuckhoe.h"
#include "hoa_don/hoadon.h"
using namespace std;
int main() {
    vector<BenhNhan> dsBN;
    vector<BacSi> dsBS;
    vector<HoSoSucKhoe> dsHS;
    vector<HoaDon> dsHD;
    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them benh nhan\n";
        cout << "2. Them bac si\n";
        cout << "3. Tao ho so suc khoe\n";
        cout << "4. Tao hoa don\n";
        cout << "5. Xuat du lieu ra file\n";
        cout << "6. Doc du lieu tu file\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            BenhNhan bn;
            cin >> bn;
            dsBN.push_back(bn);
            break;
        }
        case 2: {
            BacSi bs;
            cin >> bs;
            dsBS.push_back(bs);
            break;
        }
        case 3: {
            HoSoSucKhoe hs;
            hs.nhap();
            dsHS.push_back(hs);
            break;
        }
        case 4: {
            HoaDon hd;
            hd.nhap();
            dsHD.push_back(hd);
            break;
        }
        case 5: {
            ofstream fout("output.txt");
            fout << "===== BENH NHAN =====\n";
            for (auto &bn : dsBN) {
                fout << bn << endl;
            }
            fout << "\n===== BAC SI =====\n";
            for (auto &bs : dsBS) {
                fout << bs << endl;
            }
            fout << "\n===== HO SO =====\n";
            for (auto &hs : dsHS) {
                fout << hs << endl;
            }
            fout << "\n===== HOA DON =====\n";
            for (auto &hd : dsHD) {
                fout << hd << endl;
            }
            fout.close();
            cout << "Da ghi ra file output.txt\n";
            break;
        }
        case 6: {
            ifstream fin("output.txt");
            string line;
            cout << "\n===== NOI DUNG FILE =====\n";
            while (getline(fin, line)) {
                cout << line << endl;
            }
            fin.close();
            break;
        }
        case 0:
            cout << "Thoat chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);
    return 0;
}