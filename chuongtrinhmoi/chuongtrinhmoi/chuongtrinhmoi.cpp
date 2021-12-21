#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

long int id_Phieu = 1000;
long int id_Sach = 1000;
long int id_Nguoi = 1000;
const int MAX = 1000;
/* Sach */
class Sach {
private:
    string m_tensach;
    string m_tacgia;
    string m_tinhtrang;
    string m_theloai;
    int m_tongsosach; // tong so sach con lai trong thu vien
    int m_masach;
    int m_gia;
public:
    /* Constructors */
    Sach();
    Sach(string, string, string, string, int, int);
    /* in-out  */
    void inSach();
    void nhapSach();
    /* ham setters */
    void set_TenSach(string);
    void set_TacGia(string);
    void set_TinhTrang(string);
    void set_TongSoSach(int);
    void set_MaSach(int);
    void set_theloai(string);
    void set_giasach(int);
    /* ham getters */
    string get_TenSach();
    string get_TacGia();
    string get_TinhTrang();
    int    get_TongSoSach();
    int    get_MaSach();
    int    get_giasach();
    string get_theloai();
};
/* Nguoi */
class Nguoi {
private:
    string m_ten;
    string m_sodienthoai;
    int m_tuoi;
    int m_id;
public:
    /* Constructors */
    Nguoi(string, int, string);
    Nguoi();
    /* ham getters */
    string get_ten();
    string get_sodienthoai();
    int get_tuoi();
    int get_ID();
    void get_infor();
};
class Phieu {
private:
    int pm_sosach = 0;
    int m_IDphieu = 0;
    Nguoi m_nguoimuonsach;
    Sach m_sach[5];  // muon toi da 5 quyen/1 lan;
    bool m_trangthai; // true = dang muon, false = da tra;
public:
    string m_ngaymuonsach;
    string m_ngayhethan;
    Phieu(Nguoi);
    Phieu();
    void dangKi();
    void themSach(Sach&);
    void xoaSach(int);
    void inPhieu();
    bool is_quaHan(); // kiem tra phieu nay qua han tra hay chua;
    void traSach();
    void muonSach();
    bool get_trangthai();
    int get_ID();
};
class QuanlyThuVien {
public:
    Phieu* m_phieu;
    Sach* m_dsSach;
    int pm_soluongPhieu = 0, pm_soluongSach = 0;
    QuanlyThuVien();
    void ds_QuaHan();
    void ds_Phieu();
    void ds_Sach();
    void themPhieu(Phieu);
    void xoaSachRaKhoiHeThong(int);
    // them mot cuon sach
    void themSachVaoHeThong(Sach&);
    // them n cuon sach
    void themSachVaoHeThong(Sach*, int n);
    void timSach();
};

int sls = 10;
int sln = 4;
QuanlyThuVien qltv;
//----------------------Demo mot vai cuon sach-------------------------//
Sach mybooks[10] = {
    {"Giai Tich 1", "Mai Ngoc Doan", "Toan Hoc", "Tot", 18500, 20},
    {"Giai Tich 2", "Mai Ngoc Doan", "Toan Hoc", "Tot", 30000, 10},
    {"Hoa Dai Cuong", "Mai Ngoc Doan", "Hoa Hoc", "Tot", 18500, 15},
    {"Lap Trinh C++", "Mai Ngoc Doan", "IT", "Tot", 18500, 16},
    {"He Dieu Hanh", "Mai Ngoc Doan", "IT", "Tot", 18500, 18},
    {"Dai So Tuyen Tinh", "Mai Ngoc Doan", "Toan Hoc", "Tot", 18500, 50},
    {"Phuong Phap Tinh", "Mai Ngoc Doan", "Toan Hoc", "Tot", 18500, 100},
    {"Vat Ly 2", "Mai Ngoc Doan", "Vat Ly", "Tot", 18500, 55},
    {"Giai Tich 3", "Mai Ngoc Doan", "Toan Hoc", "Tot", 18500, 33},
    {"Vat Ly 1", "Mai Ngoc Doan", "Vat Ly", "Tot", 18500, 28},
};
//----------------------Demo mot vai ban doc-------------------------//
Nguoi mypeople[4] = {
    {"Mai Ngoc Doan", 18, "123456789"},
    {"Trinh Thanh Nhien", 18, "9876554432"},
    {"Luu Nhu Hoang", 18, "9999888777"},
    {"Luu Nhat Vuong", 18, "9999888777"},
};
////
//-------------------------------------------------------------------//
Sach::Sach() {}
Sach::Sach(string name, string author, string genre, string stt, int pr, int res) {
    m_tensach = name;
    m_tacgia = author;
    m_theloai = genre;
    m_tinhtrang = stt;
    m_gia = pr;
    m_tongsosach = res;
    m_masach = id_Sach;
    id_Sach++;
}
void Sach::inSach() {
    cout << left; // can le trai;
    cout << "+-----------------Thong Tin Sach------------------+" << endl;
    cout << "|  ID: " << setw(43) << m_masach << "|" << endl;
    cout << "|  Title: " << setw(40) << m_tensach << "|" << endl;
    cout << "|  Author: " << setw(39) << m_tacgia << "|" << endl;
    cout << "|  Genre: " << setw(40) << m_theloai << "|" << endl;
    cout << "|  Amounts: " << setw(38) << m_tongsosach << "|" << endl;
    cout << "|  Price: " << setw(40) << m_gia << "|" << endl;
    cout << "|  Status: " << setw(39) << m_tinhtrang << "|" << endl;
    cout << "+-------------------------------------------------+" << endl;
    return;
}
void Sach::nhapSach() {
    cout << "Nhap sach: \n";
    cout << "-- Ten sach:";
    getline(cin, m_tensach);
    cout << "-- Ten tac gia: ";
    getline(cin, m_tacgia);
    cout << "-- The loai: ";
    getline(cin, m_theloai);
    cout << "-- So luong sach can them: ";
    cin >> m_tongsosach;
    cout << "-- Gia: ";
    cin >> m_gia;
    cin.ignore();
    cout << "-- Trang thai: ";
    getline(cin, m_tinhtrang);
    m_masach = id_Sach;
    id_Sach++;
    return;
}
/* ham setters */
void Sach::set_TenSach(string ts) {
    m_tensach = ts;
    return;
}
void Sach::set_TacGia(string tg) {
    m_tacgia = tg;
    return;
}
void Sach::set_TinhTrang(string tt) {
    m_tinhtrang = tt;
    return;
}
void Sach::set_TongSoSach(int ts) {
    m_tongsosach = ts;
    return;
}
void Sach::set_MaSach(int ms) {
    m_masach = ms;
    return;
}
void Sach::set_theloai(string tl) {
    m_theloai = tl;
    return;
}
void Sach::set_giasach(int gs) {
    m_gia = gs;
}
/* ham getters */
string Sach::get_TenSach() {
    return m_tensach;
}
string Sach::get_TacGia() {
    return m_tacgia;
}
string Sach::get_TinhTrang() {
    return m_tinhtrang;
}
int Sach::get_TongSoSach() {
    return m_tongsosach;
}
int Sach::get_MaSach() {
    return m_masach;
}
int Sach::get_giasach() {
    return m_gia;
}
string Sach::get_theloai() {
    return m_theloai;
}


/*****************************************/
Nguoi::Nguoi(string name, int age, string std) {
    m_ten = name;
    m_tuoi = age;
    m_sodienthoai = std;
    m_id = id_Nguoi;
    id_Nguoi++;
}
Nguoi::Nguoi() {
    m_id = id_Nguoi;
    id_Nguoi++;
}
string Nguoi::get_ten() {
    return m_ten;
}
string Nguoi::get_sodienthoai() {
    return m_sodienthoai;
}
int Nguoi::get_tuoi() {
    return m_tuoi;
}
int Nguoi::get_ID() {
    return m_id;
}
void Nguoi::get_infor() {
    cout << left; // can le trai;
    cout << "+----------------Thong Tin Ban Doc----------------+" << endl;
    cout << "|  ID: " << setw(43) << m_id << "|" << endl;
    cout << "|  Name: " << setw(41) << m_ten << "|" << endl;
    cout << "|  Age: " << setw(42) << m_tuoi << "|" << endl;
    cout << "|  Phone Number: " << setw(33) << m_sodienthoai << "|" << endl;
    cout << "+-------------------------------------------------+" << endl;
}

/*****************************************/

Phieu::Phieu(Nguoi ng) {
    m_nguoimuonsach = ng;
    m_trangthai = false;
    m_IDphieu = id_Phieu;
    pm_sosach = 0;
    id_Phieu++;
}
Phieu::Phieu() {}
void Phieu::themSach(Sach& s) {
    if (pm_sosach < 5 && s.get_TongSoSach() > 0) {
        m_sach[pm_sosach] = s;
        pm_sosach++;
        s.set_TongSoSach(s.get_TongSoSach() - 1);
        cout << "Them sach thanh cong \n";
    }
    else {
        cout << "Da qua gioi han muon sach hoac sach khong con tren he thong!\n";
    }
    return;
}
void Phieu::dangKi() {
    string name, pNum;
    int age;
    cout << "Nhap Ten cua ban: ";
    getline(cin, name);
    cout << "Nhap tuoi: ";
    cin >> age;
    cin.ignore();
    cout << "Nhap so dien thoai";
    getline(cin, pNum);
    Nguoi temp(name, age, pNum);
    // dang ki:
    m_nguoimuonsach = temp;
    return;
}
void Phieu::xoaSach(int index) {
    if (index < pm_sosach) {
        m_sach[index].set_TongSoSach(m_sach[index].get_TongSoSach() + 1);
        for (int i = index; i < pm_sosach - 1; i++) {
            m_sach[i] = m_sach[i + 1];
        }
        pm_sosach--;
        cout << "Da xoa thanh cong! \n";
    }
    else {
        cout << "Khong hop le! Xin vui long thu lai. \n";
    }
    return;
}
void Phieu::inPhieu() {
    cout << left; // can le trai;
    cout << endl;
    cout << "+------------------Phieu Muon Sach-----------------+" << endl;
    cout << "|   ID_P: " << setw(40) << m_nguoimuonsach.get_ID() << " |" << endl;
    cout << "|   ID_B : " << setw(39) << m_IDphieu << " |" << endl;
    cout << "|   Name: " << setw(40) << m_nguoimuonsach.get_ten() << " |" << endl;
    cout << "|   Mfg_Date: " << setw(36) << m_ngaymuonsach << " |" << endl;
    cout << "|   Exp_Date: " << setw(36) << m_ngayhethan << " |" << endl;
    cout << "|   " << setw(47) << "         Cac loai sach da muon: " << "|" << endl;
    for (int i = 0; i < pm_sosach; i++) {
        cout << "|   ID: " << setw(10) << m_sach[i].get_MaSach() <<
            setw(32) << m_sach[i].get_TenSach() << " |" << endl;
    }
    cout << "+--------------------------------------------------+" << endl;
    return;
}
bool Phieu::is_quaHan() {
    string today = "";
    cout << "Nhay ngay hom nay(yyyy/mm/dd): ";
    getline(cin, today);
    for (int i = 0; i < today.length(); i++) {
        if (today[i] > m_ngayhethan[i]) {
            // so sanh hai ngay voi nhau.
            return true;
        }
    }
    return false;
} // kiem tra phieu nay qua han tra hay chua;
void Phieu::traSach() {
    for (int i = 0; i < pm_sosach; i++) {
        m_sach[i].set_TongSoSach(m_sach[i].get_TongSoSach() + 1);
    }
    m_trangthai = false;
    return;
}
void Phieu::muonSach() {
    cout << "Ngay muon: ";
    getline(cin, m_ngaymuonsach);
    cout << "Ngay het han muon sach: ";
    getline(cin, m_ngayhethan);
    m_trangthai = true;
    return;
}
bool Phieu::get_trangthai() {
    return m_trangthai;
}
int Phieu::get_ID() {
    return m_IDphieu;
}

/*****************************************/

QuanlyThuVien::QuanlyThuVien() {
    m_dsSach = new Sach[MAX];
    m_phieu = new Phieu[MAX];
}
void QuanlyThuVien::ds_QuaHan() {
    cout << "+----------------Phieu Qua Han---------------------+" << endl << endl;
    for (int i = 0; i < pm_soluongPhieu; i++) {
        if (m_phieu[i].is_quaHan()) {
            m_phieu[i].inPhieu();
            cout << endl;
        }
    }
    cout << "+----------------------^---------------------------+" << endl;
    return;
}
void QuanlyThuVien::ds_Phieu() {
    cout << "+----------------Danh Sach Phieu-------------------+" << endl;
    for (int i = 0; i < pm_soluongPhieu; i++) {
        if (m_phieu[i].get_trangthai()) {
            m_phieu[i].inPhieu();
            cout << endl;
        }
    }
    cout << "+----------------------^---------------------------+" << endl;
    return;
}
void QuanlyThuVien::themPhieu(Phieu x) {
    m_phieu[pm_soluongPhieu] = x;
    pm_soluongPhieu++;
    return;
}
void QuanlyThuVien::ds_Sach() {
    for (int i = 0; i < pm_soluongSach; i++) {
        m_dsSach[i].inSach();
        cout << endl;
    }
    return;
}
void QuanlyThuVien::xoaSachRaKhoiHeThong(int x) {
    if (x < pm_soluongSach) {
        for (int i = x; i < pm_soluongSach - 1; i++) {
            m_dsSach[i] = m_dsSach[i + 1];
        }
        pm_soluongSach--;
    }
    else {
        cout << "Khong hop le! Xin vui long thu lai." << endl;
    }
    return;
}
void QuanlyThuVien::timSach() {
    int lc;
    string ts;
    bool found = false;
    int id;
    cout << "Tim theo: 1- Ten, 2-Id : ";
    cin >> lc;
    switch (lc) {
    case 1:
        cout << "Nhap ten sach can tim: ";
        getline(cin, ts);
        for (int i = 0; i < pm_soluongSach; i++) {
            if (m_dsSach[i].get_TenSach() == ts) {
                cout << "Da tim thay" << endl;
                m_dsSach[i].inSach();
                found = true;
                // co the co nhieu sach trung ten
            }
        }
        if (!found) {
            cout << "Khong tim thay sach co ten: " << ts << endl;
        }
        break;
    case 2:
        cout << "Nhap ten sach can tim: ";
        cin >> id;
        for (int i = 0; i < pm_soluongSach; i++) {
            if (m_dsSach[i].get_MaSach() == id) {
                cout << "Da tim thay" << endl;
                m_dsSach[i].inSach();
                // khong the co sach trung id cua nhau
                return;
            }
        }
        cout << "Khong tim thay sach co id " << id << endl;
    default:
        cout << "Lua chon khong hop le, xin thu lai." << endl;
        break;
    }
    return;
}
void QuanlyThuVien::themSachVaoHeThong(Sach& s) {
    if (pm_soluongSach < MAX) {
        m_dsSach[pm_soluongSach] = s;
        pm_soluongSach++;
        cout << "Da them: " << s.get_TenSach() << endl;
    }
    else cout << "Thu vien da day. Khong the them sach." << endl;
    return;
}
void QuanlyThuVien::themSachVaoHeThong(Sach* s, int n) {
    if (pm_soluongSach + n < MAX) {
        for (int i = 0; i < n; i++) {
            m_dsSach[pm_soluongSach] = s[i];
            pm_soluongSach++;
        }
    }
    else {
        cout << "Khong the them " << n << " cuon sach vi thu vien se day! \n";
    }
    return;
}
//----------------------Prototype-------------------------//
void thuVien(QuanlyThuVien& qltv);
void mpl_Phieu(QuanlyThuVien& qltv, int idp);
void nguoiDung(QuanlyThuVien& qltv, int id);
void ql_main();
///-------------------------------------------------------------------//

void thuVien(QuanlyThuVien& qltv) {
    string header[7] = {
        {"Tim sach.\n"}, {"Them sach vao he thong.\n"},
        {"Xoa sach ra khoi he thong.\n"}, {"Xem danh sach cac loai sach.\n"},
        {"Xem danh sach cac phieu muon.\n"}, {"Xem danh sach cac phieu muon da qua han.\n"},
        {"Dang ki the muon sach\n"},
    };
    int lc;
    Phieu phieumoi;
    Sach newSach;
    for (int i = 0; i < 7; i++) {
        cout << "[" << i + 1 << "]: " << header[i];
    }
    cin >> lc;
    cin.ignore();
    switch (lc) {
    case 1:
        qltv.timSach();
        break;
    case 2:
        newSach.nhapSach();
        qltv.themSachVaoHeThong(newSach);
        break;
    case 3:
        int id;
        cout << "Nhap so thu tu sach can xoa tren he thong: ";
        cin >> id;
        qltv.xoaSachRaKhoiHeThong(id);
        break;
    case 4:
        cout << "Danh sach cac loai sach co trong thu vien: \n\n";
        qltv.ds_Sach();
        break;
    case 5:
        qltv.ds_Phieu();
        break;
    case 6:
        cout << "Danh sach cac loai phieu muon da qua han: \n\n";
        qltv.ds_QuaHan();
        break;
    case 7:
        cout << "Dang ki phieu moi.\n";
        int lcn;
        cout << "[1]: Dang ki cho thanh vien moi.\n";
        cout << "[2]: Dang ki cho thanh vien cu.\n";
        cin >> lcn;
        cin.ignore();
        switch (lcn) {
        case 1:
            phieumoi.dangKi();
            qltv.themPhieu(phieumoi);
            cout << "\nDang ki thanh cong!\n";
            while (true) {
                mpl_Phieu(qltv, phieumoi.get_ID());
                int yon;
                cout << "Ban co muon tiep tuc? ([0]: NO, [1]: YES)";
                cin >> yon;
                if (!yon) {
                    cout << "Da thoat! \n";
                    return;
                }
            }
            break;
        case 2:
            cout << "Nhap ID cua ban: ";
            cin >> id;
            for (int i = 0; i < sln; i++) {
                if (mypeople[i].get_ID() == id) {
                    Phieu newP(mypeople[i]);
                    qltv.themPhieu(newP);
                    while (true) {
                        mpl_Phieu(qltv, newP.get_ID());
                        int yon;
                        cout << "Ban co muon tiep tuc? ([0]: NO, [1]: YES)";
                        cin >> yon;
                        if (!yon) {
                            cout << "Da thoat!\n";
                            return;
                        }
                    }
                    break;
                }
            }
            break;
        default:
            cout << "Lua chon khong hop le, xin vui long thu lai.\n";
            return;
        }
    default:
        cout << "Khong hop le, xin vui long thu lai.\n";
        break;
    }
    return;
}
void mpl_Phieu(QuanlyThuVien& qltv, int idp) {
    string header[5] = {
        {"Them sach.\n"},
        {"Xoa sach.\n"},
        {"In phieu.\n"},
        {"Tra sach.\n"},
        {"Muon sach.\n"},
    };
    bool check = false;
    for (int i = 0; i < qltv.pm_soluongPhieu; i++) {
        if (qltv.m_phieu[i].get_ID() == idp) {
            for (int j = 0; j < 5; j++) {
                cout << "[" << j + 1 << "]: " << header[j];
            }
            int lcp;
            cout << "Nhap lua chon: ";
            cin >> lcp;
            cin.ignore();
            switch (lcp) {
            case 1:
                int ids;
                cout << "Nhap id sach can them: ";
                cin >> ids;
                for (int k = 0; k < sls; k++) {
                    if (mybooks[k].get_MaSach() == ids) {
                        qltv.m_phieu[i].themSach(mybooks[k]);
                        check = true;
                        break;
                    }
                }
                if (!check) cout << "Khong tim thay sach hop le.\n";
                break;
            case 2:
                int lcs;
                cout << "Nhap so thu tu sach can xoa tren phieu.\n";
                cin >> lcs;
                qltv.m_phieu[i].xoaSach(lcs);
                break;
            case 3:
                qltv.m_phieu[i].inPhieu();
                break;
            case 4:
                qltv.m_phieu[i].traSach();
                cout << "Tra sach thanh cong.\n";
                break;
            case 5:
                qltv.m_phieu[i].muonSach();
                cout << "Muon sach thanh cong.\n";
                cout << "Han muon: " << qltv.m_phieu[i].m_ngayhethan << endl;
                break;
            default:
                cout << "Da thoat. \n";
                return;
            }
        }
    }
    return;
}
void nguoiDung(QuanlyThuVien& qltv, int id) {
    string header[4] = {
        {"Xem thong tin ca nhan\n"},
        {"Tao phieu muon moi.\n"},
        {"Sua doi phieu muon cu.\n"},
        {"Thoat.\n"}
    };
    for (int i = 0; i < sln; i++) {
        if (mypeople[i].get_ID() == id) {
            while (true) {
                for (int j = 0; j < 4; j++) {
                    cout << "[" << j + 1 << "]: " << header[j];
                }
                int lc;
                cout << "Lua chon cua ban: ";
                cin >> lc;
                Phieu newPhieu(mypeople[i]);
                switch (lc) {
                case 1:
                    mypeople[i].get_infor();
                    break;
                case 2:
                    cout << "Da tao mot phieu moi! \n\n";
                    qltv.themPhieu(newPhieu);
                    while (true) {
                        mpl_Phieu(qltv, newPhieu.get_ID());
                        int yon;
                        cout << "Ban co muon tiep tuc? ([0]: NO, [1]: YES)";
                        cin >> yon;
                        if (!yon) {
                            cout << "Da thoat!\n";
                            break;
                        }
                    }
                    break;
                case 3:
                    int idp;
                    cout << "Nhap id phieu cua ban: ";
                    cin >> idp;
                    while (true) {
                        mpl_Phieu(qltv, idp);
                        int yon;
                        cout << "Ban co muon tiep tuc? ([0]: NO, [1]: YES)";
                        cin >> yon;
                        if (!yon) {
                            cout << "Da thoat!\n";
                            break;
                        }
                    }
                default:
                    cout << "Da thoat.\n";
                    return;
                }
            }
        }
    }
    return;
}
void ql_main() {
    int lc;
    cout << "He thong quan ly thu vien xin chao \n";
    cout << "Ban la: \n";
    QuanlyThuVien(Sach);
    cout << "-- [1] : Nguoi quan ly thu vien.\n";
    cout << "-- [2] : Nguoi muon muon sach.\n";
    cin >> lc;
    switch (lc) {
    case 1:
        while (true) {
            thuVien(qltv);
            int yon;
            cout << "Ban co muon tiep tuc? ([0]: NO, [1]: YES)";
            cin >> yon;
            if (!yon) {
                cout << "Da thoat! \n";
                break;
            }
        }
        break;
    case 2:
        while (true) {
            int id;
            cout << "Nhap ma id cua ban: ";
            cin >> id;
            nguoiDung(qltv, id);
            int yon;
            cout << "Ban co muon tiep tuc? ([0]: NO, [1]: YES)";
            cin >> yon;
            if (!yon) {
                cout << "Da thoat!\n";
                break;
            }
        }
        break;
    default:
        cout << "Lua chon khong hop le. \n";
    }
    return;
}

int main() {
    qltv.themSachVaoHeThong(mybooks, sls);
    while (true) {
        ql_main();
    }
    return 0;
}