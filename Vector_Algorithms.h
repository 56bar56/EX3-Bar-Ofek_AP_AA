//
// Created by newba on 17/11/2022.
//

#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

#ifndef B_OPROJECT_PART2_VECTOR_ALGORITHMS_H
#define B_OPROJECT_PART2_VECTOR_ALGORITHMS_H


class Vector_Algorithms{
};
class MyVector{
private:
    std::vector<float> v; //a vector we keep in the class
public:
    MyVector(std::vector<float> v);
    MyVector();
    float euclideanDis(MyVector vOther);
    float manatenDis(MyVector vOther);
    float chebyshevDis(MyVector vOther);
    float canberraDis(MyVector vOther);
    float minkowskiDis(MyVector vOther);
    const std::vector<float> getV();
    static float checkNewFloat(string str);
    void printDis(MyVector vOther);
    void printFloat(float x);
    static vector<float> returnNewNumb(string str1);
};


#endif //B_OPROJECT_PART2_VECTOR_ALGORITHMS_H