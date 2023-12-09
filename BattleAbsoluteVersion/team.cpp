#include "Team.h"
#include <QDebug>

Team::Team(Pokemon& poke1, Pokemon& poke2, Pokemon& poke3, Pokemon& poke4, Pokemon& poke5, Pokemon& poke6) : pokemon1(poke1), pokemon2(poke2), pokemon3(poke3), pokemon4(poke4), pokemon5(poke5), pokemon6(poke6) {}
Team::Team(){

}

Pokemon& Team::getPokemon1() {
    return pokemon1;
}

Pokemon& Team::getPokemon2() {
    return pokemon2;
}

Pokemon& Team::getPokemon3() {
    return pokemon3;
}

Pokemon& Team::getPokemon4() {
    return pokemon4;
}

Pokemon& Team::getPokemon5() {
    return pokemon5;
}

Pokemon& Team::getPokemon6() {
    return pokemon6;
}

void Team::switchPokemon2() {
    qDebug() << "Switched" << pokemon1.getPName() << "with" << pokemon2.getPName();
    std::swap(pokemon1, pokemon2);
}

void Team::switchPokemon3() {
    qDebug() << "Switched" << pokemon1.getPName() << "with" << pokemon3.getPName();

    std::swap(pokemon1, pokemon3);
}

void Team::switchPokemon4() {
    qDebug() << "Switched" << pokemon1.getPName() << "with" << pokemon4.getPName();

    std::swap(pokemon1, pokemon4);
}


void Team::switchPokemon5() {
    qDebug() << "Switched" << pokemon1.getPName() << "with" << pokemon5.getPName();

    std::swap(pokemon1, pokemon5);
}


void Team::switchPokemon6() {
    qDebug() << "Switched" << pokemon1.getPName() << "with" << pokemon6.getPName();

    std::swap(pokemon1, pokemon6);
}
