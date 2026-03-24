#include "bacsi.h"
#include <limits>
// Constructor
BacSi::BacSi() {
    ten = "";
    chuyenKhoa = "";
}
// Destructor
BacSi::~BacSi() {}

// Getter
string BacSi::getTen() {
    return ten;
}

string BacSi::getChuyenKhoa() {
    return chuyenKhoa;
}

// Setter
void BacSi::setTen(string ten) {
    this->ten = ten;
}

void BacSi::setChuyenKhoa(string ck) {
    this->chuyenKhoa = ck;
}

// Nhập
istream& operator>>(istream& in, BacSi& bs) {
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ten bac si: ";
    getline(in, bs.ten);

    cout << "Nhap chuyen khoa: ";
    getline(in, bs.chuyenKhoa);

    return in;
}

// Xuất
ostream& operator<<(ostream& out, const BacSi& bs) {
    out << "Ten bac si: " << bs.ten << endl;
    out << "Chuyen khoa: " << bs.chuyenKhoa << endl;
    return out;
}