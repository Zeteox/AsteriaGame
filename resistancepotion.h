#ifndef RESISTANCEPOTION_H
#define RESISTANCEPOTION_H

#include "potion.h"

class ResistancePotion : public Potion
{
    int m_defence;
public:
    ResistancePotion(int level);
    int getDefence();
    void setDefence(int defence);
    void createPotion(int level);
};

#endif // RESISTANCEPOTION_H
