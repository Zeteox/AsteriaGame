#include "village.h"
#include <iostream>
#include "randomNumber.h"
#include "building.h"
#include <vector>
using namespace std;

Village::Village(string name) {
    m_name = name;
    m_numberBuildings = getRandNumber(0, 9);
    generateVillage();
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
            if (m_allBuildings[i]->getType()==building->getType()) {
                m_allBuildings.erase(next(m_allBuildings.begin()+i));
                return "The building has been removed";
            }
        }
    }
    return "The building doesn't exist in the inventory";
}

void Village::generateVillage(){
    for(int x=0; x != m_numberBuildings; x++);{
        int choiceBuildingType = getRandNumber(1, 3);
        string buildingType;
        switch(choiceBuildingType){
        case 1 :
            buildingType = "Hostel";
            break;
        case 2 :
            buildingType = "Merchant";
            break;
        case 3 :
            buildingType = "Mine";
            break;
        }
        m_allBuildings.push_back(new Building(buildingType));
    }
}
