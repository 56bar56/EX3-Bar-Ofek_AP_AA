//
// Created by User on 07/12/2022.
//
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "DistanceAndName.h"

#ifndef EX2_AP_B_O_DISTANCELIST_H
#define EX2_AP_B_O_DISTANCELIST_H

using namespace std;
/**
 * this class as a vector of a DistanceAndName object.
 */
class DistanceList {
private:
    std::vector<DistanceAndName> v; //a vector we keep in the class
public:
    DistanceList();
    void addItem(string str1);
    void closestK(int k,  DistanceAndName closest[]);
    const vector<DistanceAndName> getV();
    void setDistances(MyVector vector, string disName);
    void select(int k);
    int partition(int start, int end);

    };


#endif //EX2_AP_B_O_DISTANCELIST_H