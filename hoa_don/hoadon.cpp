#include "hoadon.h"
#include <limits>
Thuoc::Thuoc() {
    tenThuoc = "";
    soLuong = 0;
    gia = 0;
}
Thuoc::Thuoc(string tenThuoc, int soLuong, double gia) {
    this->tenThuoc = tenThuoc;
    this->soLuong = soLuong;
    setGia(gia);
}
Thuoc::~Thuoc() {}
// Getter
string Thuoc::getTenThuoc() const {
    return tenThuoc;
}

int Thuoc::getSoLuong() const {
    return soLuong;
}

double Thuoc::getGia() const {
    return gia;
}
// Setter
void Thuoc::setTenThuoc(string tenThuoc) {
    this->tenThuoc = tenThuoc;
}
void Thuoc::setSoLuong(int soLuong) {
    this->soLuong = soLuong;
}
void Thuoc::setGia(double gia) {
    if (gia > 0)
        this->gia = gia;
    else
        this->gia = 0;
}
// Nhập
void Thuoc::nhap() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nhap ten thuoc: ";
    getline(cin, tenThuoc);
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cout << "Nhap gia: ";
    cin >> gia;
    setGia(gia);
}
// Xuất
void Thuoc::xuat() {
    cout << "Ten thuoc: " << tenThuoc << endl;
    cout << "So luong: " << soLuong << endl;
    cout << "Gia: " << gia << endl;
}
// ================== HOA DON ==================
HoaDon::HoaDon() {
    tongTien = 0;
}
HoaDon::~HoaDon() {
    cout << "Da huy hoa don\n";
}
// Thêm thuốc
void HoaDon::themThuoc(Thuoc t) {
    dsThuoc.push_back(t);
}
// Tính tổng tiền
void HoaDon::tinhTongTien() {
    tongTien = 0;
    for (int i = 0; i < dsThuoc.size(); i++) {
        tongTien += dsThuoc[i].getSoLuong() * dsThuoc[i].getGia();
    }
}
// Getter
double HoaDon::getTongTien() {
    return tongTien;
}
// Nhập
void HoaDon::nhap() {
    int n;
    cout << "Nhap so luong thuoc: ";cin >> n;
    Thuoc t;
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thuoc thu " << i + 1 << ":\n";
        t.nhap();
        dsThuoc.push_back(t);
    }
    tinhTongTien();
}
// Xuất
void HoaDon::xuat() {
    cout << "\n===== HOA DON =====\n";
    for (int i = 0; i < dsThuoc.size(); i++) {
        cout << "\nThuoc " << i + 1 << ":\n";
        dsThuoc[i].xuat();
    }
    cout << "\nTong tien: " << tongTien << endl;
}
// Nạp chồng <<
ostream& operator<<(ostream& out, const HoaDon& hd) {
    out << "\n===== HOA DON =====\n";
    for (int i = 0; i < hd.dsThuoc.size(); i++) {
        out << "\nThuoc " << i + 1 << ":\n";
        out << "Ten thuoc: " << hd.dsThuoc[i].getTenThuoc() << endl;
        out << "So luong: " << hd.dsThuoc[i].getSoLuong() << endl;
        out << "Gia: " << hd.dsThuoc[i].getGia() << endl;
    }
    out << "\nTong tien: " << hd.tongTien << endl;
    return out;
}