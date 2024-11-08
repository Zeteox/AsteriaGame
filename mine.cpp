#include "mine.h"
#include "randomNumber.h"

Mine::Mine(int mineLevel) : Building("Mine"){
    m_mineLevel = mineLevel;
    generateMine();
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

string Mine::generateMine(){
    if(m_mineLevel < 6){
        for(int i=0; i!=fibonacci(m_mineLevel); i++){
            int choice = getRandNumber(0, 3);
            switch (choice) {
            case 0:
                m_monster.push_back(new Monster("goblin", 2, 2, 2, 2, true, false, false));
                break;
            case 1:
                m_monster.push_back(new Monster("skeleton", 2, 2, 2, 2, true, false, false));
                break;
            case 2:
                m_monster.push_back(new Monster("lizardMan", 2, 2, 2, 2, true, true, false));
                break;
            case 3:
                m_monster.push_back(new Monster("tiefling", 2, 2, 2, 2, false, false, true));
                break;
            }
        }
        return "Mine was generated";
    }else if(m_mineLevel > 9){
        return "This mine has been finished";
    }else{
        int choice = getRandNumber(0, 2);
        switch (choice) {
        case 0:
            m_monster.push_back(new Monster("Cthulu", 2, 2, 2, 2, false, false, true));
            break;
        case 1:
            m_monster.push_back(new Monster("Plague Guardian", 2, 2, 2, 2, true, true, false));
            break;
        case 2:
            m_monster.push_back(new Monster("Tiefling Demon", 2, 2, 2, 2, false, false, true));
            break;
        }
        return "Mine was generated";
    }
}

string Mine::levelUp() {
    if(isEmpty() == true){
        m_mineLevel++;
        generateMine();
        return "The Mine was level Up";
    }else{
        return "There are still monsters in the mine";
    }
}
