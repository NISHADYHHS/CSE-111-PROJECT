#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include "Pokemon.h"
#include <vector>

class Pokemon;

class Team {
private:
    Pokemon pokemon1;
    Pokemon pokemon2;
    Pokemon pokemon3;
    Pokemon pokemon4;
    Pokemon pokemon5;
    Pokemon pokemon6;

public:
    Team(Pokemon& poke1, Pokemon& poke2, Pokemon& poke3, Pokemon& poke4, Pokemon& poke5, Pokemon& poke6);
    Team();
    Pokemon &getPokemon1();
    Pokemon &getPokemon2();
    Pokemon &getPokemon3();
    Pokemon &getPokemon4();
    Pokemon &getPokemon5();
    Pokemon &getPokemon6();
    void switchPokemon();

    void switchPokemon2();

    void switchPokemon3();

    void switchPokemon4();

    void switchPokemon5();

    void switchPokemon6();

};


#endif
