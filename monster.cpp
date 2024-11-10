
#include "monster.h"
#include "randomNumber.h"

Monster::Monster(const string name, const int maxHp, const int golds, const int damage, const int defence,
                 const bool haveSword, const bool haveShield, const bool haveStaff)
    : LivingCreature( name, maxHp, golds, damage, defence){
    if(haveSword == true){
        setSword(new Sword("Standard Sword", 1, 2));
    }else{
        m_sword = nullptr;
    }
    if(haveShield == true){
        setShield(new Shield("Startard Shield",0,1));
    }else{
        m_shield = nullptr;
    }
    if(haveStaff == true){
        setStaff(new Staff("Standard Staff", 1, 2));
    }else{
        m_staff = nullptr;
    }
    genImagePath();
}

Sword* Monster::getSword(){
    return m_sword;
}

void Monster::setSword(Sword* sword){
    m_sword = sword;
    updDamage();
}

Shield* Monster::getShield(){
    return m_shield;
}

void Monster::setShield(Shield* shield){
    m_shield = shield;
    updDefence();
}

Staff* Monster::getStaff(){
    return m_staff;
}

void Monster::setStaff(Staff* staff){
    m_staff = staff;
    updDamage();
}

string Monster::getStats() const {
    return "Name: " + m_name +
           "\nHp: " + to_string(m_hp) + "/" + to_string(m_maxHp) +
           "\nGold: " + to_string(m_golds) +
           "\nDamage: " + to_string(m_damage) +
           "\nDefence: " + to_string(m_defence) +
           "\nSword: " + m_sword->getName();
           "\nShield: " + m_shield->getName();
           "\nStaff: " + m_staff->getName();
}

void Monster::updDamage() {
    if (m_sword != nullptr) {
        m_damage = m_baseDamage + m_sword->getDamage();
    }else if(m_staff != nullptr){
        m_damage = m_baseDamage + m_staff->getDamage();
    }else{
        m_damage = m_baseDamage;
    }
}

void Monster::updDefence() {
    if (m_shield != nullptr) {
        m_defence = m_baseDefence + m_shield->getDefence();
    } else {
        m_defence = m_baseDefence;
    }
}

string Monster::getImagePath(){
    return m_imagePath;
}

void Monster::genImagePath(){
    if(m_name == "goblin"){
        int choice = getRandNumber(1, 2);
        switch (choice) {
        case 1:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/gobelin/gobelin (1).jpeg";
            break;
        case 2:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/gobelin/gobelin (2).jpeg";
            break;
        }
    }else if(m_name == "lizardMan"){
        int choice = getRandNumber(1, 2);
        switch (choice) {
        case 1:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/homme lezard/Homme lezard (1).jpeg";
            break;
        case 2:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/homme lezard/Homme lezard (2).jpeg";
            break;
        }
    }else if(m_name == "skeleton"){
        int choice = getRandNumber(1, 2);
        switch (choice) {
        case 1:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/squelette/squelette (1).jpeg";
            break;
        case 2:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/squelette/squelette.png";
            break;
        }
    }else if(m_name == "tiefling"){
        int choice = getRandNumber(1, 3);
        switch (choice) {
        case 1:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/tiefling/Tiefling femme.jpeg";
            break;
        case 2:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/tiefling/Tiefling homme (1).jpeg";
            break;
        case 3:
            m_imagePath = ":/Images/Images/LivingCreature/Monster/mobs/tiefling/Tiefling homme (2).jpeg";
            break;
        }
    }else if(m_name == "Cthulu"){
        m_imagePath = ":/Images/Images/LivingCreature/Monster/boss/Cthulu.jpeg";
    }else if(m_name == "Plague Guardian"){
        m_imagePath = ":/Images/Images/LivingCreature/Monster/boss/Peste Gardien.jpeg";
    }else if(m_name == "Tiefling Demon"){
        m_imagePath = ":/Images/Images/LivingCreature/Monster/boss/tiefling demon.jpeg";
    }
}
