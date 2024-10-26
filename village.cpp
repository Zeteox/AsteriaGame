#include "village.h"
#include <iostream>
#include "randomNumber.h"
using namespace std;

Village::Village(string name) {
    m_name = name;
    m_hostelNumber = getRandNumber(0, 3);
    m_mineNumber = getRandNumber(1,3);
    m_merchantNumber = getRandNumber(1,3);
    generateVillage();
}

void Village::generateVillage(){
    for(int x=0; x != m_hostelNumber; x++);{
        //m_allHostels.push_back(new Hostel());
    }
    for(int x=0; x != m_mineNumber; x++);{
        //m_allMines.push_back(new Mine());
    }
    for(int x=0; x != m_merchantNumber; x++);{
        //m_allMerchants.push_back(new Merchant());
    }

}
