#include "Paper.hpp"
#include <iostream>

using namespace std;

int main() {
    Paper a('A');
    Paper b('B');
    Paper c('C');
    Paper d(c);
    a.fold();
    b.fold();
    c.fold();
    c.glue();
    c.setName('X');
    d.fold();
    d.glue();
    return 0;
}