#include "Rekening.h"
#include <iostream>

Rekening::Rekening(){}

Rekening::Rekening(double saldo){
    if (saldo < 0){
        this->saldo = 0.0;
    } else {
        this->saldo = saldo;
    }
}

void Rekening::setSaldo(double s){
    this->saldo = saldo;
}

double Rekening::getSaldo() const {
    return saldo;
}

void Rekening::simpanUang(double s){
    saldo += s;
}

bool Rekening::tarikUang(double u){
    int sisa = saldo - u;
    if (sisa < 0){
        return false;
    } else {
        saldo -= u;
    }
    return true;
}
