#include "village.h"
#include "randomNumber.h"
#include "building.h"
#include <vector>
using namespace std;

Village::Village(string name) {
    /*The constructor sets the m_name attribute to the name entered as an argument
    and m_numberBuildings to a random number between 0 and 9,
    then calls the generateVillage method.*/
    m_name = name;
    m_numberBuildings = getRandNumber(2, 9);
    generateVillage();
}

Village::~Village(){
    // The destructor delete the village.
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
    //The addBuilding method adds the building entered as an argument.
    m_allBuildings.push_back(building);
    return "The building has been added";
}

string Village::removeBuilding(Building* building){
    //The removeBuilding method removes the building entered as an argument
    //from the list of buildings.
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
    /*The generateVillage method creates a village with the number
    of buildings specified in the m_numberBuildings attribute.
    Then randomly adds one of the building types to the m_allBuildings attribute.*/
    for(int x=0; x != m_numberBuildings; x++){
        int choiceBuildingType = getRandNumber(1, 3);
        switch(choiceBuildingType){
        case 1 :
            addBuilding(new Building("Hostel"));
            break;
        case 2 :
            addBuilding(new Building("Mine"));
            break;
        case 3 :
            addBuilding(new Building("Merchant"));
            break;
        }
    }
    return "The village was created";
}
