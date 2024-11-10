#include "mine.h"
#include "randomNumber.h"

Mine::Mine(int mineLevel) {
    //The constructor sets the m_mineLevel attribute to the level entered as an argument
    //and m_numberOfMonster to 0, then calls the generateMine method.
    m_mineLevel = mineLevel;
    m_numberOfMonster =0;
    generateMine();
}

int Mine::getMonsterNumber() {
    return m_numberOfMonster;
}

int Mine::fibonacci(int n) {
    //This method returns the number of the fibonacci
    //sequence associated with the number entered as an argument.
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
    //The addMonster method adds a monster to the m_monster attribute
    //and adds 1 to m_numberOfMonster.
    m_monster.push_back(monster);
    m_numberOfMonster++;
    return "The Monster has been added";
}

string Mine::removeMonster(Monster* monster){
    //The removeMonster method removes from the mine the monster entered as argument
    //and decrements the m_numberOfMonster attribute by 1.
    if (m_monster.size() == 0){
        return "You have no monster to remove";
    }else{
        m_numberOfMonster--;
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
    return m_monster.size() == 0;
}

string Mine::generateMine(){
    //The generateMine method creates a mine so that the number of monsters present
    //is associated with the fibonacci sequence up to Level 6, where a Boss is generated.
    if(m_mineLevel < 6){
        for(int i=0; i!=fibonacci(m_mineLevel); i++){
            int choice = getRandNumber(0, 3);
            switch (choice) {
            case 0:
                addMonster(new Monster("goblin", 8, 3, 1, 0, true, false, false));
                break;
            case 1:
                addMonster(new Monster("skeleton", 6, 2, 2, 0, true, false, false));
                break;
            case 2:
                addMonster(new Monster("lizardMan", 10, 5, 1, 0, true, true, false));
                break;
            case 3:
                addMonster(new Monster("tiefling", 12, 10, 2, 1, false, false, true));
                break;
            }
        }
        return "Mine was generated";
    }else if(m_mineLevel >= 7) {
        return "This mine has been finished";
    }else{
        int choice = getRandNumber(0, 2);
        switch (choice) {
        case 0:
            addMonster(new Monster("Cthulu", 16, 14, 5, 1, false, false, true));
            break;
        case 1:
            addMonster(new Monster("Plague Guardian", 20, 16, 4, 1, true, true, false));
            break;
        case 2:
            addMonster(new Monster("Tiefling Demon", 24, 17, 5, 0, false, false, true));
            break;
        }
        return "Mine was generated";
    }
}

string Mine::levelUp() {
    //The levelUp method checks whether the mine is empty,
    //adds 1 to the m_mineLevel attribute and then regenerates a mine.
    if (m_mineLevel<6) {
        if(isEmpty() == true){
            m_mineLevel++;
            generateMine();
            return "The Mine was level Up";
        }else{
            return "There are still monsters in the mine";
        }
    } else {
        return "The mine can't level up anymore";
    }
}
