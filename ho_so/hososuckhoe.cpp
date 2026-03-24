#include "hososuckhoe.h"
#include <limits>

// Constructor mặc định
HoSoSucKhoe::HoSoSucKhoe() {
    ngayKham = "";
    chanDoan = "";
}

// Constructor có tham số
HoSoSucKhoe::HoSoSucKhoe(BenhNhan bn, BacSi bs, string ngayKham, string chanDoan) {
    this->bn = bn;
    this->bs = bs;
    this->ngayKham = ngayKham;
    this->chanDoan = chanDoan;
}

// Destructor
HoSoSucKhoe::~HoSoSucKhoe() {
    cout << "Da huy ho so suc khoe\n";
}

// Getter
BenhNhan HoSoSucKhoe::getBenhNhan() {
    return bn;
}

BacSi HoSoSucKhoe::getBacSi() {
    return bs;
}

string HoSoSucKhoe::getNgayKham() {
    return ngayKham;
}

string HoSoSucKhoe::getChanDoan() {
    return chanDoan;
}

// Setter
void HoSoSucKhoe::setBenhNhan(BenhNhan bn) {
    this->bn = bn;
}

void HoSoSucKhoe::setBacSi(BacSi bs) {
    this->bs = bs;
}

void HoSoSucKhoe::setNgayKham(string ngayKham) {
    this->ngayKham = ngayKham;
}

void HoSoSucKhoe::setChanDoan(string chanDoan) {
    this->chanDoan = chanDoan;
}

// Hàm nhập
void HoSoSucKhoe::nhap() {
    cout << "\n--- Nhap thong tin benh nhan ---\n";
    cin >> bn;

    cout << "\n--- Nhap thong tin bac si ---\n";
    cin >> bs;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap ngay kham: ";
    getline(cin, ngayKham);

    cout << "Nhap chan doan: ";
    getline(cin, chanDoan);
}

// Hàm xuất
void HoSoSucKhoe::xuat() {
    cout << "\n===== HO SO SUC KHOE =====\n";

    cout << "\n--- Benh nhan ---\n";
    cout << bn;

    cout << "\n--- Bac si ---\n";
    cout << bs;

    cout << "Ngay kham: " << ngayKham << endl;
    cout << "Chan doan: " << chanDoan << endl;
}

// Nạp chồng toán tử <<
ostream& operator<<(ostream& out, const HoSoSucKhoe& hs) {
    out << "\n===== HO SO SUC KHOE =====\n";

    out << "\n--- Benh nhan ---\n";
    out << hs.bn;

    out << "\n--- Bac si ---\n";
    out << hs.bs;

    out << "Ngay kham: " << hs.ngayKham << endl;
    out << "Chan doan: " << hs.chanDoan << endl;

    return out;
}