#include "Move.h"

#include <QDebug>

    Move::Move(int id,  std::string name,  std::string type,  std::string category,int power, int pp, int accuracy) :
        m_id(id), m_name(name), m_type(type), m_category(category),
        m_power(power), m_pp(pp), m_accuracy(accuracy) {
        m_buff = 1;
    }

    Move::Move()
        : m_id(0), m_name(""), m_type(""), m_category(""), m_power(0), m_pp(0), m_accuracy(0) {
        m_buff = 1;
    }

    std::string Move::getType() {
        return m_type;
    }

    void Move::applyBuff(float multiplier) {
        m_buff = multiplier;
       // std::cout << m_buff << std::endl;
    }
    void Move::resetBuff() {
        m_buff = 1;
    }

    void Move::setID(int id){
        m_id = id;
    }
    void Move::setName(std::string id){
        m_name = id;
    }
    void Move::setType(std::string type){
        m_type = type;
    }
    void Move::setCategory( std::string category){
        m_category = category;
    }
    void Move::setPower(int power){

        m_power = power;
    }
    void Move::setPP( int pp){
        m_pp = pp;
    }
    void Move::setAccuracy(int accuracy){
        m_accuracy = accuracy;
    }

    int Move::getBuff() const {
        return m_buff;
    }

    int Move::getID() const {
        return m_id;
    }

    std::string Move::getName() const {
        return m_name;
    }

    std::string Move::getType() const {
        return m_type;
    }

    std::string Move::getCategory() const {
        return m_category;
    }

    int Move::getPower() const {
        return m_power;
    }

    int Move::getPP() const {
        return m_pp;
    }

    int Move::getAccuracy() const {
        return m_accuracy;
    }
