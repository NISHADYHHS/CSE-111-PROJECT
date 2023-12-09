#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include "Move.h"
#include "item.h"
#include <vector>

class Pokemon {
private:
    int p_id;
    std::string p_name;
    int p_level;
    std::string p_item;
    std::string p_type1;
    std::string p_type2;
    double p_height;
    double p_weight;
    std::string p_ability;
    std::string p_gender;
    int p_HP;
    int p_Attack;
    int p_Defense;
    int p_SpecialAttack;
    int p_SpecialDefense;
    int p_Speed;
    std::vector<Move> p_moves;
    int p_rhp;
public:


    // Constructor
    Pokemon(int id, std::string name, int level, std::string item,
            std::string type1, std::string type2, double height, double weight,
            std::string ability, std::string gender, int HP, int attack, int defense,
            int special_attack, int special_defense, int speed, std::vector<Move> moves);
    Pokemon(int id, std::string name, int level, std::string item,
            std::string type1, std::string type2, double height, double weight,
            std::string ability, std::string gender, int HP, int attack, int defense,
            int special_attack, int special_defense, int speed, std::vector<Move> moves, int r);

    Pokemon(const Pokemon& other);

    Pokemon();
    ~Pokemon();

    std::vector<Move> getMovesZZZ();
    void addMove(Move move);
    int getNoOfMoves();
    int getHP(int stat, int lv);

    int getStat(int stat, int lv);
    int getPId();
    void setPId(int id);

    std::string getPName();
    void setPName(std::string name);

    int getPLevel();
    void setPLevel(int level);

    std::string getPItem();
    void setPItem(std::string item);

    std::string getPType1();
    void setPType1(std::string type1);

    std::string getPType2();
    void setPType2(std::string type2);

    double getPHeight();
    void setPHeight(double height);

    double getPWeight();
    void setPWeight(double weight);

    std::string getPAbility();
    void setPAbility(std::string ability);

    std::string getPGender();
    void setPGender(std::string gender);

    int getPHP();
    void setPHP(int HP);

    int getPAttack();
    void setPAttack(int attack);

    int getPDefense();
    void setPDefense(int defense);

    int getPSpecialAttack();
    void setPSpecialAttack(int specialAttack);

    int getPSpecialDefense();
    void setPSpecialDefense(int specialDefense);

    int getPSpeed();
    void setPSpeed(int speed);

    int getPMoveID();
    void setPMoveID(int moveID);

    void setMoves(std::vector<Move> moves);
    int getPRHP();
    void setPRHP(int rhp);

    int setHP(int stat, int lv);
    void useItem(HPBasedItem& i);


    void applyDamage(int dmg);
    void hit(Pokemon attacker, Move& move);
    int calculateDamage(Pokemon attacker, Move& move);
    int setStat(int stat, int lv);
    void print();

    // Other member functions if needed
};
#endif // POKEMON_H
