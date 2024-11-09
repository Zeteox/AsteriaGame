#ifndef HERO_H
#define HERO_H

#include "healingpotion.h"
#include "livingcreature.h"
#include "inventory.h"
#include "strengthpotion.h"
#include "resistancepotion.h"

class Hero : public LivingCreature
{
protected:
    string m_class;
    Inventory* m_inventory;
public:
    Hero(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class);
    string& getClass();
    Inventory &getInventory();
    string talk() const;
    void addToInventory(HealingPotion *healingPotion);
    void removeFromInventory(HealingPotion *healingPotion);
    void drink(HealingPotion *healingPotion);
    void addToInventory(StrengthPotion *strenghPotion);
    void removeFromInventory(StrengthPotion *strenghPotion);
    void drink(StrengthPotion *strenghPotion);
    void addToInventory(ResistancePotion *resistancePotion);
    void removeFromInventory(ResistancePotion *resistancePotion);
    void drink(ResistancePotion *resistancePotion);
    //void trade(Merchant *merchant);
};

#endif // HERO_H
