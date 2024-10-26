#ifndef VILLAGE_H
#define VILLAGE_H
#include <iostream>

using namespace std;

class Village
{
    string m_name;
    int m_hostelNumber;
    int m_mineNumber ;
    int m_merchantNumber;
    //vector<Hostel*> m_allHostels ;
    //vector<Mine*> m_allMines ;
    //vector<Merchant*> m_allMerchants;
public:
    Village(string name);
    void generateVillage();
    //vector<Hostel*>* getHostels()
    //void addHostel(Hostel* hostel)
    //void removeHostel(Hostel* hostel)
    //vector<Mine*>getMines()
    //void addMine(Mine* mine)
    //void removeMine(Mine* mine)
    //vector<Merchant*> getMerchants()
    //void addMerchnat(Merchant* merchant)
    //void removeMerchant(Merchant* merchant)

};

#endif // VILLAGE_H
