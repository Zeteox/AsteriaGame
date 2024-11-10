#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <vector>

using namespace std;

class Weapon
{
protected:
    string m_name;
    string m_type;
    vector<string> m_swordIconsPath;
    vector<string> m_staffIconsPath;
    vector<string> m_shieldIconsPath;
    int m_price;
public:
    Weapon(const string& name, const int price);
    virtual ~Weapon();
    virtual string getStats() const = 0;
    string &getName();
    string &getType();
    void setPrice(int newPrice);
    int getPrice() const;
    vector<string> getSwordIconsPath();
    vector<string> getStaffIconsPath();
    vector<string> getShieldIconsPath();
    virtual int getDamage() const;
    virtual int getDefence() const;
};

#endif // WEAPON_H
