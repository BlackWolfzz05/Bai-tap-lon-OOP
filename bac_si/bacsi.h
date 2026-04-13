#ifndef BACSI_H
#define BACSI_H
#include <iostream>
#include <string>
using namespace std;

// ================================================================
// CLASS BacSi
// Thuoc tinh: maBS, hoTen, nghiepVu, chuyenKhoa, hocVi, quyenHan
// ================================================================
class BacSi {
private:
    int    maBS;       // Ma dinh danh bac si
    string hoTen;      // Ho va ten bac si
    string nghiepVu;   // Nghiep vu (VD: Noi khoa, Ngoai khoa, ...)
    string chuyenKhoa; // Chuyen khoa (VD: Tim mach, Than kinh, ...)
    string hocVi;      // Hoc vi (VD: Tien si, Thac si, Bac si, ...)
    string quyenHan;   // Quyen han (VD: Truong khoa, Pho khoa, Bac si dieu tri, ...)

    static int dem;    // Bien dem de tu dong tang maBS

public:
    // ---- Constructors ----
    BacSi();
    BacSi(string hoTen, string nghiepVu, string chuyenKhoa,
          string hocVi, string quyenHan);

    // ---- Destructor ----
    ~BacSi();

    // ---- Getters ----
    int    getMaBS()       const { return maBS;       }
    string getHoTen()      const { return hoTen;      }
    string getNghiepVu()   const { return nghiepVu;   }
    string getChuyenKhoa() const { return chuyenKhoa; }
    string getHocVi()      const { return hocVi;      }
    string getQuyenHan()   const { return quyenHan;   }

    // ---- Setters ----
    void setHoTen(string ht)      { hoTen      = ht; }
    void setNghiepVu(string nv)   { nghiepVu   = nv; }
    void setChuyenKhoa(string ck) { chuyenKhoa = ck; }
    void setHocVi(string hv)      { hocVi      = hv; }
    void setQuyenHan(string qh)   { quyenHan   = qh; }

    // ---- Nhap / Xuat ----
    void nhap();
    void xuat() const;

    // ---- Nap chong toan tu ----
    bool operator==(const BacSi& other) const { return maBS == other.maBS; }

    friend istream& operator>>(istream& in, BacSi& bs);
    friend ostream& operator<<(ostream& out, const BacSi& bs);
};

#endif