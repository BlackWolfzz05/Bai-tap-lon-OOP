#include "bacsi.h"

// Khoi tao bien static
int BacSi::dem = 1;

// ---- Constructor mac dinh ----
BacSi::BacSi()
    : maBS(dem++), hoTen(""), nghiepVu(""),
      chuyenKhoa(""), hocVi(""), quyenHan("") {}

// ---- Constructor co tham so ----
BacSi::BacSi(string hoTen, string nghiepVu, string chuyenKhoa,
             string hocVi, string quyenHan)
    : maBS(dem++), hoTen(hoTen), nghiepVu(nghiepVu),
      chuyenKhoa(chuyenKhoa), hocVi(hocVi), quyenHan(quyenHan) {}

// ---- Destructor ----
BacSi::~BacSi() {}

// ---- Nhap ----
void BacSi::nhap() {
    // Ho ten (khong duoc de trong)
    do {
        cout << "Nhap ho va ten bac si (khong duoc de trong): ";
        getline(cin >> ws, hoTen);
        if (hoTen.empty())
            cout << "  [!] Ho ten khong duoc de trong! Nhap lai.\n";
    } while (hoTen.empty());

    cout << "Nhap nghiep vu (VD: Noi khoa, Ngoai khoa, ...): ";
    getline(cin >> ws, nghiepVu);

    cout << "Nhap chuyen khoa (VD: Tim mach, Than kinh, ...): ";
    getline(cin >> ws, chuyenKhoa);

    cout << "Nhap hoc vi (VD: Tien si, Thac si, Bac si, ...): ";
    getline(cin >> ws, hocVi);

    cout << "Nhap quyen han (VD: Truong khoa, Pho khoa, Bac si dieu tri, ...): ";
    getline(cin >> ws, quyenHan);
}

// ---- Xuat ----
void BacSi::xuat() const {
    cout << "Ma BS      : " << maBS       << endl;
    cout << "Ho va ten  : " << hoTen      << endl;
    cout << "Nghiep vu  : " << nghiepVu   << endl;
    cout << "Chuyen khoa: " << chuyenKhoa << endl;
    cout << "Hoc vi     : " << hocVi      << endl;
    cout << "Quyen han  : " << quyenHan   << endl;
}

// ---- Nap chong >> ----
istream& operator>>(istream& in, BacSi& bs) {
    do {
        cout << "Nhap ho va ten bac si (khong duoc de trong): ";
        getline(in >> ws, bs.hoTen);
        if (bs.hoTen.empty())
            cout << "  [!] Ho ten khong duoc de trong! Nhap lai.\n";
    } while (bs.hoTen.empty());

    cout << "Nhap nghiep vu: ";
    getline(in >> ws, bs.nghiepVu);
    cout << "Nhap chuyen khoa: ";
    getline(in >> ws, bs.chuyenKhoa);
    cout << "Nhap hoc vi: ";
    getline(in >> ws, bs.hocVi);
    cout << "Nhap quyen han: ";
    getline(in >> ws, bs.quyenHan);
    return in;
}

// ---- Nap chong << ----
ostream& operator<<(ostream& out, const BacSi& bs) {
    out << "Ma BS      : " << bs.maBS       << endl;
    out << "Ho va ten  : " << bs.hoTen      << endl;
    out << "Nghiep vu  : " << bs.nghiepVu   << endl;
    out << "Chuyen khoa: " << bs.chuyenKhoa << endl;
    out << "Hoc vi     : " << bs.hocVi      << endl;
    out << "Quyen han  : " << bs.quyenHan   << endl;
    return out;
}