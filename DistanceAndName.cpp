//
// Created by User on 07/12/2022.
//

#include <iostream>
#include "DistanceAndName.h"
#include <cstdlib>
#include <cstring>
#include "Vector_Algorithms.cpp"

using namespace std;

/**
 * this class represant a complex object that hold a vector that represent
 *  the values of a flower and the string that represent the
 * status of the flower and the distance that we set when the user give us a vector.
 */
class DistanceAndName {
private:
    MyVector vector;
    float distance;
    string name;
public:
    /**
     * a constructor that set the values.
     * @param v the vector we put
     * @param n the string we put
     */
    DistanceAndName(MyVector v, string n) {
        this->vector = v;
        this->distance = 0;
        this->name = n;
    }

    /**
    * an empty constructor.
    */
    DistanceAndName() {

    }

    /**
     * a getter for the my vector we have.
     * @return a getter for the my vector we have
     */
    MyVector getVector() const {
        return vector;
    }

    /**
     * a getter for the distance we have.
     * @return the distance we have
     */
    float getDistance() const {
        return distance;
    }

    /**
     * a function that set the distance to be from a vector we get
     * and the kind of distance we get to.
     * @param myVector the vector we get
     * @param disName the kind of distance we get
     */
    void setDistance(MyVector myVector, string disName) {
        if (myVector.getV().size() != this->vector.getV().size()) {
            std::cout << "the vectors aren't in the same sizes." << std::endl;
            exit(1);
        }
        if (disName == "AUC") {
            this->distance = this->vector.euclideanDis(myVector);
        } else {
            if (disName == "MAN") {
                this->distance = this->vector.manatenDis(myVector);
            } else {
                if (disName == "CHB") {
                    this->distance = this->vector.chebyshevDis(myVector);
                } else {
                    if (disName == "CAN") {
                        this->distance = this->vector.canberraDis(myVector);
                    } else {
                        if (disName == "MIN") {
                            this->distance = this->vector.minkowskiDis(myVector);
                        }
                    }
                }

            }

        }

    }

    /**
     * a getter for the name.
     * @return  the name
     */
    const string &getName() const {
        return name;
    }
};