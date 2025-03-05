#include "Kompleks.hpp"
#include <iostream>

using namespace std;

int Kompleks::n_kompleks = 0;

Kompleks::Kompleks(){
    this->real = 0;
    this->imaginer = 0;
    Kompleks:;n_kompleks++;
}

Kompleks::Kompleks(int real, int imaginer){
    this->real = real;
    this->imaginer = imaginer;
    Kompleks:;n_kompleks++;
}

int Kompleks::GetReal() const{
    return this->real;
}

int Kompleks::GetImaginer() const{
    return this->imaginer;
}

void Kompleks::SetReal(int real){
    this->real = real;
}

void Kompleks::SetImaginer(int imag){
    this->imaginer = imag;
}

Kompleks operator+ (const Kompleks  &x, const Kompleks &y){
    int real = x.GetReal() + y.GetReal();
    int imag = x.GetImaginer() + y.GetImaginer();
    Kompleks c(real, imag);
    return c;
}

Kompleks operator-(const Kompleks &x, const Kompleks &y){
    int real = x.GetReal() - y.GetReal();
    int imag = x.GetImaginer() - y.GetImaginer();
    Kompleks c(real, imag);
    return c;
}

Kompleks operator*(const Kompleks &x, const Kompleks &y){
    int real = (x.GetReal() * y.GetReal()) - (x.GetImaginer() * y.GetImaginer());
    int imag = (x.GetImaginer() * y.GetReal()) - (x.GetReal() * y.GetImaginer());
    Kompleks c(real, imag);
    return c;
}

Kompleks operator*(const Kompleks &x, const int i){
    int real = (x.GetReal() * i);
    int imag = (x.GetImaginer() * i);
    Kompleks c(real, imag);
    return c;
}

Kompleks operator*(const int i, const Kompleks &x){
    int real = (x.GetReal() * i);
    int imag = (x.GetImaginer() * i);
    Kompleks c(real, imag);
    return c;
}

int Kompleks::CountKompleksInstance(){
    return Kompleks::n_kompleks;
}

void Kompleks::Print(){
    cout << this->real;
    if (this->imaginer >= 0){
        cout << "+" << this->imaginer << 'i' << endl; 
    } else {
        cout << this->imaginer << 'i' << endl;
    }
}

int main(){
    Kompleks k1(3,5);
    Kompleks k2(0,0);
    Kompleks k3(-5,-4);

    Kompleks k4 = k1 + k3;
    Kompleks k5 = k1 - k5;
    Kompleks k6 = k1 * k3;

    k1.Print();
    k2.Print();
    k3.Print();
    k4.Print();
    k5.Print();
    k6.Print();

    return 0;
}