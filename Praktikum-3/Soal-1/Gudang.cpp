#include "BarangElektronik.hpp"
#include "BarangMakanan.hpp"
#include "Gudang.hpp"
#include "Exception.hpp"
#include <iostream>
using namespace std;

    // vector<Barang *> daftarBarang;
    // int kapasitasTotal; // kapasitas maksimum dalam kg
    // int kapasitasTerpakai;
    // int tenagaKerja; // jumlah pekerja yang tersedia
    // int uang;  

/*
        Membuat objek Gudang dengan kapasitas, uang, tenaga kerja default.
    */
    Gudang::Gudang(){
        kapasitasTotal = DEFAULT_KAPASITAS;
        kapasitasTerpakai = 0;
        tenagaKerja = DEFAULT_TENAGA_KERJA;
        uang = DEFAULT_UANG;
    }

    /*
        Membuat objek Gudang dengan kapasitas, uang, tenaga kerja sesuai argumen.
    */
    Gudang::Gudang(int kapasitas, int uang, int tenagaKerja){
        kapasitasTotal = kapasitas;
        kapasitasTerpakai = 0;
        this->uang = uang;
        this->tenagaKerja = tenagaKerja;
    }

    /*
        Menghancurkan Gudang. Pastikan semua pointer barang dihapus (delete).
    */
    Gudang::~Gudang() {}

    /*
        Menambahkan barang ke dalam gudang.
        - Setiap barang membutuhkan:
            kapasitas = berat barang
            uang = 100 per barang
            1 tenaga kerja

        - Jika barang makanan dan sudah kedaluwarsa (hariKedaluwarsa <= 0), lempar BarangKedaluwarsaException, dan tampilkan pesan: "Barang makanan sudah kadaluwarsa, buang dulu."
        - Jika kapasitas tidak cukup, lempar KapasitasPenuhException, tampilkan: "Kapasitas tidak cukup, perluas gudang dulu."
        - Jika uang tidak cukup, lempar UangTidakCukupException, tampilkan: "Uang tidak cukup, cari pemasukan dulu."
        - Jika tidak ada tenaga kerja, lempar TenagaKerjaTidakCukupException, tampilkan: "Tidak ada tenaga kerja, rekrut dulu."

        - Jika gagal, sumber daya tidak berkurang.

        - Jika berhasil, barang ditambahkan dan tampilkan:
          "Barang [<index>] <nama> berhasil disimpan"

        - Index dimulai dari 0
        - Gunakan dynamic cast untuk mendapatkan kadaluarsa dari BarangMakanan
        contoh: Class *x = dynamic_cast<Class *>(input)

        (semua output diakhiri newline)
    */
    void Gudang::simpanBarang(Barang *barang){
        try {
            if (barang->getJenis() == "Makanan") {
                BarangMakanan* bm = dynamic_cast<BarangMakanan *>(barang);
                if (bm && bm->getHariKedaluwarsa() <= 0){
                    throw(BarangKedaluwarsaException());
                }
                pakaiKapasitas(barang->getBerat());
                pakaiUang(100);
                pakaiTenagaKerja();

                daftarBarang.push_back(barang);
                cout << "Barang [" << daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;
            } else {
                BarangElektronik* be = dynamic_cast<BarangElektronik *>(barang);
                pakaiKapasitas(barang->getBerat());
                pakaiUang(100);
                pakaiTenagaKerja();

                daftarBarang.push_back(barang);
                cout << "Barang [" << daftarBarang.size() - 1 << "] " << barang->getNama() << " berhasil disimpan" << endl;
            }
        } catch (BarangKedaluwarsaException& e) {
            cout << e.what() << ", buang dulu." << endl;
            return;
        } catch (KapasitasPenuhException& e) {
            cout << e.what() << ", perluas gudang dulu." << endl;
            return;
        } catch (UangTidakCukupException& e) {
            kapasitasTerpakai -= barang->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
            return;
        } catch (TenagaKerjaTidakCukupException& e) {
            kapasitasTerpakai -= barang->getBerat();
            uang += 100;
            cout << e.what() << ", rekrut dulu." << endl;
            return;
        }
    }

    /*
        Menambahkan kapasitas gudang
    */
    void Gudang::tambahKapasitas(int kg){
        kapasitasTotal += kg;
    }

    /*
        Menambahkan tenaga kerja
    */
    void Gudang::tambahTenagaKerja(int jumlah){
        tenagaKerja += jumlah;
    }

    /*
        Menambahkan uang
    */
    void Gudang::tambahUang(int jumlah){
        uang += jumlah;
    }

    /*
        Menggunakan kapasitas (lempar KapasitasPenuhException jika tidak cukup)
    */
    void Gudang::pakaiKapasitas(int kg){
        if (kg + kapasitasTerpakai > kapasitasTotal){
            throw (KapasitasPenuhException());
        }
        kapasitasTerpakai += kg;
    }

    /*
        Menggunakan uang (lempar UangTidakCukupException jika tidak cukup)
    */
    void Gudang::pakaiUang(int jumlah){
        if (jumlah > uang) {
            throw(UangTidakCukupException());
        }
        uang -= jumlah;
    }

    /*
        Menggunakan tenaga kerja (1 pekerja), lempar TenagaKerjaTidakCukupException jika tidak cukup
    */
    void Gudang::pakaiTenagaKerja(){
        if (tenagaKerja == 0){
            throw(TenagaKerjaTidakCukupException());
        }
        tenagaKerja--;
    }

    /*
        Menyebut barang di index tertentu. Tampilkan:
        "<nama> - <jenis> - <berat>kg"

        Jika index tidak valid, tampilkan exception bawaan C++ diakhiri newline.
    */
    void Gudang::sebutBarang(int idx){
        try {
            Barang* barang = daftarBarang.at(idx);
            cout << barang->getNama() << " - " << barang->getJenis() << " - " << barang->getBerat() << "kg" << endl;
        } catch (const out_of_range& e){
            cout << e.what() << endl;
            return;
        }
    }

    /*
        Menampilkan status gudang seperti:

        Status gudang:
          Kapasitas total: <kapasitasTotal> kg
          Kapasitas terpakai: <kapasitasTerpakai> kg
          Uang: <uang>
          Tenaga kerja: <tenagaKerja>
          Barang:
            [0] <nama> - <jenis> - <berat>kg
            ...
    */
    void Gudang::statusGudang() const{
        cout << "Status gudang:" << endl;
        cout << "  Kapasitas total: " << kapasitasTotal << " kg" << endl;
        cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg" << endl;
        cout << "  Uang: " << uang << endl;
        cout << "  Tenaga kerja: " << tenagaKerja << endl;
        cout << "  Barang:" << endl;
        for (int i = 0; i < daftarBarang.size() ; i++){
            cout << "    [" << i << "] ";
            Barang* barang = daftarBarang.at(i);
            cout << barang->getNama() << " - " << barang->getJenis() << " - " << barang->getBerat() << "kg" << endl;
        }
    }


// int main(){
//     BarangElektronik e1("e1", 21, 1);
//     BarangElektronik e2("e2", 22, 2);
//     BarangElektronik e3("e3", 23, 3);
//     BarangMakanan m1("m1", 31, 1);
//     BarangMakanan m23("m23", 23, 2);
//     BarangMakanan m2("m2", 32, -9);

//     Gudang g;
//     g.simpanBarang(&e1);
//     g.simpanBarang(&e2);
//     g.simpanBarang(&e3);
//     g.simpanBarang(&m1);
//     g.simpanBarang(&m23);
//     g.simpanBarang(&m2);

//     g.sebutBarang(6);

//     g.statusGudang();


//     return 0;
// }