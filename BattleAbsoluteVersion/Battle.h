#ifndef BATTLE_H
#define BATTLE_H
#include <iostream>
#include <cstdlib>
#include "Pokemon.h"

#include "Ability.h"
#include <vector>
#include "Team.h"

class Battle {

    Team pTeam;
    Team eTeam;

public:
    Battle(Team& pt, Team& et);
    Battle();
    void moveCalled(Move& attack);
    void enemyMove(Move& attack);
    void changePlayerPokemon(Pokemon& poke);
    void setswitchprio(int i);
    void randomEnemyMove();
    std::string getPlayerPokemon1();
    std::string getPlayerPokemon2();
    std::string getPlayerPokemon3();
    std::string getPlayerPokemon4();
    std::string getPlayerPokemon5();
    std::string getPlayerPokemon6();
    int getWhoWentFirst();
    std::string getEnemyPokemon();
    void addToreturnthing(QString s);
    int getpHP();
    int getswitchprio();
    int geteHP();
    int getpnHP(int x);

    int getenHP(int x);
    void useIt(HPBasedItem& i);
    std::vector<Move> getMoves();
    std::vector<Move> getEnemyMoves();

    void switchPokemon2();

    void switchPokemon3();

    void switchPokemon4();

    void switchPokemon5();

    void switchPokemon6();

    void eswitchPokemon();

    void turn(Move& emove);

    void playerFirst(Move& move, Move& emove);

    void enemyFirst(Move& move, Move& emove);

    void turn(Move& move, Move& emove);

    void dmgPlayer();

    Pokemon& getPlayer();
    QString getmovedone();
     QString getmovedoneP();
      QString getmovedoneE();
     Pokemon& givePoke();


};


#endif

