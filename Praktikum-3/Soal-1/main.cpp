#include <iostream>
using namespace std;

class A {
    protected:
        int x = 0;
    public:
        A(){
            cout << "Buat A" << endl;
        }
        A(int _x) : x(_x) {
            cout << "Buat A cc" << endl;
        }
        virtual void print(){
            cout << "Print A x: " << x << endl;
        }
        virtual void print2(){
            cout << "yes A" << endl;
        }
};

class B : public A {
    private:
        int y = 0;
    public:
        B(){
            cout << "Buat B" << endl;
        };
        B(int _y) : y(_y){
            cout << "Buat B cc" << endl;
        }
        void print(){
            cout << "Print B x: " << x << endl;
            cout << "Print B y: " << y << endl;
        }
        void addX(){
            x++;
            cout << "x to: " << x << endl; 
        }
        void print2(){
            cout << "no B" << endl;
        }
};

int main(){
    A a(2); //Buat A cc
    B b(3); //Buat A \n Buat B cc --- still makes base class
    a.print2();
    b.print2();
    cout << endl;

    a.print(); //Print A x: 2
    b.print(); //Print B x: 0 \n Print B y: 3
    cout << endl;

    A& c = b;
    c.print(); //Print B x: 0 \n Print B y: 3
    b.addX(); //x to: 1
    c.print2();
    cout << endl;

    A d = b; // atributnya cuma yg dari skema A, tpi isinya punya B
    d.print(); //Print A x: 1
    c.print2();
    cout << endl;

    A* e = &b; //Print B x: 1 \n Print B y: 3
    e->print();
    e->print2();
    cout << endl;

    return 0;
}