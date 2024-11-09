#ifndef POTION_H
#define POTION_H

#include <iostream>

using namespace std;

class Potion {
protected:
    string m_name;
    int m_price;

public:
    Potion();
    string &getName();
    void setName(string name);;
    void setPrice(int price);
    int getPrice();
    virtual void createPotion(int level);
};



#endif //POTION_H
