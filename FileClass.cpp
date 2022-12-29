//
// Created by newba on 06/12/2022.
//

#include "FileClass.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "DistanceList.cpp"
/**
 * divide the array into the little arrays and start sorting them and connect them.
 * @param array
 * @param left
 * @param mid
 * @param right
 */
void merge(string array[], int const left, int const mid,int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    string *leftArray = new string[subArrayOne],
            *rightArray = new string[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
/**
 * get a string array and sort him by the strings.
 * @param array the array we sort
 * @param begin the start of the array
 * @param end the end of he array
 */
void mergeSort(string array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}
/**
 * found the member of the array that show the most.
 * @param names
 * @return
 */
string FoundTheName(string names[]){
    string result;
    if(names->empty()){
        result = "";
    }
    else{
        int counter = 1;
        int maxCounter = 0;
        for(int i = 0; i < names->size() - 1; i++){
            if(maxCounter < counter){
                maxCounter = counter;
            }
            if(names[i] == names[i+1]){
                counter++;
            }
            else{
                counter = 0;
            }
        }
        counter = 1;
        for(int i = 0; i < names->size() - 1; i++){
            if(names[i] == names[i+1]){
                counter++;
            }
            if(counter == maxCounter){
                result = names[i];
                break;
            }
        }
    }
    return result;
}
string FormerMainRunner(int kPlaces, string distanceKind, vector<float> vec, string fileRead){
    string lineUser;
    std::vector<float> g1 = vec;
    int i;
    int k = kPlaces;
    std::string file = fileRead;
    std::string disKind = distanceKind;

    if(disKind!="AUC"&&disKind!="MAN"&&disKind!="CHB"&&disKind!="CAN"&&disKind!="MIN") {
        std::cout<<"the distance isn't valid value";
        exit(1);
    }
    DistanceList list= DistanceList();
    std::ifstream myfile;
    myfile.open(file);
    std::string myline;
    if ( myfile ) {
        std::getline (myfile, myline);
        while ( myfile ) { // equivalent to myfile.good()
            list.addItem(myline);
            std::getline (myfile, myline);
        }
        while(true) {
            list.setDistances(MyVector(g1),disKind);//AUC
            list.select(k);
            DistanceAndName closest[k];
            list.closestK(10,closest);
            string closestNames[k];
            for(i = 0; i < k; i++){
                closestNames[i] = closest[i].getName();
            }
            mergeSort(closestNames, 0, k-1);  //sort by string
            string result = FoundTheName(closestNames);
            //cout << result << std::endl;//print the name
            return result;

        }
    }
    else {
        std::cout << "Couldn't open file\n";
        return "-1";
    }
}