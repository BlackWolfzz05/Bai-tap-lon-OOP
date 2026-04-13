#ifndef PHONGBENH_H
#define PHONGBENH_H
#include <iostream>
#include <string>
using namespace std;

class PhongBenh {
private:
    string maPhong;
    string tenPhong;
    string loaiPhong; // "Thuong", "VIP"
    int soGiuong;
    int soGiuongDaNhan;

public:
    PhongBenh();
    PhongBenh(string maPhong, string tenPhong, string loaiPhong, int soGiuong);
    ~PhongBenh();

    string getMaPhong();
    string getTenPhong();
    string getLoaiPhong();
    int getSoGiuong();
    int getSoGiuongThongTrong();

    bool nhanGiuong(int &soGiuongDcCap);
    void traGiuong();

    void nhap();
    void xuat();
};

#endif
