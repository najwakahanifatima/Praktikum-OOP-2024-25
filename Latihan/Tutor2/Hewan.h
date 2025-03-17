#ifndef HEWAN_H
#define HEWAN_H

#include <iostream>

using namespace std;

class Hewan {
    protected:
        string nama;
    public:
        Hewan(){}
        Hewan(string nama){
            this->nama = nama;
        }
        ~Hewan() {
            cout << "Hewan mati " << nama << endl;
        }
        virtual void print(){
            cout << "Hewan ini namanya " << nama << endl;
        }

};

class Anjing : public Hewan {
    public:
        Anjing(){}
        Anjing(string nama) : Hewan(nama){}
        ~Anjing() {
            cout << "Anjing mati " << nama << endl;
        }
        virtual void print(){
            cout << "Anjing ini namanya " << nama << endl;
        }
};

class Kucing : public Hewan {
    public:
        Kucing(){}
        Kucing(string nama) : Hewan(nama){}
        ~Kucing() {
            cout << "Kucing mati " << nama << endl;
        }
        virtual void print(){
            cout << "Kucing ini namanya " << nama << endl;
        }
};

class KucingAnggora : public Kucing {
    protected:
        string pemilik;
    public:
        KucingAnggora(string namaH, string namaP){
            nama = namaH;
            pemilik = namaP;
        }
        ~KucingAnggora(){
            cout << "Kucing anggora mati " << nama << endl;
        }
        void print(){
            cout << "Kucing anggora ini namanya " << nama << endl;
        }
};

class AnjingBulldog : public Anjing {
    protected:
        string pemilik;
    public:
        AnjingBulldog(string namaH, string namaP){
            nama = namaH;
            pemilik = namaP;
        }
        ~AnjingBulldog(){
            cout << "Kucing anggora mati " << nama << endl;
        }
        void print(){
            cout << "Kucing anggora ini namanya " << nama << endl;
        }
};

#endif 