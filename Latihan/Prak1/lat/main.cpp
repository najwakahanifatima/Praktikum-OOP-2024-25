#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int &xr = x;
    int *xp;

    float y = 2.3;

    xp = &xr;

    cout << y << endl;
    cout << int(y) << endl;

    // cout << "before xr " << xr << endl;
    // cout << "before xp " << *xp << endl;

    // xr ++;

    // cout << "after x " << x << endl;
    // cout << "after xp " << *xp << endl;



    return 0;
} 