#ifndef HOADON_H
#define HOADON_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ================== CLASS THUOC ==================
class Thuoc {
private:
    string tenThuoc;
    int soLuong;
    double gia;
public:
    // Constructor & Destructor
    Thuoc();
    Thuoc(string tenThuoc, int soLuong, double gia);
    ~Thuoc();
    // Getter
   string getTenThuoc() const;
    int getSoLuong() const;
    double getGia() const;
    // Setter
    void setTenThuoc(string tenThuoc);
    void setSoLuong(int soLuong);
    void setGia(double gia); // gia > 0
    // Nhập / Xuất
    void nhap();
    void xuat();
};
// ================== CLASS HOA DON ==================
class HoaDon {
private:
    vector<Thuoc> dsThuoc;
    double tongTien;
public:
    // Constructor & Destructor
    HoaDon();
    ~HoaDon();
    // Chức năng
    void themThuoc(Thuoc t);
    void tinhTongTien();
    // Nhập / Xuất
    void nhap();
    void xuat();
    // Getter
    double getTongTien();
    // Nạp chồng toán tử
    friend ostream& operator<<(ostream& out, const HoaDon& hd);
};
#endif