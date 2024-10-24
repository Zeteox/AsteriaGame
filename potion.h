#ifndef POTION_H
#define POTION_H

#include <iostream>

using namespace std;

class Potion {
private:
    string m_name;
    int m_hp;
    int m_price;
    void createPotion(int level);

public:
    Potion(int level);
    string &getName();
    void setName(string name);
    void setHp(int hp);
    int getHp();
    void setPrice(int price);
    int getPrice();
};



#endif //POTION_H
