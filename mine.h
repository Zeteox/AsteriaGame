#ifndef MINE_H
#define MINE_H

#include "monster.h"
#include <vector>
class Mine
{
private:
    int m_mineLevel;
    vector<Monster*> m_monster;
    int fibonacci(int n);
    int m_numberOfMonster;

public:
    Mine(int mineLevel);
    ~Mine();
    int getMonsterNumber();
    int getMineLevel();
    void setMineLevel(int mineLevel);
    vector<Monster*> getMonster();
    string addMonster(Monster* monster);
    string removeMonster(Monster* monster);
    bool isEmpty();
    string generateMine();
    string levelUp();
};

#endif // MINE_H
