#ifndef BACSI_H
#define BACSI_H
#include <iostream>
#include <string>
using namespace std;
class BacSi {
private:
    string ten;
    string chuyenKhoa;
    int maBS;
    static int dem; // tự tăng mã bác sĩ
public:
    // Constructor mặc định
    BacSi();
    // Constructor có tham số
    BacSi(string ten, string chuyenKhoa);
    // Destructor
    ~BacSi();
    // Getter
    string getTen();
    string getChuyenKhoa();
    int getMaBS();
    // Setter
    void setTen(string ten);
    void setChuyenKhoa(string chuyenKhoa);
    // Hàm nhập / xuất
    void nhap();
    void xuat();
    // Nạp chồng toán tử
    friend istream& operator>>(istream& in, BacSi& bs);
    friend ostream& operator<<(ostream& out, const BacSi& bs);
    // So sánh 2 bác sĩ theo mã
    bool operator==(const BacSi& other);
};
#endif