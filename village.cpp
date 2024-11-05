#include "village.h"
#include <iostream>
#include "hostel.h"
#include "merchant.h"
#include "mine.h"
#include "randomNumber.h"
#include "building.h"
#include <vector>
using namespace std;

Village::Village(string name) {
    m_name = name;
    m_numberBuildings = getRandNumber(0, 9);
    generateVillage();
}

Village::~Village(){
    for(size_t x = 0; x< m_allBuildings.size(); x++){
        delete m_allBuildings[x];
    }
}

string Village::getName(){
    return m_name;
}

void Village::setName(string name){
    m_name = name;
}

int Village::getNumberBuildings(){
    return m_numberBuildings;
}

void Village::setNumberBuildings(int numberBuildings){
    m_numberBuildings = numberBuildings;
}

vector<Building*> Village::getAllBuildings(){
    return m_allBuildings;
}

string Village::addBuilding(Building* building){
    m_allBuildings.push_back(building);
    return "The building has been added";
}

string Village::removeBuilding(Building* building){
    if (m_numberBuildings == 0){
        return "You have no building to remove";
    }else{
        for (int i=0; i<m_numberBuildings;i++) {
            if (m_allBuildings[i] == building) {
                m_allBuildings.erase(m_allBuildings.begin()+i);
                return "The building has been removed";
            }
        }
    }
    return "The building doesn't exist in the inventory";
}

string Village::generateVillage(){
    for(int x=0; x != m_numberBuildings; x++){
        int choiceBuildingType = getRandNumber(1, 3);
        switch(choiceBuildingType){
        case 1 :
            m_allBuildings.push_back(new Hostel());
            break;
        case 2 :
            m_allBuildings.push_back(new Mine(0));
            break;
        case 3 :
            m_allBuildings.push_back(new Merchant());
            break;
        }
    }
    return "The village was created";
}
