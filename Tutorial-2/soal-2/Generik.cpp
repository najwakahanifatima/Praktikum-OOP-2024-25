#include <iostream>

using namespace std;

template <class T>
void func(T param1, T param2){
    cout << "Masukan Anda: " << param1 << " dan " << param2 << ", memiliki tipe yang sama" << endl;
}

template <class T1, class T2>
void func(T1 param1, T2 param2){
    cout << "Masukan Anda: " << param1 << " dan " << param2 << ", mungkin memiliki tipe yang berbeda" << endl;
}

template<>
void func(char c, int n){
    for (int i = 0; i < n; i++){
        cout << c << endl;
    }
}

// int main() {
//     func(2, 3.0);
//     func('x', '1');
//     func('n', 10);

//     return 0;
// }