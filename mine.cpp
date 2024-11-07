#include "mine.h"

Mine::Mine(int mineLevel) {
    m_mineLevel = mineLevel;
}

int Mine::fibonacci(int n) {
    if(n==0) {
        return 0;
    }else if(n==1||n==2) {
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int Mine::getMineLevel(){
    return m_mineLevel;
}

void Mine::setMineLevel(int mineLevel){
    m_mineLevel = mineLevel;
}

vector<Monster*> Mine::getMonster(){
    return m_monster;
}

string Mine::addMonster(Monster* monster){
    m_monster.push_back(monster);
    return "The Monster has been added";
}

string Mine::removeMonster(Monster* monster){
    if (m_monster.size() == 0){
        return "You have no monster to remove";
    }else{
        for (size_t i=0; i<m_monster.size();i++) {
            if(m_monster[i] == monster){
                m_monster.erase(m_monster.begin()+i);
                return "The monster has been removed";
            }

        }
    }
    return "the monster doesn't exist in the Mine";
}
bool Mine::isEmpty(){
    if(m_monster.size() == 0){
        return true;
    }else {
        return false;
    }
}
void Mine::generateMine(Monster* monster){
    for(int i=0; i!=fibonacci(m_mineLevel); i++){
        m_monster.push_back(monster);
    }
}
