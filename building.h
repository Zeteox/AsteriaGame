#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include "hostel.h"
#include "merchant.h"
#include "mine.h"

using namespace std;

class Building
{
private:
    string m_type;
    Hostel* m_hostel;
    Merchant* m_merchant;
    Mine* m_mine;

public:
    Building(const string &type);
    ~Building();
    string getType();
    void setType(string type);
    Hostel* getHostel();
    Merchant* getMerchant();
    Mine* getMine();
};

#endif // BUILDING_H
