//
// Created by User on 07/12/2022.
//

#include "DistanceAndName.h"

using namespace std;

/**
 * this class represant a complex object that hold a vector that represent
 *  the values of a flower and the string that represent the
 * status of the flower and the distance that we set when the user give us a vector.
 */
/**
 * a constructor that set the values.
 * @param v the vector we put
 * @param n the string we put
 */
DistanceAndName::DistanceAndName(MyVector v, string n) {
    this->vector = v;
    this->distance = 0;
    this->name = n;
}

/**
* an empty constructor.
*/
DistanceAndName::DistanceAndName() {

}

/**
 * a getter for the my vector we have.
 * @return a getter for the my vector we have
 */
MyVector DistanceAndName::getVector() const {
    return vector;
}

/**
 * a getter for the distance we have.
 * @return the distance we have
 */
float DistanceAndName::getDistance() const {
    return distance;
}

/**
 * a function that set the distance to be from a vector we get
 * and the kind of distance we get to.
 * @param myVector the vector we get
 * @param disName the kind of distance we get
 */
int DistanceAndName::setDistance(MyVector myVector, string disName) {
    if (myVector.getV().size() != this->vector.getV().size()) {
        std::cout << "the vectors aren't in the same sizes." << std::endl;
        return 0;
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
    return 1;
}

/**
 * a getter for the name.
 * @return  the name
 */
const string DistanceAndName::getName() const {
    return name;
}