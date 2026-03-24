#ifndef BENHNHAN_H
#define BENHNHAN_H

#include <iostream>
#include <string>
using namespace std;

class BenhNhan {
private:
    string ten;
    int maBN;
    int tuoi;
    string diaChi;
    static int dem; // dùng để tự tăng mã bệnh nhân

public:
    // Constructor mặc định
    BenhNhan();

    // Constructor có tham số
    BenhNhan(string ten, int tuoi, string diaChi);

    // Destructor
    ~BenhNhan();

    // Getter
    string getTen();
    int getMaBN();
    int getTuoi();
    string getDiaChi();

    // Setter
    void setTen(string ten);
    void setTuoi(int tuoi);     // điều kiện > 0
    void setDiaChi(string diaChi);

    // Hàm nhập / xuất
    void nhap();
    void xuat();

    // Nạp chồng toán tử nhập xuất
    friend istream& operator>>(istream& in, BenhNhan& bn);
    friend ostream& operator<<(ostream& out, const BenhNhan& bn);
};

#endif