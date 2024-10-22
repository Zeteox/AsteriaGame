#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

using namespace std;

class Weapon
{
protected:
    string m_name;
    int m_price;
public:
    Weapon(const string& name, const int price);
    virtual void showStats() const = 0;
    string& getName();
    void setPrice(int newPrice);
    int getPrice() const;
};

#endif // WEAPON_H
