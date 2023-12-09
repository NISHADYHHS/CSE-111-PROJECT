#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <QString>
class Move {
public:
    Move();

    Move(int id, std::string name, std::string type, std::string category,int power, int pp, int accuracy);
    std::string getType();
    void applyBuff(float multiplier);
    void resetBuff();
    void setID(int id);
    void setName(std::string id);
    void setType(std::string type);
    void setCategory( std::string category);
    void setPower(int power);
    void setPP( int pp);
    void setAccuracy(int accuracy);

    int getBuff() const;
    int getID() const;
    std::string getName() const;
    std::string getType() const;
    std::string getCategory() const;
    int getPower() const;
    int getPP() const;
    int getAccuracy() const;

private:
    int m_id;
    std::string m_name;
    std::string m_type;
    std::string m_category;
    int m_power;
    int m_pp;
    int m_accuracy;
    float m_buff;

};


#endif
