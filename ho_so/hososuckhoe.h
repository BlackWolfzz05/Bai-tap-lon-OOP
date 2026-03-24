#ifndef HOSOSUCKHOE_H
#define HOSOSUCKHOE_H

#include <iostream>
#include <string>
#include "../benh_nhan/benhnhan.h"
#include "../bac_si/bacsi.h"

using namespace std;

class HoSoSucKhoe {
private:
    BenhNhan bn;      // composition
    BacSi bs;         // composition
    string ngayKham;
    string chanDoan;

public:
    // Constructor mặc định
    HoSoSucKhoe();

    // Constructor có tham số
    HoSoSucKhoe(BenhNhan bn, BacSi bs, string ngayKham, string chanDoan);

    // Destructor
    ~HoSoSucKhoe();

    // Getter
    BenhNhan getBenhNhan();
    BacSi getBacSi();
    string getNgayKham();
    string getChanDoan();

    // Setter
    void setBenhNhan(BenhNhan bn);
    void setBacSi(BacSi bs);
    void setNgayKham(string ngayKham);
    void setChanDoan(string chanDoan);

    // Hàm nhập / xuất
    void nhap();
    void xuat();

    // Friend function (truy cập private)
    friend ostream& operator<<(ostream& out, const HoSoSucKhoe& hs);
};

#endif