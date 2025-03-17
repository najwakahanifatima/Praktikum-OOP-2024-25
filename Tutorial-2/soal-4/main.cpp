#include "Pokemon.hpp"
#include "FirePokemon.hpp"
#include "GrassPokemon.hpp"
#include "WaterPokemon.hpp"
#include <iostream>

using namespace std;

int main() {
    FirePokemon c("Charmander", 100, 20);
    WaterPokemon s("Squirtle", 100, 20, 10);
    s.heal(10);
    s.attack(c);
    c.attack(s);
    s.attack(c);
    GrassPokemon b("Bulbasaur", 100, 50, 20);
    s.attack(b);
    b.attack(s);
    
    return 0;
}