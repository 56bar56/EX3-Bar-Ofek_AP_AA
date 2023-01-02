//
// Created by Bar and Ofek on 17/11/2022.
//

#include "Vector_Algorithms.h"
using namespace std;

/**
 * a constructor for the class.
 * @param v the vector we get to put in the object
 */
MyVector::MyVector(std::vector<float> v) {
    this->v = v;
}
MyVector::MyVector() {
}

/**
* we will calculate the euclidean distance we formula.
* @param vOther the other vector we need to find our distance from her
* @return  the distance
*/
float MyVector::euclideanDis(MyVector vOther) {
    float result;
    float sum = 0;
    for (int i = 0; i < this->v.size(); i++) {
        sum += pow(abs(this->v[i] - vOther.getV()[i]), 2);
    }
    result = sqrt(sum);
    return result;
}

/**
* we will calculate the manaten distance we formula.
* @param vOther the other vector we need to find our distance from her
* @return  the distance
*/
float MyVector::manatenDis(MyVector vOther) {
    float sum = 0;
    for (int i = 0; i < this->v.size(); i++) {
        sum += abs(this->v[i] - vOther.getV()[i]);
    }
    return sum;
}

/**
* we will calculate the chebyshev distance we formula.
* @param vOther the other vector we need to find our distance from her
* @return  the distance
*/
float MyVector::chebyshevDis(MyVector vOther) {
    float sum = 0;
    for (int i = 0; i < this->v.size(); i++) {
        sum = max(abs(this->v[i] - vOther.getV()[i]), sum);
    }
    return sum;
}

/**
* we will calculate the canberra distance we formula.
* @param vOther the other vector we need to find our distance from her
* @return  the distance
*/
float MyVector::canberraDis(MyVector vOther) {
    float sum = 0;
    for (int i = 0; i < this->v.size(); i++) {
        if (this->v[i] == 0 && vOther.getV()[i] == 0) {
            std::cout << "we cant find the Canberra distance because we can't divide with 0 " << std::endl;
            i = this->v.size();
            sum = -1;//defult value

        } else {
            sum += abs(this->v[i] - vOther.getV()[i]) / (abs(this->v[i]) + abs(vOther.getV()[i]));

        }
    }
    return sum;
}

/**
* we will calculate the minkowski distance we formula.
* @param vOther the other vector we need to find our distance from her
* @return  the distance
*/
float MyVector::minkowskiDis(MyVector vOther) {
    float sum = 0;
    double p = 2; //this method use a number bigger than 1 we choose 2.
    for (int i = 0; i < this->v.size(); i++) {
        sum += pow(abs(this->v[i] - vOther.getV()[i]), p);
    }
    sum = pow(sum, 1 / p);
    return sum;
}

/**
* a getter for v.
* @return the v of our my vector
*/
const std::vector<float> MyVector::getV() {
    return this->v;
}

/**
* this function print all the distance we been told to find between 2 vectors.
* @param vOther the other vector
*/
void MyVector::printDis(MyVector vOther) {
    std::cout << setprecision(15);
    printFloat(this->euclideanDis(vOther));
    printFloat(this->manatenDis(vOther));
    printFloat(this->chebyshevDis(vOther));
    if (this->canberraDis(vOther) != -1) { //we check if we get legal number from the function
        printFloat(this->canberraDis(vOther));
    }
    printFloat(this->minkowskiDis(vOther));
}

/**
* a function that print float in the rules we choose.
* @param x the float we print
*/
void MyVector::printFloat(float x) {
    float x1 = x;
    std::cout << fixed;
    int i = 1;
    while (true) {
        if (x1 == (int) x1) {
            std::cout << setprecision(i); //in case that the number is Integer we print i number after the point
            break;
        } else {
            if (i == 8) {//the maximum precision will be 8
                break;
            } else {
                i++;
                x1 = x1 * 10;
            }
        }
    }
    std::cout << x << std::endl;

}

/**
 * this function get a string that should represent a float number
 * and we check if it is a legal number and return the number.
 * @param str string that represent a number
 * @return the number
 */
float MyVector::checkNewFloat(string str) {
    int i;
    int numberOfPoints = 0;
    int counterE=0;
    for (i = 0; i < str.size(); i++) {
        if (str[i] == '.') { //we check how many points we had
            numberOfPoints++;
        }
        if (str[i] == '-') {//we check if we add - in wrong place
            if (i != 0) {
                if(str[i-1]!='E') {
                    cout << "invalid input";
                    exit(1);
                }
            }
        }
        if(str[i]=='E') {
            counterE++;
            if(i==0||i==str.size()-1) {
                cout << "invalid input";
                exit(1);
            }
        }
    }
    if (numberOfPoints > 1) { // we cant have more than one point
        cout << "invalid input";
        exit(1);
    }
    if (counterE > 1) { // we cant have more than one E
        cout << "invalid input";
        exit(1);
    }
    return std::stof(str);
}

/**
* get the string of the line we get and change it to a vector.
* @param str1 the line we get
* @return the new vector
*/
vector<float> MyVector::returnNewNumb(string str1) {
    string num_vec = "";
    float num;
    int i = 0;
    std::vector<float> g1;
    while (i < str1.size()) { //move on the string we get
        while (str1[i] == ' ') {
            i++;
        }
        while (str1[i] != ' ' && i < str1.size()) {
            if (!(isdigit(str1[i]) || str1[i] == '-' || str1[i] == '.'||str1[i]=='E')) { //if we have a char we can't get
                cout << "invalid input";
                exit(1);
            }
            num_vec += str1[i];
            i++;
        }
        if (num_vec != "") {
            num = checkNewFloat(num_vec);
            g1.push_back(num);
            num_vec = "";
        }

    }
    return g1;
}