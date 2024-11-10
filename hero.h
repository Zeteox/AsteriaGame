#ifndef HERO_H
#define HERO_H

#include "livingcreature.h"
#include "potion.h"
#include "inventory.h"
#include "merchant.h"

class Hero : public LivingCreature
{
protected:
    string m_class;
    Inventory* m_inventory;
public:
    Hero(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class);
    virtual ~Hero();
    string& getClass();
    Inventory* getInventory();
    string addToInventory(Potion *potion);
    string addToInventory(Weapon *weapon);
    string removeFromInventory(Potion *potion);
    string removeFromInventory(Weapon *weapon);
    string talk() const;
    void drink(Potion *potion);
    void trade(Merchant *merchant, Potion *potion);
    void trade(Merchant *merchant, Weapon *weapon);
    void sell(Merchant *merchant, Potion *potion);
    void sell(Merchant *merchant, Weapon *weapon);
    virtual int getBonuses();
    virtual void setWeapon(Weapon *newWeapon);
    virtual vector<Weapon*> getWeapons();
};

#endif // HERO_H
