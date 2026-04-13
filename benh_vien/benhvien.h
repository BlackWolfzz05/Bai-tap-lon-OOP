#ifndef BENHVIEN_H
#define BENHVIEN_H

#include "../bac_si/bacsi.h"
#include "../benh_nhan/benhnhan.h"
#include "../hoa_don/hoadon.h"
#include "../co_so_vat_chat/phongbenh.h"
#include "../he_thong/danhmuc.h"
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class BenhVien {
private:
    BenhNhan*    dsBN[MAX_SIZE];
    int slBN;

    BacSi*       dsBS[MAX_SIZE];
    int slBS;

    HoaDon*      dsHD[MAX_SIZE];
    int slHD;

    PhongBenh*   dsPB[MAX_SIZE];
    int slPB;

    DanhMuc      danhMucTraCuu;

    static int nhapSoNguyen(const string& prompt);
    void hienThiMenu() const;

    // --- I. QUAN LY DOI TUONG ---
    void themHoSoBenhNhan();             // 1
    void xemDanhSachBenhNhan() const;    // 2
    void thaoTacBenhNhan();              // 3
    void dieuPhoiXepGiuong(int indexBN); // Helper xep giuong

    void themThongTinBacSi();            // 4
    void xemDanhSachBacSi() const;       // 5
    void thaoTacBacSi();                 // 6

    // --- II. QUAN LY CO SO VAT CHAT ---
    void quanLyPhongBenh();              // 7
    void soDoGiuongBenh() const;         // 8

    // --- III. QUAN LY HE THONG & THONG KE ---
    void quanLyDanhMuc();                // 9
    void baoCaoThongKe() const;          // 10
    void saoLuuDuLieu();                 // 11
    void khoiPhucDuLieu();               // 12

public:
    BenhVien();
    ~BenhVien();

    void chay();
};

#endif
