#ifndef MINE_H
#define MINE_H

#include "building.h"
class Mine : public Building
{
    int m_mineLevel;
    //vector<Monster* monster> m_monster;
public:
    Mine();
};

#endif // MINE_H
