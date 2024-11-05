#ifndef MINE_H
#define MINE_H

#include "building.h"
#include "monster.h"
#include <vector>
class Mine : public Building
{
    int m_mineLevel;
    vector<Monster*> m_monster;
    int fibonacci(int n);

public:
    Mine(int mineLevel);
    int getMineLevel();
    void setMineLevel(int mineLevel);
    vector<Monster*> getMonster();
    string addMonster(Monster* monster);
    string removeMonster(Monster* monster);
    bool isEmpty();
    void generateMine(Monster* monster);
};

#endif // MINE_H
