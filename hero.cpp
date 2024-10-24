#include "hero.h"
#include <QDebug>

Hero::Hero(const string name, const int maxHp, const int golds, const int damage, const int defence, const string p_class)
    : LivingCreature(name, maxHp, golds, damage, defence) {
    m_class = p_class;
}

string& Hero::getClass() {
    return m_class;
}

void Hero::talk() const {
    qDebug() << "je suis le hero " << m_name;
}

void Hero::showStats() const {
    qDebug()<< "Name:" << m_name << "\n"
            << "class:" << m_class << "\n"
            << "Hp:" << m_hp << "/" << m_maxHp << "\n"
            << "Gold:" << m_golds << "\n"
            << "Damage:" <<m_damage << "\n"
            << "Defence:" <<m_defence;
}

void Hero::drink(Potion *potion) {
    healHp(potion->getHp());
    delete potion;
}
