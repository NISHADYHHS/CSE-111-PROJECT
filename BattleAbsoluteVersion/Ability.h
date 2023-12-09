#ifndef ABILITIES_H
#define ABILITIES_H
#include <iostream>
#include "Move.h"
#include "Pokemon.h"

class BaseAbility {
public:
    virtual void useAbility(Pokemon& target) = 0;
    virtual ~BaseAbility() = default;
};

class HPBasedBoost : public BaseAbility {
    std::string type;
    Move &attack;
public:
    HPBasedBoost(std::string typeBoost, Move &usedattack) : type(typeBoost), attack(usedattack) {}
    ~HPBasedBoost() {
        attack.resetBuff();
    }
    void useAbility(Pokemon& target) override {
        if ((target.getPRHP() < 0.33 * target.getPHP()) && attack.getType() == type) {
            attack.applyBuff(1.5);
        }
    }
};

class Aftermath : public BaseAbility {
    Move move;
public:
    Aftermath(Move mov) : move(mov) {}
    void useAbility(Pokemon& target) override {
        if (move.getCategory() == "Physical") {
            target.applyDamage(0.25 * target.getPHP());
        }
    }
};

#endif
