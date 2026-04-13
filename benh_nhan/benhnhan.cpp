#include "benhnhan.h"

int BenhNhan::dem = 1;

BenhNhan::BenhNhan() : tenBenh(""), loaiBenhAn(""), chanDoan(""), maBacSiKCB(0), ngayVaoVien(""), ngayRaVien(""), soNgayDieuTri(0), maPhongLuuTru(""), soGiuongLuuTru(0), slHoaDon(0) {
    this->maBN = dem++;
    this->ten = "";
    this->tuoi = 0;
    this->diaChi = "";
}

BenhNhan::BenhNhan(string ten, int tuoi, string diaChi) : tenBenh(""), loaiBenhAn(""), chanDoan(""), maBacSiKCB(0), ngayVaoVien(""), ngayRaVien(""), soNgayDieuTri(0), maPhongLuuTru(""), soGiuongLuuTru(0), slHoaDon(0) {
    this->maBN = dem++;
    this->ten = ten;
    this->tuoi = tuoi;
    this->diaChi = diaChi;
}

BenhNhan::~BenhNhan() {
    for (int i = 0; i < slHoaDon; i++) delete dsHoaDon[i];
}

string BenhNhan::getTen() { return ten; }
int BenhNhan::getMaBN() { return maBN; }
int BenhNhan::getTuoi() { return tuoi; }
string BenhNhan::getDiaChi() { return diaChi; }
string BenhNhan::getMaPhongLuuTru() { return maPhongLuuTru; }

void BenhNhan::setTen(string t) { ten = t; }
void BenhNhan::setDiaChi(string dc) { diaChi = dc; }
void BenhNhan::setTuoi(int t) { tuoi = t; }
void BenhNhan::setPhongLuuTru(string maP, int soG) { maPhongLuuTru = maP; soGiuongLuuTru = soG; }

void BenhNhan::nhap() {
    cout << "Nhap ho ten (khong de trong): ";
    getline(cin >> ws, ten);
    while (ten.empty()) {
        cout << "  [!] Ho ten khong duoc de trong! Nhap lai: ";
        getline(cin >> ws, ten);
    }

    string ageStr;
    bool validAge = false;
    do {
        cout << "Nhap tuoi (>0): ";
        cin >> ageStr;
        try {
            int t = stoi(ageStr);
            if (t > 0) {
                tuoi = t;
                validAge = true;
            } else {
                cout << "  [!] Tuoi phai lon hon 0!\n";
            }
        } catch (...) {
            cout << "  [!] Tuoi gi do sai roi! Vui long nhap so.\n";
        }
    } while (!validAge);

    cout << "Nhap dia chi: ";
    getline(cin >> ws, diaChi);
}

void BenhNhan::xuat() {
    cout << "\n--- THONG TIN BENH NHAN ---\n";
    cout << "Benh nhan: " << ten << " | Ma BN: " << maBN 
         << " | Tuoi: " << tuoi << " | Dia chi: " << diaChi << "\n";
         
    if (loaiBenhAn != "") {
        cout << " ==> HO SO CHUYEN MON (" << loaiBenhAn << ") <==\n";
        cout << "  - Ma BS kham     : " << maBacSiKCB << "\n";
        cout << "  - Ngay kham/vao  : " << ngayVaoVien << "\n";
        cout << "  - Ten benh       : " << tenBenh << "\n";
        cout << "  - Chuan doan BS  : " << chanDoan << "\n";
        if (loaiBenhAn == "Noi tru (Nhap vien)" || loaiBenhAn == "Noi tru (Da xuat vien)") {
            if (maPhongLuuTru != "") {
                cout << "  - Vi tri giuong  : Phong " << maPhongLuuTru << " (Giuong " << soGiuongLuuTru << ")\n";
            }
            cout << "  - Ngay ra vien   : " << ngayRaVien << "\n";
            cout << "  - So ngay DB/DT  : " << soNgayDieuTri << " ngay\n";
        }
    }
}

istream& operator>>(istream& in, BenhNhan& bn) {
    bn.nhap();
    return in;
}

ostream& operator<<(ostream& out, const BenhNhan& bn) {
    out << "Ma BN: " << bn.maBN << " | Ho ten: " << bn.ten;
    return out;
}

// ----------------------------------------------------
// QUAN LY NGHIEP VU KCB (PATIENT-CENTRIC TRUC TIEP)
// ----------------------------------------------------

int BenhNhan::quyTrinhKhamBenh() {
    cout << "\n--- LICH TRINH KHAM BENH CHO " << ten << " ---\n";
    cout << "Nhap ma bac si kham: ";
    cin >> maBacSiKCB;
    
    cout << "Nhap ngay kham (dd/mm/yyyy): ";
    getline(cin >> ws, ngayVaoVien);
    
    cout << "Nhap ten benh: ";
    getline(cin >> ws, tenBenh);
    
    cout << "Chuan doan cua bac si: ";
    getline(cin >> ws, chanDoan);
    
    cout << "\nYeu cau cua bac si muc do tinh trang benh:\n";
    cout << "  1. NANG => Phai NHAP VIEN dieu tri noi tru.\n";
    cout << "  2. NHE  => Ke thuoc, xuat hoa don va DI VE.\n";
    cout << "Chon yeu cau (1 hoac 2): ";
    int mucDo;
    cin >> mucDo;
    if (cin.fail()) { cin.clear(); cin.ignore(10000, '\n'); mucDo = 2; }
    
    if (mucDo == 1) {
        loaiBenhAn = "Noi tru (Nhap vien)";
        cout << "[!] Tinh trang NANG: Yeu cau tiep tiep Noi Tru.\n";
        cout << "Yeu cau nhap so ngay dieu tri du kien (tu 1 ngay): ";
        cin >> soNgayDieuTri;
        ngayRaVien = "";
        cout << "[OK] Da lap ho so nhap vien. Dang chuyen yeu cau xep giuong...\n";
        return 1; // Tin hieu => Can xep giuong
    } else {
        loaiBenhAn = "Ngoai tru (Ke thuoc)";
        soNgayDieuTri = 0;
        ngayRaVien = "";
        cout << "[!] Tinh trang NHE: Ho so se chuyen sang ke thuoc va xuat Hoa Don.\n";
        themHoaDon(); // Truc tiep tien hanh xuat hoa don va di ve
        cout << "[OK] Benh nhan da duoc xuat hoa don va co electric the di ve.\n";
        return 0; // Khong can giuong
    }
}

void BenhNhan::thuTucXuatVien(string loaiPhongLuuTru) {
    if (loaiBenhAn != "Noi tru (Nhap vien)") {
        cout << "[!] Benh nhan nay KHONG co ho so dang nam vien Noi tru.\n";
        return;
    }
    cout << "\n--- THU TUC XUAT VIEN CHO " << ten << " ---\n";
    cout << "Nhap ngay ra vien chinh thuc (dd/mm/yyyy): ";
    getline(cin >> ws, ngayRaVien);
    
    double donGia = (loaiPhongLuuTru == "VIP") ? 1000000 : 200000;
    
    loaiBenhAn = "Noi tru (Da xuat vien)";
    cout << "[OK] Da ghi nhan xuat vien. Chuyen sang he thong thanh toan vien phi...\n";
    themHoaDon(donGia, loaiPhongLuuTru);
    cout << "[OK] THU TUC XUAT VIEN HOAN TAT!\n";
}

void BenhNhan::themHoaDon(double donGiaGiuong, string loaiPhong) {
    if (slHoaDon >= MAX_HS) { cout << "[!] Vuot qua so luong hoa don cho phep.\n"; return; }
    cout << "\n--- Lap hoa don cho Benh nhan " << maBN << " ---\n";
    dsHoaDon[slHoaDon] = new HoaDon(maBN); // passing maBN
    
    if (donGiaGiuong > 0 && soNgayDieuTri > 0) {
        Thuoc phiGV("Phi luu tru giuong " + loaiPhong, soNgayDieuTri, donGiaGiuong);
        dsHoaDon[slHoaDon]->themThuoc(phiGV);
        cout << " [+] He thong da tu dong tich hop Phi luu tru Giang vao Hoa don!\n";
    }
    
    dsHoaDon[slHoaDon]->nhap();
    slHoaDon++;
    cout << "[OK] Hoa don thu " << slHoaDon << " lap xong!\n";
}

void BenhNhan::xemDanhSachHoaDon() {
    cout << "\n--- Danh sach Hoa don cua Benh nhan " << ten << " (" << maBN << ") ---\n";
    if (slHoaDon == 0) { cout << "  (Chua co hoa don nao)\n"; return; }
    for (int i = 0; i < slHoaDon; i++) {
        cout << "--- Phieu [" << i + 1 << "] ---\n";
        dsHoaDon[i]->xuat();
    }
}

double BenhNhan::tinhTongVienPhi() const {
    double total = 0;
    for (int i = 0; i < slHoaDon; i++) {
        total += dsHoaDon[i]->getTongTien();
    }
    return total;
}