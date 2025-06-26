#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    // Lengkapi disini
    Dragon d("Draco");
    d.speak();
    d.wound();
    d.wound();
    d.print();
    d.speak();

    Creature* b = &d;
    b->wound();
    b->print();
    d.print();
    
    Creature c = d;
    c.speak();
    c.wound();
    c.print();

    d.print();

    return 0;
}