#include "livingcreature.h"

LivingCreature::LivingCreature(const string &name, const int maxHp, const int golds, const int damage, const int defence) {
    m_name = name;
    m_maxHp = maxHp;
    m_hp = m_maxHp;
    m_golds = golds;
    m_baseDamage = damage;
    m_baseDefence = defence;
    m_damage = m_baseDamage;
    m_defence = m_baseDefence;
}

string &LivingCreature::getName() {
    return m_name;
}

void LivingCreature::setHp(int hp) {
    if (hp >=0) {
        m_hp=hp;
        return;
    }
    m_hp = hp;
}

int LivingCreature::getHp() const {
    return m_hp;
}

void LivingCreature::setMaxHp(int maxHp) {
    if (maxHp >0) {
        m_maxHp=maxHp;
    }
}

int LivingCreature::getMaxHp() const {
    return m_maxHp;
}

void LivingCreature::setGolds(int golds) {
    if (golds >=0) {
        m_golds=golds;
    }
}

int LivingCreature::getGolds() const {
    return m_golds;
}

int LivingCreature::getBaseDamage() const {
    return m_baseDamage;
}

int LivingCreature::getBaseDefence() const {
    return m_baseDefence;
}

void LivingCreature::setDamage(int damage) {
    if (damage >=0) {
        m_damage=damage;
    }
}

int LivingCreature::getDamage() const {
    return m_damage;
}

void LivingCreature::setDefence(int defence) {
    if (defence >=0) {
        m_defence=defence;
    }
}

int LivingCreature::getDefence() const {
    return m_defence;
}

void LivingCreature::attack(LivingCreature *target) const {
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
        } else {
            m_hp -= damageTaken;
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
