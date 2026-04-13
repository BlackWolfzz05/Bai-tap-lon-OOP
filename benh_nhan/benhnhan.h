#ifndef BENHNHAN_H
#define BENHNHAN_H
#include <iostream>
#include <string>
#include "../hoa_don/hoadon.h"
using namespace std;

const int MAX_HS = 50;

// ================================================================
// CLASS BenhNhan - Chua cac thuoc tinh KCB rui trưc tiêp
// ================================================================
class BenhNhan {
private:
    string ten;
    int    maBN;
    int    tuoi;
    string diaChi;
    static int dem; // tu tang ma benh nhan

    // ------------------------------------
    // THUOC TINH HO SO KCB (Truc tiep)
    // ------------------------------------
    string tenBenh;        // Ten benh moi them
    string loaiBenhAn;     // "Noi tru", "Ngoai tru", hoac rong (chua lap)
    string chanDoan;       // Noi tru: Ly do nhap vien | Ngoai tru: Ten benh / Chan doan
    int    maBacSiKCB;     // Ma BS tiep thuc
    string ngayVaoVien;    // Chung cho Ngoai tru (ngay kham) va Noi tru
    string ngayRaVien;     // Chi danh cho Noi tru
    int    soNgayDieuTri;  // Chi danh cho Noi tru
    
    // Thong tin luu tru co so vat chat
    string maPhongLuuTru;
    int soGiuongLuuTru;
    
    // ------------------------------------
    HoaDon* dsHoaDon[MAX_HS];
    int slHoaDon;

public:
    BenhNhan();
    BenhNhan(string ten, int tuoi, string diaChi);
    ~BenhNhan();

    // Getter
    string getTen();
    int    getMaBN();
    int    getTuoi();
    string getDiaChi();

    // Setter
    void setTen(string t);
    void setDiaChi(string dc);
    void setTuoi(int t);

    void setPhongLuuTru(string maP, int soG);
    string getMaPhongLuuTru();

    // Ham nhap xuat thong tin ca nhan co ban
    void nhap();
    void xuat();
    
    // NGHIEP VU KCB TREN CHINH BENH NHAN (Linear Flow)
    int quyTrinhKhamBenh(); 
    void thuTucXuatVien(string loaiPhongLuuTru); 
    void themHoaDon(double donGiaGiuong = 0, string loaiPhong = "");
    void xemDanhSachHoaDon();

    double tinhTongVienPhi() const;

    // Nap chong
    friend istream& operator>>(istream& in, BenhNhan& bn);
    friend ostream& operator<<(ostream& out, const BenhNhan& bn);
};

#endif