#include <iostream>

using namespace std;

#include <string>
#include <QDebug>
#include "Pokemon.h"
#include "Battle.h"
#include "Team.h"
#include <QTimer>

Battle::Battle(Team& pt, Team& et) : pTeam(pt), eTeam(et) {}
int first = 0;
int switchprio = 0; // if -1 that means enemy fainted, if 1 it means your pokemon fainted, if 0, the nyou just switch, if 3
QString returnthing = "";
QString returnPlayerMove = "";
QString returnEnemyMove = "";

void Battle::moveCalled(Move& attack) {
    Pokemon& player = pTeam.getPokemon1();
    Pokemon& enemy = eTeam.getPokemon1();
    std::cout << "In battle" << &enemy << std::endl;
    int random = rand() % 100 + 1;
    if (random < attack.getAccuracy()) {
        enemy.hit(player, attack);
        QString ename = QString::fromStdString(enemy.getPName());
        QString patt = QString::fromStdString(attack.getName());
        QString pname = QString::fromStdString(player.getPName());



            returnPlayerMove=  pname + " used " + patt + " on " + ename += "\n";



        qDebug() << enemy.getPRHP();

    }
    else{
        returnPlayerMove+= " Move Missed the Enemy \n";
    }
}

void Battle::enemyMove(Move& attack) {
    Pokemon& player = pTeam.getPokemon1();
    Pokemon& enemy = eTeam.getPokemon1();
    int random = rand() % 100 + 1;
    if (random < attack.getAccuracy()) {
        player.hit(enemy, attack);
        //qDebug() << QString::fromStdString(enemy.getPName()) << " used " << attack.getName() << " on " << QString::fromStdString(player.getPName()) << "!";
        QString ename = QString::fromStdString(enemy.getPName());
        QString eatt = QString::fromStdString(attack.getName());
        QString pname = QString::fromStdString(player.getPName());


            returnEnemyMove =  ename + " used " + eatt + " on " + pname + "\n";

        if(player.getPRHP() <= 0)
            switchprio = 1;
        std::cout << player.getPRHP() << std::endl;
    }
    else{
        returnEnemyMove+= "Move Missed the Player \n";
    }
}

void Battle::useIt(HPBasedItem& i){

    Pokemon& pt1 = pTeam.getPokemon1();
    pt1.setPRHP(pt1.getPRHP() + i.getRes());
}


Pokemon& Battle::givePoke(){
    Pokemon& pt1 = pTeam.getPokemon1();
    return pt1;
}

void Battle::addToreturnthing(QString s){
    returnthing+= s;
}

QString Battle::getmovedone(){
    //qDebug() << returnthing;
    //returnthing = "HELOOOOOOOOOOOOOOOOO";
    return returnthing;
}
QString Battle::getmovedoneP(){
    //qDebug() << returnthing;
    //returnthing = "HELOOOOOOOOOOOOOOOOO";
    return returnPlayerMove;
}
QString Battle::getmovedoneE(){
    //qDebug() << returnthing;
    //returnthing = "HELOOOOOOOOOOOOOOOOO";
    return returnEnemyMove;
}



void Battle::randomEnemyMove() {
    Pokemon& enemy = eTeam.getPokemon1();
    Move& attack = eTeam.getPokemon1().getMovesZZZ()[0];
    qDebug() << "here " << QString::fromStdString(attack.getName());
}

int Battle::getswitchprio(){

    return switchprio;
}



void Battle::changePlayerPokemon(Pokemon& poke) {
    Pokemon& player = pTeam.getPokemon1();
    player = poke;
}

std::string Battle::getPlayerPokemon1() {
    Pokemon& player = pTeam.getPokemon1();
    return player.getPName();
}
std::string Battle::getPlayerPokemon2() {
    return pTeam.getPokemon2().getPName();
}
std::string Battle::getPlayerPokemon3() {
    return pTeam.getPokemon3().getPName();
}
std::string Battle::getPlayerPokemon4() {
    return pTeam.getPokemon4().getPName();
}
std::string Battle::getPlayerPokemon5() {
    return pTeam.getPokemon5().getPName();
}
std::string Battle::getPlayerPokemon6() {
    return pTeam.getPokemon6().getPName();
}

std::string Battle::getEnemyPokemon() {
    Pokemon& enemy = eTeam.getPokemon1();
    return enemy.getPName();
}

int Battle::getpHP() {
    Pokemon& player = pTeam.getPokemon1();
    return player.getPRHP();
}

int Battle::geteHP() {
    Pokemon& enemy = eTeam.getPokemon1();
    return enemy.getPRHP();
}

std::vector<Move> Battle::getMoves() {
    Pokemon& player = pTeam.getPokemon1();
    return player.getMovesZZZ();
}

int Battle::getpnHP(int n) {
    if (n == 1) {
        if(pTeam.getPokemon1().getPRHP() <= 0)
            //switchprio = 1;
        return pTeam.getPokemon1().getPRHP();
    }
    if (n == 2) {
        if(pTeam.getPokemon2().getPRHP() <= 0)
            //switchprio = 1;
        return pTeam.getPokemon2().getPRHP();
    }
    if (n == 3) {
        if(pTeam.getPokemon3().getPRHP() <= 0)
           // switchprio = 1;
        return pTeam.getPokemon3().getPRHP();
    }
    if (n == 4) {
        if(pTeam.getPokemon4().getPRHP() <= 0)
            //switchprio = 1;
        return pTeam.getPokemon4().getPRHP();
    }
    if (n == 5) {
        if(pTeam.getPokemon5().getPRHP() <= 0)
           // switchprio = 1;
        return pTeam.getPokemon5().getPRHP();
    }
    if (n == 6) {
        if(pTeam.getPokemon6().getPRHP() <= 0)
           // switchprio = 1;
        return pTeam.getPokemon6().getPRHP();
    }
}

int Battle::getenHP(int n) {
    if (n == 1) {
        return eTeam.getPokemon1().getPRHP();
    }
    if (n == 2) {
        return eTeam.getPokemon2().getPRHP();
    }
    if (n == 3) {
        return eTeam.getPokemon3().getPRHP();
    }
    if (n == 4) {
        return eTeam.getPokemon4().getPRHP();
    }
    if (n == 5) {
        return eTeam.getPokemon5().getPRHP();
    }
    if (n == 6) {
        return eTeam.getPokemon6().getPRHP();
    }
    return 0;
}




std::vector<Move> Battle::getEnemyMoves() {
    Pokemon& enemy = eTeam.getPokemon1();
    return enemy.getMovesZZZ();
}

void Battle::switchPokemon2() {
    if(pTeam.getPokemon1().getPRHP() <= 0)
        switchprio = 4;
    else
        switchprio = 0;
    pTeam.switchPokemon2();



}

void Battle::switchPokemon3() {
    if(pTeam.getPokemon1().getPRHP() <= 0)
        switchprio = 4;
    else
        switchprio = 0;
    pTeam.switchPokemon3();
}

void Battle::switchPokemon4() {
    if(pTeam.getPokemon1().getPRHP() <= 0)
        switchprio = 4;
    else
        switchprio = 0;
    pTeam.switchPokemon4();

}

void Battle::switchPokemon5() {
    if(pTeam.getPokemon1().getPRHP() <= 0)
        switchprio = 4;
    else
        switchprio = 0;
    pTeam.switchPokemon5();
}

void Battle::switchPokemon6() {
    if(pTeam.getPokemon1().getPRHP() <= 0)
        switchprio = 4;
    else
        switchprio = 0;
    pTeam.switchPokemon6();

}

void Battle::eswitchPokemon() {
    Pokemon& player = pTeam.getPokemon1();
    Pokemon& enemy = eTeam.getPokemon1();
    if(eTeam.getPokemon2().getPRHP() > 0) {
        eTeam.switchPokemon2();
        switchprio = -1;
    }
    else if(eTeam.getPokemon3().getPRHP() > 0) {
        eTeam.switchPokemon3();
         switchprio = -1;
    }
    else if(eTeam.getPokemon4().getPRHP() > 0) {
        eTeam.switchPokemon4();
         switchprio = -1;
    }
    else if(eTeam.getPokemon5().getPRHP() > 0) {
        eTeam.switchPokemon5();
        switchprio = -1;
    }
    else if(eTeam.getPokemon6().getPRHP() > 0) {
        eTeam.switchPokemon6();
         switchprio = -1;
    }
}


void Battle::turn(Move& emove) {
    enemyMove(emove);
}


void Battle::setswitchprio(int i){
    switchprio = i;
}
int Battle::getWhoWentFirst(){
    return first;
}
void Battle::playerFirst(Move& move, Move& emove) {
    Pokemon& player = pTeam.getPokemon1();
    Pokemon& enemy = eTeam.getPokemon1();
    moveCalled(move);
        first = 1;
        switchprio = 3;
        if (enemy.getPRHP() > 0) {


            enemyMove(emove);
        }

}

void Battle::enemyFirst(Move& move, Move& emove) {
    Pokemon& player = pTeam.getPokemon1();
    Pokemon& enemy = eTeam.getPokemon1();

    enemyMove(emove);

    if (player.getPRHP() > 0) {

            moveCalled(move);
            //switchprio = 1;
            switchprio = 3;
    }
    else{
        switchprio = 1;
    }


   // delete mo;
    first = -1;

}


void Battle::turn(Move& move, Move& emove) {
    Pokemon& player = pTeam.getPokemon1();
    Pokemon& enemy = eTeam.getPokemon1();
    int pSpeed = player.getPSpeed();
    int eSpeed = enemy.getPSpeed();
    if (pSpeed > eSpeed) {
        playerFirst(move, emove);
    }
    else if (eSpeed > pSpeed) {
        enemyFirst(move, emove);
    }
    else {
        int first = rand() % 2 + 1;
        if (first == 1) {
            playerFirst(move, emove);
        }
        else {
            enemyFirst(move, emove);
        }
    }
}

void Battle::dmgPlayer() {
    Pokemon& player = pTeam.getPokemon1();
    //player.applyDamage(0);
}

Pokemon& Battle::getPlayer() {
    Pokemon& player = pTeam.getPokemon1();
    return player;
}
