#ifndef HOADON_H
#define HOADON_H
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_THUOC = 50;

// ================================================================
// CLASS Thuoc
// ================================================================
class Thuoc {
private:
    string tenThuoc;
    int    soLuong;
    double gia;

public:
    Thuoc();
    Thuoc(string tenThuoc, int soLuong, double gia);
    ~Thuoc();

    // Getter
    string getTenThuoc() const;
    int    getSoLuong()  const;
    double getGia()      const;

    // Setter voi validation
    void setTenThuoc(string t);
    void setSoLuong(int sl);
    void setGia(double g);

    void nhap();
    void xuat() const;
};

// ================================================================
// CLASS HoaDon - Chua danh sach thuoc, lien ket voi BenhNhan
// ================================================================
class HoaDon {
private:
    int    maBN;
    Thuoc  dsThuoc[MAX_THUOC];
    int    soLuongThuoc;
    double tongTien;

public:
    HoaDon();
    HoaDon(int maBN);
    ~HoaDon();

    // Getter
    int    getMaBN();
    double getTongTien();

    void themThuoc(Thuoc t);
    void tinhTongTien();
    void nhap();
    void xuat() const;

    friend ostream& operator<<(ostream& out, const HoaDon& hd);
};

#endif