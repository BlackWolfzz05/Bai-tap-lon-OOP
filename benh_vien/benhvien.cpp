#include "benhvien.h"

BenhVien::BenhVien() : slBN(0), slBS(0), slHD(0), slPB(0) {
    for (int i = 0; i < MAX_SIZE; i++) {
        dsBN[i] = nullptr;
        dsBS[i] = nullptr;
        dsHD[i] = nullptr;
        dsPB[i] = nullptr;
    }
    
    // Yeu cau tu dong nap san 20 phong Thuong (moi phong 6 giuong)
    for (int i = 1; i <= 20; i++) {
        string ma = "T" + to_string(i);
        if (i < 10) ma = "T0" + to_string(i);
        dsPB[slPB++] = new PhongBenh(ma, "Phong Thuong", "Thuong", 6);
    }
    
    // Yeu cau tu dong nap san 5 phong VIP (moi phong 1 giuong)
    for (int i = 1; i <= 5; i++) {
        string ma = "V0" + to_string(i);
        dsPB[slPB++] = new PhongBenh(ma, "Phong VIP", "VIP", 1);
    }
}

BenhVien::~BenhVien() {
    for (int i = 0; i < slBN; i++) delete dsBN[i];
    for (int i = 0; i < slBS; i++) delete dsBS[i];
    for (int i = 0; i < slPB; i++) delete dsPB[i];
}

int BenhVien::nhapSoNguyen(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        cin >> val;
        if (!cin.fail()) break;
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "  [!] Chi duoc nhap so! Nhap lai.\n";
    }
    return val;
}

void BenhVien::hienThiMenu() const {
    cout << "\n==========================================================\n";
    cout << "               HE THONG QUAN LY BENH VIEN\n";
    cout << "==========================================================\n";
    cout << "  --- I. QUAN LY DOI TUONG (Benh Nhan & Bac Si) ---\n";
    cout << "  1. Them benh nhan moi\n";
    cout << "  2. Xem danh sach benh nhan\n";
    cout << "  3. Tra cuu / Cap nhat / Xoa thong tin benh nhan\n\n";
    
    cout << "  4. Them thong tin bac si\n";
    cout << "  5. Danh sach doi ngu bac si\n";
    cout << "  6. Tra cuu / Cap nhat / Xoa thong tin bac si\n\n";

    cout << "  --- II. QUAN LY CO SO VAT CHAT ---\n";
    cout << "  7. Quan ly danh muc phong benh (Them/Sua/Xoa)\n";
    cout << "  8. So do phan bo va Hien trang giuong benh\n\n";

    cout << "  --- III. QUAN LY HE THONG & THONG KE ---\n";
    cout << "  9. Quan ly danh muc he thong (Thuoc & Dich vu)\n";
    cout << "  10. Bao cao tong doanh thu benh vien\n";
    cout << "  11. Sao luu he thong ra File (.txt)\n";
    cout << "  12. Khoi phuc du lieu he thong tu File\n";
    cout << "  0. Thoat chuong trinh\n";
    cout << "==========================================================\n";
}

void BenhVien::themHoSoBenhNhan() {
    if (slBN >= MAX_SIZE) { cout << "[!] Danh sach benh nhan da day!\n"; return; }
    cout << "\n--- Nhap ho so benh nhan mong muon ---\n";
    dsBN[slBN] = new BenhNhan();
    dsBN[slBN]->nhap();
    cout << "[OK] Da them benh nhan. Ma BN = " << dsBN[slBN]->getMaBN() << "\n";
    slBN++;
    
    int tinHieuXepGiuong = dsBN[slBN - 1]->quyTrinhKhamBenh();
    if (tinHieuXepGiuong == 1) {
        dieuPhoiXepGiuong(slBN - 1);
    }
}

void BenhVien::dieuPhoiXepGiuong(int indexBN) {
    if (slPB == 0) {
        cout << "[!] Benh vien chua co he thong phong luu tru. Khong the xep giuong!\n";
        return;
    }
    cout << "\n--- CHUYEN SANG BUOC XEP GIUONG BENH ---\n";
    cout << "Danh sach phong con giuong trong:\n";
    bool coPhongTrong = false;
    for (int i = 0; i < slPB; i++) {
        if (dsPB[i]->getSoGiuongThongTrong() > 0) {
            cout << "  - Phong " << dsPB[i]->getLoaiPhong() << " [" << dsPB[i]->getMaPhong() << "] : " << dsPB[i]->getTenPhong() << " | Con " << dsPB[i]->getSoGiuongThongTrong() << " giuong\n";
            coPhongTrong = true;
        }
    }
    if (!coPhongTrong) {
        cout << "[!] Benh vien hien DA HET GIUONG! Khong the xep giuong.\n";
        return;
    }

    string maChon;
    int viTriPhong = -1;
    while (true) {
        cout << "Nhap Ma Phong muon chon de nhan giuong: ";
        getline(cin >> ws, maChon);
        for (int i = 0; i < slPB; i++) {
            if (dsPB[i]->getMaPhong() == maChon && dsPB[i]->getSoGiuongThongTrong() > 0) {
                viTriPhong = i;
                break;
            }
        }
        if (viTriPhong != -1) break;
        cout << "  [!] Ma phong khong hop le hoac phong da day! Nhap lai.\n";
    }

    int giuongDuocCap = 0;
    if (dsPB[viTriPhong]->nhanGiuong(giuongDuocCap)) {
        dsBN[indexBN]->setPhongLuuTru(dsPB[viTriPhong]->getMaPhong(), giuongDuocCap);
        cout << "======> XEP GIUONG THANH CONG <======\n";
        cout << "Benh nhan da duoc len Giuong so: " << giuongDuocCap << " | Tai Phong: " << dsPB[viTriPhong]->getMaPhong() << "\n";
    }
}

void BenhVien::xemDanhSachBenhNhan() const {
    cout << "\n--- DANH SACH CHI TIET BENH NHAN (" << slBN << " nguoi) ---\n";
    if (slBN == 0) { cout << "  (Chua co benh nhan nao)\n"; return; }
    for (int i = 0; i < slBN; i++) {
        cout << "\n  [" << i + 1 << "] ";
        dsBN[i]->xuat();
    }
}

void BenhVien::thaoTacBenhNhan() {
    if (slBN == 0) { cout << "[!] Chua co benh nhan nao de thao tac!\n"; return; }
    
    int ma = nhapSoNguyen("\nNhap ma benh nhan can tim (Hoac 0 de thoat): ");
    if (ma == 0) return;
    
    int index = -1;
    for (int i = 0; i < slBN; i++) {
        if (dsBN[i]->getMaBN() == ma) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "[!] Khong tim thay benh nhan co ma " << ma << ".\n";
        return;
    }

    cout << "\n--- BAN DANG THAO TAC VOI BENH NHAN ---\n";
    dsBN[index]->xuat();

    cout << "\nThao tac ban muon thuc hien:\n";
    cout << "  1. Tra cuu Chi tiet Ho so Benh An / KCB\n";
    cout << "  2. Cap nhat Lai Thong Tin Ca Nhan\n";
    cout << "  3. XOA benh nhan khoi he thong benh vien\n";
    cout << "  4. Lam thu tuc XUAT VIEN & Thanh toan (Chi danh cho Noi tru)\n";
    cout << "  0. Huy bo thao tac\n";
    int choice = nhapSoNguyen("Lua chon cua ban: ");

    if (choice == 1) {
        dsBN[index]->xuat(); // Xuat da tich hop ho so KCB
    } else if (choice == 2) {
        cout << "[!] Moi ban cap nhat thong tin hien tai cho benh nhan:\n";
        dsBN[index]->nhap();
        cout << "[OK] Cap nhat thanh cong!\n";
    } else if (choice == 3) {
        string xacNhan;
        cout << "Ban co chac chan muon xoa TOAN BO DU LIEU NAY khoi benh vien (y/n)? ";
        cin >> xacNhan;
        if (xacNhan == "y" || xacNhan == "Y") {
            delete dsBN[index];
            for (int i = index; i < slBN - 1; i++) dsBN[i] = dsBN[i + 1];
            slBN--;
            cout << "[OK] Da xoa xoa sach se!\n";
        } else {
            cout << "[INFO] Da huy thao tac xoa.\n";
        }
    } else if (choice == 4) {
        string mp = dsBN[index]->getMaPhongLuuTru();
        string lp = "Thuong";
        if (mp != "") {
             for (int i=0; i<slPB; i++) {
                 if (dsPB[i]->getMaPhong() == mp) {
                      lp = dsPB[i]->getLoaiPhong();
                      dsPB[i]->traGiuong();
                      dsBN[index]->setPhongLuuTru("", 0); // Xoa thong tin phong sau khi tra
                      break;
                 }
             }
        }
        dsBN[index]->thuTucXuatVien(lp);
    }
}

void BenhVien::themThongTinBacSi() {
    if (slBS >= MAX_SIZE) { cout << "[!] Danh sach bac si da day!\n"; return; }
    cout << "\n--- Nhap thong tin bac si ---\n";
    dsBS[slBS] = new BacSi();
    dsBS[slBS]->nhap();
    cout << "[OK] Da them bac si. Ma BS = " << dsBS[slBS]->getMaBS() << "\n";
    slBS++;
}

void BenhVien::xemDanhSachBacSi() const {
    cout << "\n--- DANH SACH BAC SI (" << slBS << " nguoi) ---\n";
    if (slBS == 0) { cout << "  (Chua co bac si nao)\n"; return; }
    for (int i = 0; i < slBS; i++) {
        cout << "\n  [" << i + 1 << "] ";
        dsBS[i]->xuat();
    }
}

void BenhVien::thaoTacBacSi() {
    if (slBS == 0) { cout << "[!] Chua co bac si nao de thao tac!\n"; return; }
    
    int ma = nhapSoNguyen("\nNhap ma bac si can tim (Hoac 0 de thoat): ");
    if (ma == 0) return;
    int index = -1;
    for (int i = 0; i < slBS; i++) {
        if (dsBS[i]->getMaBS() == ma) { index = i; break; }
    }

    if (index == -1) { cout << "[!] Khong tim thay. \n"; return; }

    cout << "\n--- THONG TIN BAC SI TIM THAY ---\n"; dsBS[index]->xuat();
    cout << "\nThao tac ban muon thuc hien:\n  1. Cap nhat thong tin\n  2. Xoa bac si\n  0. Huy\n";
    int choice = nhapSoNguyen("Lua chon: ");

    if (choice == 1) {
        dsBS[index]->nhap(); cout << "[OK] Da cap nhat.\n";
    } else if (choice == 2) {
        delete dsBS[index];
        for (int i = index; i < slBS - 1; i++) dsBS[i] = dsBS[i + 1];
        slBS--;
        cout << "[OK] Da xoa!\n";
    }
}

void BenhVien::quanLyPhongBenh() {
    cout << "\n--- II. QUAN LY DANH MUC PHONG BENH ---\n";
    cout << "1. Them phong benh moi\n2. Sua thong tin phong benh\n3. Xoa phong benh khoi he thong\n0. Huy/Quay lai\n";
    int choice = nhapSoNguyen("Lua chon chuc nang: ");
    
    if (choice == 1) {
        if (slPB >= MAX_SIZE) { cout << "[!] Danh sach phong day!\n"; return; }
        dsPB[slPB] = new PhongBenh();
        dsPB[slPB]->nhap();
        slPB++;
        cout << "[OK] Them phong thanh cong.\n";
    } else if (choice == 2 || choice == 3) {
        if (slPB == 0) { cout << "Chua co phong de thao tac!\n"; return; }
        string ma; cout << "Nhap ma phong: "; getline(cin >> ws, ma);
        int index = -1;
        for(int i=0; i<slPB; i++) { if (dsPB[i]->getMaPhong() == ma) { index = i; break; } }
        
        if (index == -1) { cout << "Khong tim thay phong!\n"; return; }
        
        if (choice == 2) {
            dsPB[index]->nhap(); cout << "[OK] Da sua.\n";
        } else { 
            delete dsPB[index];
            for(int i=index; i<slPB-1; i++) dsPB[i] = dsPB[i+1];
            slPB--;
            cout << "[OK] Da xoa!\n";
        }
    }
}

void BenhVien::soDoGiuongBenh() const {
    cout << "\n--- SO DO PHAN BO VA HIEN TRANG GIUONG BENH ---\n";
    if (slPB == 0) { cout << "  (Chua co co so vat chat nao)\n"; return; }
    for(int i=0; i < slPB; i++) { cout << "  [" << i+1 << "] "; dsPB[i]->xuat(); }
}

void BenhVien::quanLyDanhMuc() { cout << "[INFO] Dang phat trien (Phan He Thong)... \n"; }

void BenhVien::baoCaoThongKe() const { 
    cout << "\n============================================\n";
    cout << "   BAO CAO DOANH THU TOAN HE THONG\n";
    cout << "============================================\n";
    if (slBN == 0) { cout << "  (Chua co du lieu luu luong benh nhan)\n"; return; }
    double tongToanVien = 0;
    int soLuongCoTraPhe = 0;
    for (int i = 0; i < slBN; i++) {
        double phi = dsBN[i]->tinhTongVienPhi();
        if (phi > 0) {
            cout << " - BN: " << dsBN[i]->getTen() << "     | Phat sinh chi phi: " << phi << "\n";
            tongToanVien += phi;
            soLuongCoTraPhe++;
        }
    }
    cout << "--------------------------------------------\n";
    cout << " > Tong luot benh nhan phat sinh phi: " << soLuongCoTraPhe << "\n";
    cout << " > TONG DOANH THU HOP LE: " << tongToanVien << " VNĐ\n";
    cout << "============================================\n";
}

void BenhVien::saoLuuDuLieu() { cout << "[INFO] Dang phat trien (File I/O)...\n"; }
void BenhVien::khoiPhucDuLieu() { cout << "[INFO] Dang phat trien (File I/O)...\n"; }

void BenhVien::chay() {
    int choice;
    do {
        hienThiMenu();
        choice = nhapSoNguyen("Lua chon cua ban (0-12): ");
        switch (choice) {
        case 1: themHoSoBenhNhan();  break;
        case 2: xemDanhSachBenhNhan(); break;
        case 3: thaoTacBenhNhan(); break;
        case 4: themThongTinBacSi();     break;
        case 5: xemDanhSachBacSi(); break;
        case 6: thaoTacBacSi(); break;
        case 7: quanLyPhongBenh(); break;
        case 8: soDoGiuongBenh(); break;
        case 9: quanLyDanhMuc(); break;
        case 10: baoCaoThongKe(); break;
        case 11: saoLuuDuLieu(); break;
        case 12: khoiPhucDuLieu(); break;
        case 0: cout << "\nDong he thong. Tam biet!\n"; break;
        default: cout << "[!] Lua chon khong hop le!\n";
        }
    } while (choice != 0);
}
