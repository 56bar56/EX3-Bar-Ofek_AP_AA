//
// Created by User on 07/12/2022.
//

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "DistanceAndName.cpp"
#include "DistanceList.h"
using namespace std;

    /**
     * an empty constructor because we already analyzed the field and we need to put objects.
     */
    DistanceList::DistanceList() {
    }
/**
 * this func get a string from our file and add the vector that should be to our list
 * according to the instructions we received.
 * @param str1 the string from our file
 */
    void DistanceList::addItem(string str1) {
        string num_vec = "";
        string name = "";
        float num;
        int i = 0;
        int j=0;
        std::vector<float> g1;
        while (i < str1.size()) { //move on the string we get
            while (str1[i] == ' ') {
                i++;
            }
            while (str1[i] != ' ' && i < str1.size()) {
                if (str1[i] == ',') { //when we have , we get to the other number, and we keep the number before in num_vec
                    for(j=0;j<num_vec.size();j++) {
                        if (!(isdigit(num_vec[j]) || num_vec[j] == '-' || num_vec[j] == '.'||num_vec[j]=='E')) {
                            cout << "invalid input";
                            exit(1);
                        }
                    }
                    num = MyVector::checkNewFloat(num_vec);
                    g1.push_back(num);
                    num_vec = "";
                    i++;
                }
                num_vec += str1[i];
                i++;
            }
            for(j=0;j<num_vec.size()-1;j++) { // keep the name of the flower in a string
                name+=num_vec[j];
            }
        }
        DistanceAndName x = DistanceAndName(MyVector(g1), name);
        this->v.push_back(x);
    }    /**
     * get an array and a number k and put the first k members in our vector in the array.
     * @param k the numbers of elements we put
     * @param closest the array we put values in
     */
    void DistanceList::closestK(int k,  DistanceAndName closest[]) {
        int i;
        for (i = 0; i<k; i++) {
            closest[i]=this->v[i];
        }
    }
    /**
     * a getter to our v
     * @return our v field
     */
    const vector<DistanceAndName> DistanceList::getV() const;
        return v;
    }
    /**
     * set the distance of every member in our vector with vector we get and the kind of
     * distance we check.
     * @param vector the vector we check the distance from
     * @param disName the kind of distance
     */
    void DistanceList::setDistances(MyVector vector, string disName) {
        int i;
        for (i = 0; i < this->v.size(); i++) {
            this->v[i].setDistance(vector, disName);
        }
    }
/**
 * get an k value and put the k's size number in the k-1 spot and
 * before we will have smaller numbers and right bigger.
 * @param k the value we arranged accordingly
 */
    void DistanceList::select(int k) {
        if (k >= this->v.size()) {
            cout << "k can't be bigger than the size of the vector";
            exit(1);
        }
        int start = 0;
        int end = this->v.size() - 1;
        while (end >= start) {
            int pivot = partition(start, end);
            if (pivot == k - 1) {
                break;
            }
            if (pivot < k - 1) {
                start = pivot + 1;
            } else {
                end = pivot - 1;
            }
        }

    }
    /**
     * this func use the last element as pivot and put the smaller at his left and bigger
     * at his right.
     * @param start the start of the array we use
     * @param end the end of the array we use
     * @return the pivot spot
     */
    int DistanceList::partition(int start, int end) {
        int i;
        float x = (this->v[end]).getDistance();
        int j = start;
        for (i = start; i < end; i++) {
            if ((this->v[i]).getDistance() <= x) {
                DistanceAndName d = this->v[i];
                this->v[i] = this->v[j];
                this->v[j] = d;
                j++;
            }
        }
        DistanceAndName d2 = this->v[end];
        this->v[end] = this->v[j];
        this->v[j] = d2;
        return j;
    }
