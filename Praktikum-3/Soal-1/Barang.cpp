#include "Barang.hpp"


Barang::Barang(string nama, int berat){
    this->nama = nama;
    this->berat = berat;
}

Barang::~Barang(){}

string Barang::getNama() const {
    return this->nama;
}
int Barang::getBerat() const {
    return this->berat;
}