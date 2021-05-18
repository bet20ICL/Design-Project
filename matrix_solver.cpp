#include <iostream>
#include <cmath>
#include <Eigen/Dense>

// #include "helloworld.h"
using Eigen::MatrixXd;

int main(){
    std::cout<<"Hello World"<<std::endl;
    // helloworld();

    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
    std::cout << m.inverse() << std::endl;
    MatrixXd m1(2,2);
    m1(0,0) = 1;
    m1(1,0) = 3;
    m1(0,1) = 2;
    m1(1,1) = 4;
    std::cout << m1 << std::endl;
    std::cout << m1.inverse() << std::endl;
}