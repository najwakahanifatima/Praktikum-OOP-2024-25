#include <iostream>
#include <cmath>

using namespace std;

template <class T1, class T2>
class KeyValue{
    private:
        T1 keys[10];
        T2 values[10];
        int count;
    public:
        KeyValue(){
            count = 0;
        }
        ~KeyValue(){}
        void set(T1 key, T2 value){
            if (count == 10){ //penuh
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            } else {
                int i = 0; bool found = false;
                while (i < 10 && !found){
                    if (keys[i] == key){
                        values[i] = value;
                        found = true;
                    }
                    i++;
                }
                if (!found){
                    keys[count] = key;
                    values[count] = value;
                    count++;
                }
            }
        }
        void display(T1 key){
            int i = 0; bool found = false; int counter = 0;
            while (i < 10 && !found){
                if (keys[i] == key){
                    cout << values[i] << endl;
                    found = true;
                }
                i++;
            }
            if (i == 10){
                cout << "Key tidak ditemukan!" << endl;
            }
        }
};

template <class T2>
class KeyValue<double, T2>{
    private:
        double keys[10];
        T2 values[10];
        int count;
    public:
        KeyValue(){
            count = 0;
        }
        ~KeyValue(){}
        void set(double key, T2 value){
            if (count == 10){ //penuh
                cout << "KeyValue penuh! Tidak bisa menambahkan KeyValue lagi." << endl;
            } else {
                int i = 0; bool found = false;
                while (i < 10 && !found){
                    if (abs(keys[i] - key) < 0.01){
                        values[i] = value;
                        found = true;
                    }
                    i++;
                }
                if (!found){
                    keys[count] = key;
                    values[count] = value;
                    count++;
                }
            }
        }
        void display(double key){
            int i = 0; bool found = false; int counter = 0;
            while (i < 10 && !found){
                if (abs(keys[i] - key) < 0.01){
                    cout << values[i] << endl;
                    found = true;
                }
                i++;
            }
            if (i == 10){
                cout << "Key tidak ditemukan!" << endl;
            }
        }
};

// int main(){
//     KeyValue<double, string> kv;
//     kv.set(1.01, "Alice");
//     kv.set(2.02, "Bob");
//     kv.set(3, "Charlie");
//     kv.display(1.012); // Output: "Alice"
//     kv.display(1.02); // Output: "Bob"
//     kv.display(2.02); // Output: "Charlie"
// }
