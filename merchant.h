#ifndef MERCHANT_H
#define MERCHANT_H

#include <vector>
#include "building.h"
#include "potion.h"
#include "shield.h"
#include "staff.h"
#include "sword.h"
class Merchant : public Building
{
    vector<Sword*> m_swordStock;
    vector<Shield*> m_shieldStock;
    vector<Staff*> m_staffStock;
    vector<Potion*> m_potionStock;
public:
    Merchant();
    vector<Sword*> getSwordStock();
    vector<Shield*> getShieldStock();
    vector<Staff*> getStaffStock();
    vector<Potion*> getPotionStock();
    string removeSword(Sword* sword);
    string removeShield(Shield* shield);
    string removeStaff(Staff* staff);
    string removePotion(Potion* potion);

};

#endif // MERCHANT_H
