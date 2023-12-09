#include <iostream>

using namespace std;
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <string>
#include "Pokemon.h"
#include "move.h"
#include <stdio.h>
#include "Ability.h"

Pokemon::Pokemon(int id, std::string name, int level, std::string item,
                 std::string type1, std::string type2, double height, double weight,
                 std::string ability, std::string gender, int HP, int attack, int defense,
                 int special_attack, int special_defense, int speed, std::vector<Move> moves) :
    p_id(id), p_name(name), p_level(level), p_item(item), p_type1(type1), p_type2(type2), p_height(height), p_weight(weight),
    p_ability(ability), p_gender(gender), p_HP(setHP(HP, level)), p_Attack(setStat(attack, level)), p_Defense(setStat(defense, level)), p_SpecialAttack(setStat(special_attack, level)),
    p_SpecialDefense(setStat(special_defense, level)), p_Speed(setStat(speed, level)), p_moves(moves), p_rhp(setHP(HP, level)) {
    // Constructor initialization
    //qDebug() << "pokemon made";
    QSqlDatabase pokemondb = QSqlDatabase::addDatabase("QSQLITE");
    pokemondb.setDatabaseName("C:/Users/nishb/Downloads/ActualFinalver/FINALVERSIONOFCSE111/Updated Updated Website/Django/mysite/pokemon.db");
    if(pokemondb.open())
        qDebug() << "Open";
    else
        qDebug() << "Closed";
}

Pokemon::Pokemon(int id, std::string name, int level, std::string item,
                 std::string type1, std::string type2, double height, double weight,
                 std::string ability, std::string gender, int HP, int attack, int defense,
                 int special_attack, int special_defense, int speed, std::vector<Move> moves, int r) :
    p_id(id), p_name(name), p_level(level), p_item(item), p_type1(type1), p_type2(type2), p_height(height), p_weight(weight),
    p_ability(ability), p_gender(gender), p_HP(setHP(HP, level)), p_Attack(setStat(attack, level)), p_Defense(setStat(defense, level)), p_SpecialAttack(setStat(special_attack, level)),
    p_SpecialDefense(setStat(special_defense, level)), p_Speed(setStat(speed, level)), p_moves(moves), p_rhp(r) {
    // Constructor initializatio
}


Pokemon::Pokemon(const Pokemon& other) :
    p_id(other.p_id), p_name(other.p_name), p_level(other.p_level), p_item(other.p_item),
    p_type1(other.p_type1), p_type2(other.p_type2), p_height(other.p_height), p_weight(other.p_weight),
    p_ability(other.p_ability), p_gender(other.p_gender), p_HP(other.p_HP), p_Attack(other.p_Attack),
    p_Defense(other.p_Defense), p_SpecialAttack(other.p_SpecialAttack), p_SpecialDefense(other.p_SpecialDefense),
    p_Speed(other.p_Speed), p_moves(other.p_moves), p_rhp(other.p_rhp) {
    // Deep copy of moves vector
    for (const auto& move : other.p_moves) {
        p_moves.push_back(move);
    }
   // qDebug() << "copy made" ;
    qDebug() << (*this).getPRHP();
}

void Pokemon::useItem(HPBasedItem& i){
    setPRHP(getPRHP() + i.getRes());
}
int Pokemon::setHP(int stat, int lv) {
    return (2 * stat * lv) / 100 + lv + 10;
}

int Pokemon::getPId(){ return p_id; }
void Pokemon::setPId(int id) { p_id = id; }

std::string Pokemon::getPName()  { return p_name; }
void Pokemon::setPName( std::string name) { p_name = name; }

int Pokemon::getPLevel()  { return p_level; }
void Pokemon::setPLevel(int level) { p_level = level; }

std::string Pokemon::getPItem()  { return p_item; }
void Pokemon::setPItem( std::string item) { p_item = item; }

std::string Pokemon::getPType1()  { return p_type1; }
void Pokemon::setPType1( std::string type1) { p_type1 = type1; }

std::string Pokemon::getPType2()  { return p_type2; }
void Pokemon::setPType2( std::string type2) { p_type2 = type2; }

double Pokemon::getPHeight()  { return p_height; }
void Pokemon::setPHeight(double height) { p_height = height; }

double Pokemon::getPWeight()  { return p_weight; }
void Pokemon::setPWeight(double weight) { p_weight = weight; }

std::string Pokemon::getPAbility()  { return p_ability; }
void Pokemon::setPAbility( std::string ability) { p_ability = ability; }

std::string Pokemon::getPGender()  { return p_gender; }
void Pokemon::setPGender( std::string gender) { p_gender = gender; }

int Pokemon::getPHP()  { return p_HP; }
void Pokemon::setPHP(int hp) { p_HP = setHP(hp,getPLevel());p_rhp = setHP(hp,getPLevel()); }

int Pokemon::getPAttack()  { return p_Attack; }
void Pokemon::setPAttack(int attack) { p_Attack = setStat(attack, getPLevel()); }

int Pokemon::getPDefense()  { return p_Defense; }
void Pokemon::setPDefense(int defense) { p_Defense  = setStat(defense, getPLevel()); }

int Pokemon::getPSpecialAttack()  { return p_SpecialAttack; }
void Pokemon::setPSpecialAttack(int specialAttack) { p_SpecialAttack = setStat(specialAttack, getPLevel()); }

int Pokemon::getPSpecialDefense()  { return p_SpecialDefense; }
void Pokemon::setPSpecialDefense(int specialDefense) { p_SpecialDefense  = setStat(specialDefense, getPLevel()); }

int Pokemon::getPSpeed()  { return p_Speed; }
void Pokemon::setPSpeed(int speed) { p_Speed = setStat(speed, getPLevel()); }

int Pokemon::getPRHP()  { return p_rhp; }
void Pokemon::setPRHP(int rhp) { p_rhp = rhp; }

Pokemon::Pokemon(){
    p_id = 0;
    p_name = "";
    p_level = 0;
    p_item = "";
    p_type1 = "";
    p_type2 = "";
    p_level = 0;
    p_height = 0;
    p_weight = 0;
    p_ability = "";
    p_gender = "";
    p_HP = 0;
    p_Attack = 0;
    p_Defense = 0;
    p_SpecialAttack = 0;
    p_SpecialDefense = 0;
    p_Speed = 0;
    p_rhp = 0;
    std::vector<Move> v;
    p_moves = v;
}
Pokemon::~Pokemon(){
    //cout << "destroyed" << (*this).getPName() << ": " << (*this).getPRHP() ;

}

void Pokemon::setMoves(std::vector<Move> moves){

    p_moves = moves;
}


int Pokemon::getHP(int stat, int lv) {
    return (2 * stat * lv) / 100 + lv + 10;
}

int Pokemon::getStat(int stat, int lv) {
    return (2 * stat * lv) / 100 + 5;
}

void Pokemon::applyDamage(int dmg) {
    qDebug() << "In apply damage" << &*this;
    qDebug() << p_HP;
    p_rhp -= dmg;
    qDebug() << p_HP;
}
vector<Move> Pokemon::getMovesZZZ(){

    return p_moves;
}

int Pokemon::setStat(int stat, int lv) {
    return (2 * stat * lv) / 100 + 5;
}

void Pokemon::addMove(Move move){

    int count = 0;
    for(Move m: p_moves){
        count++;
    }
    if(count < 5){
        p_moves.push_back(move);

    }

}

int Pokemon::calculateDamage(Pokemon attacker, Move& move) {
    // Calculate damage based on move power, attacker's stats, attacked Pokemon's stats, etc.
    // This can be a complex calculation involving various factors
    // For simplicity, let's assume a basic calculation here
    QSqlDatabase pokemondb = QSqlDatabase::addDatabase("QSQLITE");
    pokemondb.setDatabaseName("C:/Users/nishb/Downloads/ActualFinalver/FINALVERSIONOFCSE111/Updated Updated Website/Django/mysite/pokemon.db");
    if(pokemondb.open())
        qDebug() << "Open";
    else
        qDebug() << "Closed";


    int atkStat;
    int defStat;
    if (move.getCategory() == "Physical") {
        atkStat = attacker.getPAttack();
        defStat = this->getPDefense();
    }
    else {
        atkStat = attacker.getPSpecialAttack();
        defStat = this->getPSpecialDefense();
    }


    float stab = 1;
    if (attacker.p_type1 == move.getType()) {
        if (attacker.p_ability != "Adaptability") {
            stab = 1.5;
        }
        else {
            stab = 2;
        }
    }
    else {
        if (attacker.p_type2 == move.getType()) {
            if (attacker.p_ability != "Adaptability") {
                stab = 1.5;
            }
            else {
                stab = 2;
            }
        }
    }
    BaseAbility* ability = new HPBasedBoost(attacker.getPType1(), move);
    ability->useAbility(attacker);

    double effectiveness = 1.0; // Assume no type effectiveness for now

    QSqlQuery effective;
    effective.prepare("select type_name from Type where type_id in (select w_weakness from Weakness inner join Type ON Type.type_id = Weakness.w_id  where Type.type_name = (:type)) ");
    effective.bindValue(":type", QString::fromStdString(getPType1()));

    //effective.bindValue(":movename", move.getType().c_str());
    //int moveid = moveIDs.record().indexOf("m_id");
    //qDebug() << (moveid) << movename;
    QString id;
    if (effective.exec())
    {
        while (effective.next())
        {
            id = effective.value(0).toString();
           // qDebug() << "type: " << getPType1() << "Check Weak 1" << id ;

            if (move.getType() == id.toStdString()) {
                 //qDebug() <<"This is super very effective: "  << move.getType();
                effectiveness *= 2;
            }
        }
    }


    QSqlQuery effective2;
    effective2.prepare("select type_name from Type where type_id in (select r_resistane from Resistance inner join Type ON Type.type_id = Resistance.r_id where Type.type_name = (:type))");
    effective2.bindValue(":type", QString::fromStdString(getPType1()));
    //effective.bindValue(":movename", move.getType().c_str());
    //int moveid = moveIDs.record().indexOf("m_id");
    //qDebug() << (moveid) << movename;
    if (effective2.exec())
    {
        while (effective2.next())
        {

            id = effective2.value(0).toString();
            //qDebug() << "type: " << getPType2() << "Check Res 1" << id ;
            //qDebug() << (id);
            if (move.getType() == id.toStdString()) {
               // qDebug()<< "type: " << getPType1() << "This is not very effective: "  << move.getType();
                effectiveness *= 0.5;
            }
        }
    }

    QSqlQuery effective3;

    effective3.prepare("select type_name from Type where type_id in (select w_weakness from Weakness inner join Type ON Type.type_id = Weakness.w_id where Type.type_name = (:type))");
    effective3.bindValue(":type", QString::fromStdString(getPType2()));
    //effective.bindValue(":movename", move.getType().c_str());
    //int moveid = moveIDs.record().indexOf("m_id");
    //qDebug() << (moveid) << movename;
    if (effective3.exec())
    {
        while (effective3.next())
        {

            id = effective3.value(0).toString();
           // qDebug() << "type: " << getPType1() << "Check Weak 2" << id ;
            if (move.getType() == id.toStdString()) {
              //   qDebug()<<"This is super very effective: "  << move.getType();
                effectiveness *= 2;
            }
        }
    }


    QSqlQuery effective4;
    effective4.prepare("select type_name from Type where type_id in (select r_resistane from Resistance inner join Type ON Type.type_id = Resistance.r_id where Type.type_name = (:type))");
    effective4.bindValue(":type", QString::fromStdString(getPType2()));
    //effective.bindValue(":movename", move.getType().c_str());
    //int moveid = moveIDs.record().indexOf("m_id");
    //qDebug() << (moveid) << movename;
    if (effective4.exec())
    {
        while (effective4.next())
        {

            id = effective4.value(0).toString();
           // qDebug() << "Check Res 2"  << id ;
            //qDebug() << (id);
            if (move.getType() == id.toStdString()) {
               //  qDebug()<< "This is not very effective: "  << move.getType();
                effectiveness *= 0.5;
            }
        }
    }



    //QSqlQuery effective;
    //effective.prepare("select type_name from Type where type_id in (select w_weakness from Weakness inner join Type ON Type.type_id == Weakness.w_id where Type.type_name = (:movetype))");
    //effective.bindValue(":movetype", move.getType());

    int damage = ((((((2 * attacker.getPLevel()) / 5) + 2) * move.getPower() * move.getBuff() * float(float(atkStat) / float(defStat))) / 50) + 2) * effectiveness * stab;
    std::cout << "move: " << move.getName() <<  "power: "<< attacker.getPAttack() << "  move power:" << move.getPower()<<  "  defense:" << getPDefense() << " stab: "<< stab << " effectiveness: " << effectiveness << "m_buff " << move.getPower() << std::endl;
    delete ability;
    ability = nullptr;
    return damage;
}

void Pokemon::hit(Pokemon attacker, Move& move) {
    int damage = calculateDamage(attacker, move);
    applyDamage(damage);
   // qDebug() << p_rhp ;
}

void Pokemon::print(){

    qDebug() << "p_id: " << p_id ;
    qDebug() << "p_name: " << p_name ;
    qDebug() << "p_level: " << p_level ;
    qDebug() << "p_item: " << p_item ;
    qDebug() << "p_type1: " << p_type1 ;
    qDebug() << "p_type2: " << p_type2 ;
    qDebug() << "p_height: " << p_height ;
    qDebug() << "p_weight: " << p_weight ;
    qDebug() << "p_ability: " << p_ability ;
    qDebug() << "p_gender: " << p_gender ;
    qDebug() << "p_HP: " << p_HP ;
    qDebug() << "p_Attack: " << p_Attack ;
    qDebug() << "p_Defense: " << p_Defense ;
    qDebug() << "p_SpecialAttack: " << p_SpecialAttack ;
    qDebug() << "p_SpecialDefense: " << p_SpecialDefense ;
    qDebug() << "p_Speed: " << p_Speed ;
    qDebug() << "p_rhp: " << p_rhp ;
    for(Move e: p_moves){
        //qDebug() << "MOVE" << e.getName();
    }
}

