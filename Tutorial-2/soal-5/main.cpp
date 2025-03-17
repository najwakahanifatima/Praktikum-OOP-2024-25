#include "Pokemon.hpp"
#include "FirePokemon.hpp"
#include "GrassPokemon.hpp"
#include "WaterPokemon.hpp"
#include <iostream>

using namespace std;

int main(){

    // std::cout << "------------------------" << std::endl;

    FirePokemon* f11 = new FirePokemon("Charmander", 100, 20);
    FirePokemon* f21 = new FirePokemon(*f11);

    WaterPokemon* w11 = new WaterPokemon("Squirtle", 100, 20, 10);
    w11->heal(10);
    WaterPokemon* w21 = new WaterPokemon("Magikarp", 100, 20, 0);
    *w21 = *w11;

    w11->attack(*f11);
    w11->attack(*f11);

    delete f11;
    delete w11;

    return 0;
}