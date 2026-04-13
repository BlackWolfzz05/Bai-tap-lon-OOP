#include "danhmuc.h"

DanhMuc::DanhMuc() : soLuongThuoc(0), soLuongDichVu(0) {}
DanhMuc::~DanhMuc() {}

void DanhMuc::themThuoc() {
    if (soLuongThuoc < MAX_THUOC) {
        dsThuoc[soLuongThuoc].nhap();
        soLuongThuoc++;
    } else {
        cout << "Danh sach da day!\n";
    }
}

void DanhMuc::themDichVu() {
    if (soLuongDichVu < MAX_THUOC) {
        dsDichVu[soLuongDichVu].nhap();
        soLuongDichVu++;
    } else {
        cout << "Danh sach da day!\n";
    }
}

void DanhMuc::xemDanhSach() {
    cout << "\n--- DANH MUC THUOC ---\n";
    for(int i = 0; i < soLuongThuoc; i++) dsThuoc[i].xuat();
    cout << "\n--- DANH MUC DICH VU ---\n";
    for(int i = 0; i < soLuongDichVu; i++) dsDichVu[i].xuat();
}
