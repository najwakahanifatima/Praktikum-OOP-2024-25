#include "BunchofKeys.hpp"
#include <iostream>

using namespace std;

BunchOfKeys::BunchOfKeys(){
    this->n_keys = 0;
}

void BunchOfKeys::add() {
    this->n_keys++;
}

void BunchOfKeys::shake() {
    if (this->n_keys > 1) {
        cout << "krincing" << endl;
    } else {
        cout << "Tidak terjadi apa-apa" << endl;
    }
}

int main(){
    BunchOfKeys key;
    key.add();
    key.shake();

    key.add();
    key.shake();

    return 0;
}