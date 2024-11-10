#include <iostream>

int getRandNumber(int min, int max){
    //return a number between min and max
    return (rand()%(max-min+1)) +min;
}
