#include "benhnhan.h"

// Khởi tạo biến static
int BenhNhan::dem = 0;

// Constructor mặc định
BenhNhan::BenhNhan() {
    ten = "";
    tuoi = 0;
    diaChi = "";
    maBN = ++dem;
}

// Constructor có tham số
BenhNhan::BenhNhan(string ten, int tuoi, string diaChi) {
    this->ten = ten;
    setTuoi(tuoi); // kiểm tra điều kiện
    this->diaChi = diaChi;
    maBN = ++dem;
}

// Destructor
BenhNhan::~BenhNhan() {
    cout << "Da huy benh nhan: " << ten << endl;
}

// Getter
string BenhNhan::getTen() {
    return ten;
}

int BenhNhan::getMaBN() {
    return maBN;
}

int BenhNhan::getTuoi() {
    return tuoi;
}

string BenhNhan::getDiaChi() {
    return diaChi;
}

// Setter
void BenhNhan::setTen(string ten) {
    this->ten = ten;
}

void BenhNhan::setTuoi(int tuoi) {
    if (tuoi > 0)
        this->tuoi = tuoi;
    else
        this->tuoi = 0;
}

void BenhNhan::setDiaChi(string diaChi) {
    this->diaChi = diaChi;
}

// Hàm nhập
void BenhNhan::nhap() {
    cin.ignore();
    cout << "Nhap ten: ";
    getline(cin, ten);

    cout << "Nhap tuoi: ";
    cin >> tuoi;
    setTuoi(tuoi);

    cin.ignore();
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}

// Hàm xuất
void BenhNhan::xuat() {
    cout << "Ma BN: " << maBN << endl;
    cout << "Ten: " << ten << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "Dia chi: " << diaChi << endl;
}

// Nạp chồng toán tử >>
istream& operator>>(istream& in, BenhNhan& bn) {
    in.ignore();
    cout << "Nhap ten: ";
    getline(in, bn.ten);

    cout << "Nhap tuoi: ";
    in >> bn.tuoi;
    bn.setTuoi(bn.tuoi);

    in.ignore();
    cout << "Nhap dia chi: ";
    getline(in, bn.diaChi);

    return in;
}

// Nạp chồng toán tử <<
ostream& operator<<(ostream& out, const BenhNhan& bn) {
    out << "Ma BN: " << bn.maBN << endl;
    out << "Ten: " << bn.ten << endl;
    out << "Tuoi: " << bn.tuoi << endl;
    out << "Dia chi: " << bn.diaChi << endl;
    return out;
}