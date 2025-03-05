#include "Paper.hpp"
#include <iostream>

int main(){
    Paper a('A');
    Paper b('B');
    Paper c('C');
    Paper cc(c);
    a.fold();
    b.fold();
    c.fold();
    c.glue();
    c.setName('X');
    cc.fold();
    cc.glue();
    cc.fold();

    return 0;
}