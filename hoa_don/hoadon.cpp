#include "hoadon.h"

// ================== THUOC ==================

Thuoc::Thuoc() : tenThuoc(""), soLuong(0), gia(0) {}

Thuoc::Thuoc(string tenThuoc, int soLuong, double gia) {
    this->tenThuoc = tenThuoc;
    setSoLuong(soLuong);
    setGia(gia);
}

Thuoc::~Thuoc() {}

// Getter
string Thuoc::getTenThuoc() const { return tenThuoc; }
int    Thuoc::getSoLuong()  const { return soLuong; }
double Thuoc::getGia()      const { return gia; }

// Setter
void Thuoc::setTenThuoc(string t)  { this->tenThuoc = t; }
void Thuoc::setSoLuong(int sl)     { this->soLuong = (sl > 0) ? sl : 0; }
void Thuoc::setGia(double g)       { this->gia     = (g  > 0) ? g  : 0; }

// Loi #5: fix cin.ignore() thua - su dung getline(cin >> ws, ...)
// Loi #4: them validation so luong va gia phai > 0
void Thuoc::nhap() {
    cout << "  Nhap ten thuoc (khong duoc de trong): ";
    do {
        getline(cin >> ws, tenThuoc);
        if (tenThuoc.empty())
            cout << "  [!] Ten thuoc khong duoc de trong! Nhap lai: ";
    } while (tenThuoc.empty());

    cout << "  Nhap so luong (> 0): ";
    while (!(cin >> soLuong) || soLuong <= 0) {
        cin.clear(); cin.ignore();
        cout << "  [!] So luong phai la so nguyen duong! Nhap lai: ";
    }

    cout << "  Nhap don gia (VND, > 0): ";
    while (!(cin >> gia) || gia <= 0) {
        cin.clear(); cin.ignore();
        cout << "  [!] Don gia phai lon hon 0! Nhap lai: ";
    }
    setGia(gia);
}

void Thuoc::xuat() const {
    cout << "  Ten thuoc : " << tenThuoc << endl;
    cout << "  So luong  : " << soLuong << endl;
    cout << "  Don gia   : " << fixed << setprecision(0) << gia << " VND" << endl;
    cout << "  Thanh tien: " << fixed << setprecision(0) << soLuong * gia << " VND" << endl;
}

// ================== HOA DON ==================

// Loi #10: constructor mac dinh - maBN = 0 (chua xac dinh)
HoaDon::HoaDon() : maBN(0), soLuongThuoc(0), tongTien(0) {}

// Loi #10: constructor co ma benh nhan
HoaDon::HoaDon(int maBN) : maBN(maBN), soLuongThuoc(0), tongTien(0) {}

// Loi #2: Destructor KHONG in gi (tranh spam)
HoaDon::~HoaDon() {}

// Getter
int    HoaDon::getMaBN()     { return maBN; }
double HoaDon::getTongTien() { return tongTien; }

// Them thuoc
void HoaDon::themThuoc(Thuoc t) {
    if (soLuongThuoc < MAX_THUOC)
        dsThuoc[soLuongThuoc++] = t;
    else
        cout << "[!] Hoa don da day (toi da " << MAX_THUOC << " loai thuoc)!\n";
}

// Tinh tong tien
void HoaDon::tinhTongTien() {
    tongTien = 0;
    for (int i = 0; i < soLuongThuoc; i++)
        tongTien += dsThuoc[i].getSoLuong() * dsThuoc[i].getGia();
}

void HoaDon::nhap() {
    cout << "--- Lap hoa don ---\n";
    int n;
    cout << "Nhap so luong loai thuoc / dich vu KCB can them: ";
    cin >> n;

    if (soLuongThuoc + n > MAX_THUOC) {
        cout << "Khong the them qua " << MAX_THUOC - soLuongThuoc << " loai thuoc nua.\n";
        n = MAX_THUOC - soLuongThuoc;
    }

    int start = soLuongThuoc;
    soLuongThuoc += n;
    for (int i = start; i < soLuongThuoc; i++) {
        cout << "\nThuoc / dich vu thu " << i + 1 << ":\n";
        dsThuoc[i].nhap();
    }
    tinhTongTien();
}

// Loi #10: xuat hien thi maBN
void HoaDon::xuat() const {
    cout << "\n===== HOA DON =====\n";
    cout << "Benh nhan (Ma BN): " << (maBN > 0 ? to_string(maBN) : "Chua xac dinh") << "\n";
    if (soLuongThuoc == 0) {
        cout << "  (Khong co thuoc nao)\n";
    } else {
        for (int i = 0; i < soLuongThuoc; i++) {
            cout << "\n  Thuoc " << i + 1 << ":\n";
            dsThuoc[i].xuat();
        }
    }
    cout << "\nTong tien: " << fixed << setprecision(0) << tongTien << " VND\n";
}

// Nap chong <<
ostream& operator<<(ostream& out, const HoaDon& hd) {
    out << "\n===== HOA DON =====\n";
    out << "Benh nhan (Ma BN): " << (hd.maBN > 0 ? to_string(hd.maBN) : "Chua xac dinh") << "\n";
    for (int i = 0; i < hd.soLuongThuoc; i++) {
        out << "\n  Thuoc " << i + 1 << ":\n";
        out << "  Ten thuoc : " << hd.dsThuoc[i].getTenThuoc() << endl;
        out << "  So luong  : " << hd.dsThuoc[i].getSoLuong() << endl;
        out << "  Don gia   : " << fixed << setprecision(0) << hd.dsThuoc[i].getGia() << " VND\n";
    }
    out << "\nTong tien: " << fixed << setprecision(0) << hd.tongTien << " VND\n";
    return out;
}