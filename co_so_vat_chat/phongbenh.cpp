#include "phongbenh.h"

PhongBenh::PhongBenh() : maPhong(""), tenPhong(""), loaiPhong("Thuong"), soGiuong(0), soGiuongDaNhan(0) {}

PhongBenh::PhongBenh(string maPhong, string tenPhong, string loaiPhong, int soGiuong) {
    this->maPhong = maPhong;
    this->tenPhong = tenPhong;
    this->loaiPhong = loaiPhong;
    this->soGiuong = soGiuong;
    this->soGiuongDaNhan = 0;
}

PhongBenh::~PhongBenh() {}

string PhongBenh::getMaPhong() { return maPhong; }
string PhongBenh::getTenPhong() { return tenPhong; }
string PhongBenh::getLoaiPhong() { return loaiPhong; }
int PhongBenh::getSoGiuong() { return soGiuong; }
int PhongBenh::getSoGiuongThongTrong() { return soGiuong - soGiuongDaNhan; }

bool PhongBenh::nhanGiuong(int &soGiuongDcCap) {
    if (soGiuongDaNhan < soGiuong) {
        soGiuongDaNhan++;
        soGiuongDcCap = soGiuongDaNhan; // Cap cho ho giuong ke tiep
        return true;
    }
    return false;
}

void PhongBenh::traGiuong() {
    if (soGiuongDaNhan > 0) {
        soGiuongDaNhan--;
    }
}

void PhongBenh::nhap() {
    cout << "Nhap ma phong: ";
    getline(cin >> ws, maPhong);
    cout << "Nhap ten phong: ";
    getline(cin >> ws, tenPhong);
    
    int loai;
    cout << "Chon loai phong (1. Thuong, 2. VIP): ";
    cin >> loai;
    if (loai == 2) loaiPhong = "VIP";
    else loaiPhong = "Thuong";
    
    cout << "Nhap so giuong toi da: ";
    cin >> soGiuong;
    soGiuongDaNhan = 0;
}

void PhongBenh::xuat() {
    cout << "Phong " << loaiPhong << " [" << maPhong << "] " << tenPhong 
         << " - Giuong da nhan: " << soGiuongDaNhan << "/" << soGiuong << "\n";
}
