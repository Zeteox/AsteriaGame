#ifndef POTION_H
#define POTION_H

#include <iostream>

using namespace std;

class Potion {
    string m_name;
    int m_hp;
    int m_price;
public:
    Potion(int level);
    string& getName();
    void setName(string name);
    void setHp(int hp);
    int getHp();
    void setPrice(int price);
    int getPrice();
    void createPotion(int level);
};



#endif //POTION_H
