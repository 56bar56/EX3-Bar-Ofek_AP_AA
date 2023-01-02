//
// Created by newba on 06/12/2022.
//

#ifndef EX2_AP_B_O_FILECLASS_H
#define EX2_AP_B_O_FILECLASS_H

#include "FileClass.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "DistanceList.cpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class FileClass {
public:
    static void merge(string array[], int const left, int const mid, int const right);

    void mergeSort(string array[], int const begin, int const end);

    string FoundTheName(string names[]);

    string FormerMainRunner(int kPlaces, string distanceKind, vector<float> vec, string fileRead);
};

#endif //EX2_AP_B_O_FILECLASS_H