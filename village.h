#ifndef VILLAGE_H
#define VILLAGE_H
#include <iostream>
#include "building.h"
#include <vector>
using namespace std;

class Village
{
    string m_name;
    int m_numberBuildings;
    vector<Building*> m_allBuildings ;
public:
    Village(string name);
    string getName();
    void setName(string name);
    int getNumberBuildings();
    void setNumberBuildings(int numberBuildings);
    vector<Building*> getAllBuildings();
    string addBuilding(Building* building);
    string removeBuilding(Building* building);
    string generateVillage();
};

#endif // VILLAGE_H
