#ifndef HERO_H
#define HERO_H

#include "livingcreature.h"
#include "potion.h"

class Hero : public LivingCreature
{
protected:
    string m_class;
    //Inventory* m_inventory;
public:
    Hero(const string name, const int maxHp, const int golds, const int damage, const int defence, const string p_class);
    string& getClass();
    //Inventory &getInventory();
    //virtual void addToInventory(Potion *potion);
    //virtual void removeFromInventory(Potion *potion);
    void talk() const;
    void showStats() const;
    void drink(Potion *potion);
    //void trade(Merchant *merchant);
};

#endif // HERO_H
