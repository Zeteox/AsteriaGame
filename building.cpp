#include "building.h"

Building::Building(const string &type) {
    m_type = type;
}
string Building::getType(){
    return m_type;
}
void Building::setType(string type){
    m_type = type;
};
