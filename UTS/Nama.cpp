#include <string>
#include "Exception.cpp"
#include <iostream>

#include <vector>

using namespace std;
class Nama {
    private:
        string depan;
        string belakang;
        string tengah;
        int static num;

    public:
        Nama(const Nama& n){
            this->depan = n.depan;
            this->belakang = n.belakang;
            this->tengah = n.tengah;
        }
        Nama& operator=(const Nama& n){
            depan = n.depan;
            belakang = n.belakang;
            tengah = n.tengah;
            return *this;
        }
        ~Nama();

        void static process(int n){
            try {
                if(n == 0) {
                    throw KapasitasPenuhException();
                } else if (n == 1){
                    throw BarangKedaluwarsaException();
                }
            }
            catch (KapasitasPenuhException& e) {
                cerr << e.what() << endl;
            }catch (BarangKedaluwarsaException& e) {
                cerr << e.what() << endl;
            }
        }
};

int main(){
    Nama::process(0);
    vector<int> v = {'a','b','c'};    



    return 0;
}