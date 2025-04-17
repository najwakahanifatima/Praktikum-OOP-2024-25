//File:Animal.cpp
#include <iostream>
using namespace std;
class Animal {
    public:
        virtual void greeting() = 0;
    };
class Cat: public Animal {
    public:
        void greeting() { cout << "Meow!" << endl; }
};
class Dog: public Animal {
    public:
        virtual void greeting() { cout << "Woof!" << endl;}
        void greeting(Dog another) { cout << "Woooooooooof!" << endl;}
    };
class BigDog: public Dog {
    public:
        void greeting() { cout << "Woww!" << endl; }
        void greeting(Dog another) { cout << "Wooooowwwww!" << endl;}
};
int main() {
    Cat cat1; cat1.greeting(); //(2.2) ....................
    Dog dog1; dog1.greeting(); //(2.3) ....................
    BigDog bigdog1; bigdog1.greeting(); //(2.4) ....................
    dog1 = bigdog1; dog1.greeting(); //(2.5) ....................
    BigDog bigdog2; dog1.greeting(bigdog2); //(2.6) ....................
    bigdog2.greeting(bigdog1); //(2.7) ....................
    // bigdog2 = dog1; bigdog2.greeting(); //(2.8) ....................
    return 0;
}