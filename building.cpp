#include "building.h"

Building::Building(const string &type) {
    //The constructor creates a new building
    //of the type requested in the associated attribute.
    m_type = type;
    if (type == "Hostel") {
        m_hostel = new Hostel();
        m_merchant = nullptr;
        m_mine = nullptr;
    } else     if (type == "Merchant") {
        m_hostel = nullptr;
        m_merchant = new Merchant();
        m_mine = nullptr;
    } else     if (type == "Mine") {
        m_hostel = nullptr;
        m_merchant = nullptr;
        m_mine = new Mine (1);
    }
}
Building::~Building(){
    // The destructor delete the buildings.
    delete m_hostel;
    delete m_merchant;
    delete m_mine;
}

string Building::getType(){
    return m_type;
}

void Building::setType(string type){
    m_type = type;
};

Hostel* Building::getHostel() {
    return m_hostel;
}

Merchant* Building::getMerchant() {
    return m_merchant;
}

Mine* Building::getMine() {
    return m_mine;
}
