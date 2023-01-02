//
// Created by User on 07/12/2022.
//
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Vector_Algorithms.h"
using namespace std;

#ifndef EX2_AP_B_O_DISTANCEANDNAME_H
#define EX2_AP_B_O_DISTANCEANDNAME_H



class DistanceAndName{
private:
    MyVector vector;
    float distance;
    string name;
public:
    DistanceAndName(MyVector v, string n);
    DistanceAndName();
    MyVector getVector() const;
    float getDistance() const;
    void setDistance(MyVector myVector, string disName);
    const string getName() const;
};


#endif //EX2_AP_B_O_DISTANCEANDNAME_H