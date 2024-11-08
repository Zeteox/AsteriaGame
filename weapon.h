#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

using namespace std;

class Weapon
{
protected:
    string m_name;
    string m_type;
    int m_price;
public:
    Weapon(const string& name, const int price);
    virtual string getStats() const = 0;
    string &getName();
    string &getType();
    void setPrice(int newPrice);
    int getPrice() const;
    virtual int getDamage() const;
    virtual int getDefence() const;
};

#endif // WEAPON_H
