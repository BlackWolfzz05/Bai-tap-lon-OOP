#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Person {
protected:
    string id;
    string name;

public:
    Person() {
        this->id = "";
        this->name = "";
    }

    Person(string id, string name) {
        this->id = id;
        this->name = name;
    }

    virtual ~Person() {}

    string getId() { return id; }
    string getName() { return name; }

    void setId(string id) { this->id = id; }
    void setName(string name) { this->name = name; }

    virtual void showInfo() {
        cout << "  " << id << "\t" << name << endl;
    }

    virtual void input() {
        cout << "  Nhap ten: ";
        getline(cin, name);
    }
};

class Customer : public Person {
public:
    Customer() : Person() {}

    Customer(string id, string name) : Person(id, name) {}

    void input() override {
        cout << "  Nhap ten khach hang: ";
        getline(cin, name);
    }
};

class Drink {
private:
    string id;
    string name;
    long long price;

public:
    Drink() {
        this->id = "";
        this->name = "";
        this->price = 0;
    }

    Drink(string id, string name, long long price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    string getId() { return id; }
    string getName() { return name; }
    long long getPrice() { return price; }

    void setId(string id) { this->id = id; }
    void setName(string name) { this->name = name; }
    void setPrice(long long price) { this->price = price; }

    void showInfo() {
        cout << "  " << id << "\t" << name << "\t" << price << endl;
    }

    void input() {
        cout << "  Nhap ten do uong: ";
        getline(cin, name);
        cout << "  Nhap gia: ";
        cin >> price;
        cin.ignore();
    }
};

class Employee : public Person {
private:
    string phone;
    string position;
    long long salary;

public:
    Employee() : Person() {
        this->phone = "";
        this->position = "";
        this->salary = 0;
    }

    Employee(string id, string name, string phone, string position, long long salary) : Person(id, name) {
        this->phone = phone;
        this->position = position;
        this->salary = salary;
    }

    string getPhone() { return phone; }
    string getPosition() { return position; }
    long long getSalary() { return salary; }

    void setPhone(string phone) { this->phone = phone; }
    void setPosition(string position) { this->position = position; }
    void setSalary(long long salary) { this->salary = salary; }

    void showInfo() override {
        cout << "  " << id << "\t" << name << "\t" << phone << "\t" << position << "\t" << salary << endl;
    }

    void input() override {
        cout << "  Nhap ten: ";
        getline(cin, name);
        cout << "  Nhap so dien thoai: ";
        getline(cin, phone);
        cout << "  Nhap chuc vu: ";
        getline(cin, position);
        cout << "  Nhap luong: ";
        cin >> salary;
        cin.ignore();
    }
};

class OrderDetail {
private:
    string drinkId;
    string drinkName;
    long long unitPrice;
    int quantity;

public:
    OrderDetail() {
        this->drinkId = "";
        this->drinkName = "";
        this->unitPrice = 0;
        this->quantity = 0;
    }

    OrderDetail(string drinkId, string drinkName, long long unitPrice, int quantity) {
        this->drinkId = drinkId;
        this->drinkName = drinkName;
        this->unitPrice = unitPrice;
        this->quantity = quantity;
    }

    string getDrinkId() { return drinkId; }
    string getDrinkName() { return drinkName; }
    long long getUnitPrice() { return unitPrice; }
    int getQuantity() { return quantity; }
    long long getSubTotal() { return unitPrice * quantity; }

    void setDrinkId(string drinkId) { this->drinkId = drinkId; }
    void setDrinkName(string drinkName) { this->drinkName = drinkName; }
    void setUnitPrice(long long unitPrice) { this->unitPrice = unitPrice; }
    void setQuantity(int quantity) { this->quantity = quantity; }

    void showInfo() {
        cout << "  " << drinkId << "\t" << drinkName << "\t" << unitPrice << "\t" << quantity << "\t" << getSubTotal() << endl;
    }
};

class Table {
private:
    string id;
    int capacity;
    bool available;

public:
    Table() {
        this->id = "";
        this->capacity = 0;
        this->available = true;
    }

    Table(string id, int capacity, bool available) {
        this->id = id;
        this->capacity = capacity;
        this->available = available;
    }

    string getId() { return id; }
    int getCapacity() { return capacity; }
    bool isAvailable() { return available; }

    void setId(string id) { this->id = id; }
    void setCapacity(int capacity) { this->capacity = capacity; }
    void setAvailable(bool available) { this->available = available; }

    void showInfo() {
        string trangThai;
        if (available) {
            trangThai = "Trong";
        } else {
            trangThai = "Co khach";
        }
        cout << "  " << id << "\t" << capacity << "\t" << trangThai << endl;
    }

    void input() {
        cout << "  Nhap suc chua (so cho): ";
        cin >> capacity;
        cin.ignore();
    }
};

const int MAX_DETAILS = 20;

class Order {
private:
    string id;
    string customerName;
    string employeeName;
    string tableId;
    OrderDetail details[MAX_DETAILS];
    int detailCount;
    string date;

public:
    Order() {
        this->id = "";
        this->customerName = "";
        this->employeeName = "";
        this->tableId = "";
        this->detailCount = 0;
        this->date = "";
    }

    Order(string id, string customerName, string employeeName, string tableId, string date) {
        this->id = id;
        this->customerName = customerName;
        this->employeeName = employeeName;
        this->tableId = tableId;
        this->detailCount = 0;
        this->date = date;
    }

    string getId() { return id; }
    string getCustomerName() { return customerName; }
    string getEmployeeName() { return employeeName; }
    string getTableId() { return tableId; }
    int getDetailCount() { return detailCount; }
    string getDate() { return date; }

    long long getTotalAmount() {
        long long total = 0;
        for (int i = 0; i < detailCount; i++) {
            total += details[i].getSubTotal();
        }
        return total;
    }

    OrderDetail getDetail(int index) { return details[index]; }

    void setId(string id) { this->id = id; }
    void setCustomerName(string customerName) { this->customerName = customerName; }
    void setEmployeeName(string employeeName) { this->employeeName = employeeName; }
    void setTableId(string tableId) { this->tableId = tableId; }
    void setDate(string date) { this->date = date; }

    void addDetail(OrderDetail detail) {
        if (detailCount < MAX_DETAILS) {
            details[detailCount++] = detail;
        }
    }

    void showInfo() {
        cout << endl;
        cout << "  HOA DON: " << id << endl;
        cout << "  Khach hang : " << customerName << endl;
        cout << "  Nhan vien  : " << employeeName << endl;
        cout << "  Ban        : " << tableId << endl;
        cout << "  Ngay       : " << date << endl;
        cout << endl;
        cout << "  Chi tiet don hang:" << endl;
        cout << "  " << "Ma" << "\t" << "Ten" << "\t" << "Don gia" << "\t" << "SL" << "\t" << "Thanh tien" << endl;
        for (int i = 0; i < detailCount; i++) {
            details[i].showInfo();
        }
        cout << endl;
        cout << "  TONG TIEN: " << getTotalAmount() << " VND" << endl;
    }
};

const int MAX_CUSTOMERS = 1000;

class CustomerManager {
private:
    Customer customers[MAX_CUSTOMERS];
    int count;

public:
    CustomerManager() {
        count = 0;
    }

    int getCount() { return count; }
    Customer getCustomer(int index) { return customers[index]; }

    Customer* findById(string id) {
        for (int i = 0; i < count; i++) {
            if (customers[i].getId() == id) return &customers[i];
        }
        return nullptr;
    }

    int findIndexById(string id) {
        for (int i = 0; i < count; i++) {
            if (customers[i].getId() == id) return i;
        }
        return -1;
    }

    void add() {
        if (count >= MAX_CUSTOMERS) {
            cout << "  Danh sach khach hang da day!" << endl;
            return;
        }

        string id;
        cout << "  Nhap ma khach hang: ";
        getline(cin, id);

        if (findById(id) != nullptr) {
            cout << "  Ma khach hang da ton tai!" << endl;
            return;
        }

        customers[count].setId(id);
        customers[count].input();
        count++;
        cout << "  Them khach hang thanh cong!" << endl;
    }

    void update() {
        string id;
        cout << "  Nhap ma khach hang can sua: ";
        getline(cin, id);

        Customer* c = findById(id);
        if (c == nullptr) {
            cout << "  Khong tim thay khach hang!" << endl;
            return;
        }

        cout << "  Thong tin hien tai:" << endl;
        c->showInfo();
        cout << endl;
        cout << "  Nhap thong tin moi:" << endl;
        c->input();
        cout << "  Cap nhat thanh cong!" << endl;
    }

    void remove() {
        string id;
        cout << "  Nhap ma khach hang can xoa: ";
        getline(cin, id);

        int index = findIndexById(id);
        if (index == -1) {
            cout << "  Khong tim thay khach hang!" << endl;
            return;
        }

        for (int i = index; i < count - 1; i++) {
            customers[i] = customers[i + 1];
        }
        count--;
        cout << "  Xoa khach hang thanh cong!" << endl;
    }

    void displayAll() {
        if (count == 0) {
            cout << "  Danh sach khach hang trong!" << endl;
            return;
        }
        cout << endl << "  DANH SACH KHACH HANG" << endl << endl;
        cout << "  " << left << setw(6) << "Ma" << "  " << left << setw(20) << "Ten" << endl;
        for (int i = 0; i < count; i++) {
            customers[i].showInfo();
        }
        cout << "  Tong: " << count << " khach hang" << endl;
    }
};

const int MAX_DRINKS = 1000;

class DrinkManager {
private:
    Drink drinks[MAX_DRINKS];
    int count;

public:
    DrinkManager() {
        count = 0;
    }

    int getCount() { return count; }
    Drink getDrink(int index) { return drinks[index]; }

    Drink* findById(string id) {
        for (int i = 0; i < count; i++) {
            if (drinks[i].getId() == id) return &drinks[i];
        }
        return nullptr;
    }

    int findIndexById(string id) {
        for (int i = 0; i < count; i++) {
            if (drinks[i].getId() == id) return i;
        }
        return -1;
    }

    void add() {
        if (count >= MAX_DRINKS) {
            cout << "  Danh sach do uong da day!" << endl;
            return;
        }

        string id;
        cout << "  Nhap ma do uong: ";
        getline(cin, id);

        if (findById(id) != nullptr) {
            cout << "  Ma do uong da ton tai!" << endl;
            return;
        }

        drinks[count].setId(id);
        drinks[count].input();
        count++;
        cout << "  Them do uong thanh cong!" << endl;
    }

    void update() {
        string id;
        cout << "  Nhap ma do uong can sua: ";
        getline(cin, id);

        Drink* d = findById(id);
        if (d == nullptr) {
            cout << "  Khong tim thay do uong!" << endl;
            return;
        }

        cout << "  Thong tin hien tai:" << endl;
        d->showInfo();
        cout << endl;
        cout << "  Nhap thong tin moi:" << endl;
        d->input();
        cout << "  Cap nhat thanh cong!" << endl;
    }

    void remove() {
        string id;
        cout << "  Nhap ma do uong can xoa: ";
        getline(cin, id);

        int index = findIndexById(id);
        if (index == -1) {
            cout << "  Khong tim thay do uong!" << endl;
            return;
        }

        for (int i = index; i < count - 1; i++) {
            drinks[i] = drinks[i + 1];
        }
        count--;
        cout << "  Xoa do uong thanh cong!" << endl;
    }

    void displayAll() {
        if (count == 0) {
            cout << "  Danh sach do uong trong!" << endl;
            return;
        }
        cout << endl << "  DANH SACH DO UONG" << endl << endl;
        cout << "  " << left << setw(6) << "Ma" << "  " << left << setw(20) << "Ten" << "  " << left << setw(12) << "Gia" << endl;
        for (int i = 0; i < count; i++) {
            drinks[i].showInfo();
        }
        cout << "  Tong: " << count << " do uong" << endl;
    }
};

const int MAX_EMPLOYEES = 1000;

class EmployeeManager {
private:
    Employee employees[MAX_EMPLOYEES];
    int count;

public:
    EmployeeManager() {
        count = 0;
    }

    int getCount() { return count; }
    Employee getEmployee(int index) { return employees[index]; }

    Employee* findById(string id) {
        for (int i = 0; i < count; i++) {
            if (employees[i].getId() == id) return &employees[i];
        }
        return nullptr;
    }

    int findIndexById(string id) {
        for (int i = 0; i < count; i++) {
            if (employees[i].getId() == id) return i;
        }
        return -1;
    }

    void add() {
        if (count >= MAX_EMPLOYEES) {
            cout << "  Danh sach nhan vien da day!" << endl;
            return;
        }

        string id;
        cout << "  Nhap ma nhan vien: ";
        getline(cin, id);

        if (findById(id) != nullptr) {
            cout << "  Ma nhan vien da ton tai!" << endl;
            return;
        }

        employees[count].setId(id);
        employees[count].input();
        count++;
        cout << "  Them nhan vien thanh cong!" << endl;
    }

    void update() {
        string id;
        cout << "  Nhap ma nhan vien can sua: ";
        getline(cin, id);

        Employee* e = findById(id);
        if (e == nullptr) {
            cout << "  Khong tim thay nhan vien!" << endl;
            return;
        }

        cout << "  Thong tin hien tai:" << endl;
        e->showInfo();
        cout << endl;
        cout << "  Nhap thong tin moi:" << endl;
        e->input();
        cout << "  Cap nhat thanh cong!" << endl;
    }

    void remove() {
        string id;
        cout << "  Nhap ma nhan vien can xoa: ";
        getline(cin, id);

        int index = findIndexById(id);
        if (index == -1) {
            cout << "  Khong tim thay nhan vien!" << endl;
            return;
        }

        for (int i = index; i < count - 1; i++) {
            employees[i] = employees[i + 1];
        }
        count--;
        cout << "  Xoa nhan vien thanh cong!" << endl;
    }

    void displayAll() {
        if (count == 0) {
            cout << "  Danh sach nhan vien trong!" << endl;
            return;
        }
        cout << endl << "  DANH SACH NHAN VIEN" << endl << endl;
        cout << "  " << left << setw(6) << "Ma" << "  " << left << setw(20) << "Ten" << "  " << left << setw(12) << "SDT" << "  " << left << setw(12) << "Chuc vu" << "  " << left << setw(12) << "Luong" << endl;
        for (int i = 0; i < count; i++) {
            employees[i].showInfo();
        }
        cout << "  Tong: " << count << " nhan vien" << endl;
    }
};

const int MAX_TABLES = 1000;

class TableManager {
private:
    Table tables[MAX_TABLES];
    int count;

public:
    TableManager() {
        count = 0;
    }

    int getCount() { return count; }
    Table getTable(int index) { return tables[index]; }

    Table* findById(string id) {
        for (int i = 0; i < count; i++) {
            if (tables[i].getId() == id) return &tables[i];
        }
        return nullptr;
    }

    int findIndexById(string id) {
        for (int i = 0; i < count; i++) {
            if (tables[i].getId() == id) return i;
        }
        return -1;
    }

    void add() {
        if (count >= MAX_TABLES) {
            cout << "  Danh sach ban da day!" << endl;
            return;
        }

        string id;
        cout << "  Nhap ma ban: ";
        getline(cin, id);

        if (findById(id) != nullptr) {
            cout << "  Ma ban da ton tai!" << endl;
            return;
        }

        tables[count].setId(id);
        tables[count].input();
        count++;
        cout << "  Them ban thanh cong!" << endl;
    }

    void update() {
        string id;
        cout << "  Nhap ma ban can sua: ";
        getline(cin, id);

        Table* t = findById(id);
        if (t == nullptr) {
            cout << "  Khong tim thay ban!" << endl;
            return;
        }

        cout << "  Thong tin hien tai:" << endl;
        t->showInfo();
        cout << endl;
        cout << "  Nhap thong tin moi:" << endl;
        t->input();
        cout << "  Cap nhat thanh cong!" << endl;
    }

    void remove() {
        string id;
        cout << "  Nhap ma ban can xoa: ";
        getline(cin, id);

        int index = findIndexById(id);
        if (index == -1) {
            cout << "  Khong tim thay ban!" << endl;
            return;
        }

        for (int i = index; i < count - 1; i++) {
            tables[i] = tables[i + 1];
        }
        count--;
        cout << "  Xoa ban thanh cong!" << endl;
    }

    void displayAll() {
        if (count == 0) {
            cout << "  Danh sach ban trong!" << endl;
            return;
        }
        cout << endl << "  DANH SACH BAN" << endl << endl;
        cout << "  " << left << setw(6) << "Ma" << "  " << left << setw(10) << "Suc chua" << "  " << left << setw(12) << "Trang thai" << endl;
        for (int i = 0; i < count; i++) {
            tables[i].showInfo();
        }
        cout << "  Tong: " << count << " ban" << endl;
    }
};

const int MAX_ORDERS = 1000;

class OrderManager {
private:
    Order orders[MAX_ORDERS];
    int count;

public:
    OrderManager() {
        count = 0;
    }

    int getCount() { return count; }

    Order* findById(string id) {
        for (int i = 0; i < count; i++) {
            if (orders[i].getId() == id) return &orders[i];
        }
        return nullptr;
    }

    int findIndexById(string id) {
        for (int i = 0; i < count; i++) {
            if (orders[i].getId() == id) return i;
        }
        return -1;
    }

    void add(DrinkManager& dm, CustomerManager& cm, EmployeeManager& em, TableManager& tm) {
        if (count >= MAX_ORDERS) {
            cout << "  Danh sach hoa don da day!" << endl;
            return;
        }

        string orderId;
        cout << "  Nhap ma hoa don: ";
        getline(cin, orderId);

        if (findById(orderId) != nullptr) {
            cout << "  Ma hoa don da ton tai!" << endl;
            return;
        }

        // Chon khach hang
        cm.displayAll();
        string custId;
        cout << "  Nhap ma khach hang: ";
        getline(cin, custId);
        Customer* cust = cm.findById(custId);
        if (cust == nullptr) {
            cout << "  Khong tim thay khach hang!" << endl;
            return;
        }

        // Chon nhan vien
        em.displayAll();
        string empId;
        cout << "  Nhap ma nhan vien phuc vu: ";
        getline(cin, empId);
        Employee* emp = em.findById(empId);
        if (emp == nullptr) {
            cout << "  Khong tim thay nhan vien!" << endl;
            return;
        }

        // Chon ban
        tm.displayAll();
        string tableId;
        cout << "  Nhap ma ban: ";
        getline(cin, tableId);
        Table* table = tm.findById(tableId);
        if (table == nullptr) {
            cout << "  Khong tim thay ban!" << endl;
            return;
        }

        string date;
        cout << "  Nhap ngay (dd/mm/yyyy): ";
        getline(cin, date);

        Order order(orderId, cust->getName(), emp->getName(), tableId, date);

        // Them do uong vao hoa don
        int choice = 1;
        while (choice == 1) {
            dm.displayAll();
            string drinkId;
            cout << "  Nhap ma do uong: ";
            getline(cin, drinkId);

            Drink* drink = dm.findById(drinkId);
            if (drink == nullptr) {
                cout << "  Khong tim thay do uong!" << endl;
            } else {
                int qty;
                cout << "  Nhap so luong: ";
                cin >> qty;
                cin.ignore();

                OrderDetail detail(drink->getId(), drink->getName(), drink->getPrice(), qty);
                order.addDetail(detail);
                cout << "  Da them do uong vao hoa don!" << endl;
            }

            cout << "  Tiep tuc them do uong? (1: Co, 0: Khong): ";
            cin >> choice;
            cin.ignore();
        }

        // Cap nhat trang thai ban
        table->setAvailable(false);

        orders[count++] = order;
        cout << "  Tao hoa don thanh cong!" << endl;
        order.showInfo();
    }

    void remove() {
        string id;
        cout << "  Nhap ma hoa don can xoa: ";
        getline(cin, id);

        int index = findIndexById(id);
        if (index == -1) {
            cout << "  Khong tim thay hoa don!" << endl;
            return;
        }

        for (int i = index; i < count - 1; i++) {
            orders[i] = orders[i + 1];
        }
        count--;
        cout << "  Xoa hoa don thanh cong!" << endl;
    }

    void displayAll() {
        if (count == 0) {
            cout << "  Danh sach hoa don trong!" << endl;
            return;
        }
        cout << endl << "  DANH SACH HOA DON" << endl << endl;
        for (int i = 0; i < count; i++) {
            orders[i].showInfo();
        }
        cout << "  Tong: " << count << " hoa don" << endl;
    }

    void revenueByDay() {
        string date;
        cout << "  Nhap ngay can xem (dd/mm/yyyy): ";
        getline(cin, date);

        long long totalRevenue = 0;
        int soHoaDon = 0;

        cout << endl << "  DOANH THU NGAY " << date << endl << endl;
        cout << "  " << "Ma HD" << "\t" << "Khach hang" << "\t" << "Nhan vien" << "\t" << "Tong tien" << endl;

        for (int i = 0; i < count; i++) {
            if (orders[i].getDate() == date) {
                cout << "  " << orders[i].getId() << "\t"
                     << orders[i].getCustomerName() << "\t"
                     << orders[i].getEmployeeName() << "\t"
                     << orders[i].getTotalAmount() << endl;
                totalRevenue = totalRevenue + orders[i].getTotalAmount();
                soHoaDon++;
            }
        }

        if (soHoaDon == 0) {
            cout << "  Khong co hoa don nao trong ngay nay!" << endl;
        } else {
            cout << endl;
            cout << "  So hoa don  : " << soHoaDon << endl;
            cout << "  TONG DOANH THU: " << totalRevenue << " VND" << endl;
        }
    }

    void revenueByMonth() {
        string thang, nam;
        cout << "  Nhap thang (vd: 01, 12): ";
        getline(cin, thang);
        cout << "  Nhap nam (vd: 2026): ";
        getline(cin, nam);

        string duoi = "/" + thang + "/" + nam;

        long long totalRevenue = 0;
        int soHoaDon = 0;

        cout << endl << "  DOANH THU THANG " << thang << "/" << nam << endl << endl;
        cout << "  " << "Ma HD" << "\t" << "Ngay" << "\t\t" << "Khach hang" << "\t" << "Nhan vien" << "\t" << "Tong tien" << endl;

        for (int i = 0; i < count; i++) {
            string ngay = orders[i].getDate();
            bool trung = false;
            if (ngay.length() == 10 && ngay.substr(2) == duoi) {
                trung = true;
            }
            if (trung) {
                cout << "  " << orders[i].getId() << "\t"
                     << ngay << "\t"
                     << orders[i].getCustomerName() << "\t"
                     << orders[i].getEmployeeName() << "\t"
                     << orders[i].getTotalAmount() << endl;
                totalRevenue = totalRevenue + orders[i].getTotalAmount();
                soHoaDon++;
            }
        }

        if (soHoaDon == 0) {
            cout << "  Khong co hoa don nao trong thang nay!" << endl;
        } else {
            cout << endl;
            cout << "  So hoa don  : " << soHoaDon << endl;
            cout << "  TONG DOANH THU: " << totalRevenue << " VND" << endl;
        }
    }
};

class Menu {
private:
    DrinkManager drinkManager;
    EmployeeManager employeeManager;
    CustomerManager customerManager;
    TableManager tableManager;
    OrderManager orderManager;

    void drinkMenu() {
        int choice;
        do {
            system("cls");
            cout << endl << "  QUAN LY DO UONG" << endl << endl;
            cout << "  1. Them do uong" << endl;
            cout << "  2. Sua do uong" << endl;
            cout << "  3. Xoa do uong" << endl;
            cout << "  4. Hien thi danh sach" << endl;
            cout << "  0. Quay lai" << endl;
            cout << "  Lua chon: ";
            cin >> choice;
            cin.ignore();

            if (choice >= 1 && choice <= 4) system("cls");
            switch (choice) {
                case 1: drinkManager.add(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 2: drinkManager.update(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 3: drinkManager.remove(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 4: drinkManager.displayAll(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 0: break;
                default: cout << "  Lua chon khong hop le!" << endl;
                    cout << endl << "  Nhan Enter de tiep tuc..."; cin.get();
            }
        } while (choice != 0);
    }

    void employeeMenu() {
        int choice;
        do {
            system("cls");
            cout << endl << "  QUAN LY NHAN VIEN" << endl << endl;
            cout << "  1. Them nhan vien" << endl;
            cout << "  2. Sua nhan vien" << endl;
            cout << "  3. Xoa nhan vien" << endl;
            cout << "  4. Hien thi danh sach" << endl;
            cout << "  0. Quay lai" << endl;
            cout << "  Lua chon: ";
            cin >> choice;
            cin.ignore();

            if (choice >= 1 && choice <= 4) system("cls");
            switch (choice) {
                case 1: employeeManager.add(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 2: employeeManager.update(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 3: employeeManager.remove(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 4: employeeManager.displayAll(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 0: break;
                default: cout << "  Lua chon khong hop le!" << endl;
                    cout << endl << "  Nhan Enter de tiep tuc..."; cin.get();
            }
        } while (choice != 0);
    }

    void customerMenu() {
        int choice;
        do {
            system("cls");
            cout << endl << "  QUAN LY KHACH HANG" << endl << endl;
            cout << "  1. Them khach hang" << endl;
            cout << "  2. Sua khach hang" << endl;
            cout << "  3. Xoa khach hang" << endl;
            cout << "  4. Hien thi danh sach" << endl;
            cout << "  0. Quay lai" << endl;
            cout << "  Lua chon: ";
            cin >> choice;
            cin.ignore();

            if (choice >= 1 && choice <= 4) system("cls");
            switch (choice) {
                case 1: customerManager.add(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 2: customerManager.update(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 3: customerManager.remove(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 4: customerManager.displayAll(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 0: break;
                default: cout << "  Lua chon khong hop le!" << endl;
                    cout << endl << "  Nhan Enter de tiep tuc..."; cin.get();
            }
        } while (choice != 0);
    }

    void tableMenu() {
        int choice;
        do {
            system("cls");
            cout << endl << "  QUAN LY BAN" << endl << endl;
            cout << "  1. Them ban" << endl;
            cout << "  2. Sua ban" << endl;
            cout << "  3. Xoa ban" << endl;
            cout << "  4. Hien thi danh sach" << endl;
            cout << "  0. Quay lai" << endl;
            cout << "  Lua chon: ";
            cin >> choice;
            cin.ignore();

            if (choice >= 1 && choice <= 4) system("cls");
            switch (choice) {
                case 1: tableManager.add(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 2: tableManager.update(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 3: tableManager.remove(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 4: tableManager.displayAll(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 0: break;
                default: cout << "  Lua chon khong hop le!" << endl;
                    cout << endl << "  Nhan Enter de tiep tuc..."; cin.get();
            }
        } while (choice != 0);
    }

    void orderMenu() {
        int choice;
        do {
            system("cls");
            cout << endl << "  QUAN LY HOA DON" << endl << endl;
            cout << "  1. Tao hoa don" << endl;
            cout << "  2. Xoa hoa don" << endl;
            cout << "  3. Hien thi danh sach" << endl;
            cout << "  0. Quay lai" << endl;
            cout << "  Lua chon: ";
            cin >> choice;
            cin.ignore();

            if (choice >= 1 && choice <= 3) system("cls");
            switch (choice) {
                case 1: orderManager.add(drinkManager, customerManager, employeeManager, tableManager); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 2: orderManager.remove(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 3: orderManager.displayAll(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 0: break;
                default: cout << "  Lua chon khong hop le!" << endl;
                    cout << endl << "  Nhan Enter de tiep tuc..."; cin.get();
            }
        } while (choice != 0);
    }

    void revenueMenu() {
        int choice;
        do {
            system("cls");
            cout << endl << "  QUAN LY DOANH THU" << endl << endl;
            cout << "  1. Doanh thu theo ngay" << endl;
            cout << "  2. Doanh thu theo thang" << endl;
            cout << "  0. Quay lai" << endl;
            cout << "  Lua chon: ";
            cin >> choice;
            cin.ignore();

            if (choice >= 1 && choice <= 2) system("cls");
            switch (choice) {
                case 1: orderManager.revenueByDay(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 2: orderManager.revenueByMonth(); cout << endl << "  Nhan Enter de tiep tuc..."; cin.get(); break;
                case 0: break;
                default: cout << "  Lua chon khong hop le!" << endl;
                    cout << endl << "  Nhan Enter de tiep tuc..."; cin.get();
            }
        } while (choice != 0);
    }

public:
    void run() {
        int choice;
        do {
            system("cls");
            cout << endl << "  QUAN LY QUAN COFFEE" << endl << endl;
            cout << "  1. Quan ly do uong" << endl;
            cout << "  2. Quan ly nhan vien" << endl;
            cout << "  3. Quan ly khach hang" << endl;
            cout << "  4. Quan ly ban" << endl;
            cout << "  5. Quan ly hoa don" << endl;
            cout << "  6. Quan ly doanh thu" << endl;
            cout << "  0. Thoat" << endl;
            cout << "  Lua chon: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: drinkMenu(); break;
                case 2: employeeMenu(); break;
                case 3: customerMenu(); break;
                case 4: tableMenu(); break;
                case 5: orderMenu(); break;
                case 6: revenueMenu(); break;
                case 0: break;
                default: cout << "  Lua chon khong hop le!" << endl;
                    cout << endl << "  Nhan Enter de tiep tuc..."; cin.get();
            }
        } while (choice != 0);
    }
};

int main() {
    Menu* menu = new Menu();
    menu->run();
    delete menu;
    return 0;
}