#ifndef DANHMUC_H
#define DANHMUC_H
#include <iostream>
#include <string>
#include "../hoa_don/hoadon.h" // de use class Thuoc
using namespace std;

class DichVu {
private:
    string tenDichVu;
    double giaDichVu;
public:
    DichVu() : tenDichVu(""), giaDichVu(0) {}
    DichVu(string ten, double gia) : tenDichVu(ten), giaDichVu(gia) {}
    
    string getTen() { return tenDichVu; }
    double getGia() { return giaDichVu; }
    
    void nhap() {
        cout << "Nhap ten dich vu: ";
        getline(cin >> ws, tenDichVu);
        cout << "Nhap gia dich vu: ";
        cin >> giaDichVu;
    }
    void xuat() {
        cout << "Dich vu: " << tenDichVu << " - Gia: " << giaDichVu << "\n";
    }
};

class DanhMuc {
private:
    Thuoc dsThuoc[MAX_THUOC];
    int soLuongThuoc;

    DichVu dsDichVu[MAX_THUOC];
    int soLuongDichVu;

public:
    DanhMuc();
    ~DanhMuc();

    void themThuoc();
    void themDichVu();
    void xemDanhSach();
};

#endif
