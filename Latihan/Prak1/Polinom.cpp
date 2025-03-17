#include "Polinom.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Polinom::Polinom(){
    derajat = 0;
    koef = new int[derajat+1];
    koef[0] = 0;
}

Polinom::Polinom(int n){
    derajat = n;
    koef = new int[derajat+1];
    for (int i = 0; i < derajat+1; i++){
        koef[i] = 0;
    }
}

Polinom::Polinom(const Polinom& p){
    derajat = p.derajat;
    koef = new int[derajat+1];
    for(int i = 0; i < derajat + 1; i++){
        koef[i] = p.koef[i];
    }
}

Polinom::~Polinom(){
    delete[] this->koef;
}

Polinom& Polinom::operator=(const Polinom& p){
    derajat = p.derajat;
    delete[] this-> koef;
    koef = new int[derajat+1];
    for(int i = 0; i < derajat + 1; i++){
        koef[i] = p.koef[i];
    }
    return *this;
}

int Polinom::getKoefAt(int idx) const {
    return this->koef[idx];
}

int Polinom::getDerajat() const {
    return this->derajat;
}

void Polinom::setKoefAt(int idx, int val){
    koef[idx] = val;
}

void Polinom::setDerajat(int n){
    this->derajat = n;
}

void Polinom::input(){
    for(int i = 0; i < derajat+1; i++){
        cin >> koef[i];
    }
}

void Polinom::printKoef(){
    for(int i = 0; i < derajat+1; i++){
        cout << koef[i] << endl;
    }
}

int Polinom::substitute(int x){
    int res = 0;
    for(int i = 0; i < derajat + 1; i++){
        res += (koef[i] * pow(x, i));
    }
    return res;
}

void Polinom::print(){
    bool isZero = true;
    for(int i = 0; i < derajat+1; i++){
        if (koef[i] < 0){
            i == 0 ? cout << "-" << koef[i] : cout << "-" << koef[i] << "x^" << i;
            isZero = 0;
        } else if (koef[i] > 0){
            i == 0 ? cout << koef[i] : cout << "+" << koef[i] << "x^" << i;
            isZero = 0;
        } else if (isZero && i == derajat){
            cout << 0;
        }
    }
}

