#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>

using namespace std;

class Building
{
    string m_type;
public:
    Building(const string &type);
    string getType();
    void setType(string type);
};

#endif // BUILDING_H
