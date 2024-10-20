#include "livingcreature.h"

LivingCreature::LivingCreature(string name, int maxHp, int golds, int damage, int defence) {
    m_name = name;
    m_maxHp = maxHp;
    m_hp = m_maxHp;
    m_golds = golds;
    m_baseDamage = damage;
    m_baseDefence = defence;
    updDamage();
    updDefence();
}

void LivingCreature::attack(LivingCreature* target) const {
    target->removeHp(m_damage);
}

void LivingCreature::updDamage() {
    m_damage = m_baseDamage;
}

void LivingCreature::updDefence() {
    m_defence = m_baseDefence;
}

void LivingCreature::removeHp(int damage) {
    int damageTaken = damage - m_defence;
    if (damageTaken>0) {
        if (m_hp - damageTaken<=0) {
            m_hp = 0;
            cout << m_name + " has died" << endl;
        } else {
            m_hp -= damageTaken;
            cout << m_name << " took " <<
                damageTaken << " damage" <<
                endl;
        }
    }
}

void LivingCreature::healHp(int heal) {
    int finalHp = m_hp + heal;
    if (finalHp > m_maxHp) {
        m_hp = m_maxHp;
    } else {
        m_hp = finalHp;
    }
}

bool LivingCreature::isAlive() {
    return m_hp>0;
}
