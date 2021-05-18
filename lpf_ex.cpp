#include <iostream>
#include <cmath>
#include <complex>
#include <Eigen/Dense>

using namespace Eigen;

const std::complex<double> j (0, 1.);

std::complex<double> transfer_function(double f){
    double C = pow(10, -6);
    double R = pow(10, 3);
    double omega = f * 2. * M_PI;
    return (j * omega * R * C + 1.) / (j * omega * 4. * R * C + 1.);
}

int main(){
    double R = 1e3;
    double C = 1e-6;
    double f = 1e2;
    double omega = 2 * M_PI * f;

    MatrixXcd m(4,4);
    m(0,0) = 1.;
    m(0,1) = 0.;
    m(0,2) = 0.;
    m(0,3) = 0.;

    m(1,0) = -1./(3.*R);
    m(1,1) = 1./(3.*R) + 1/R;
    m(1,2) = -1./R;
    m(1,3) = 0;

    m(2,0) = 0;
    m(2,1) = -1./R;
    m(2,2) = 1./R + j * omega * C;
    m(2,3) = -1. * j * omega * C; 
    // m(2,2) = 0;
    // m(2,3) = 0;

    m(3,0) = 0.; 
    m(3,1) = 0.;
    m(3,2) = 0.;
    m(3,3) = 1.;

    std::complex<double> vin = 1.;
    MatrixXcd i_col(4,1);
    i_col(0,0) = vin;
    i_col(1, 0) = 0.;
    i_col(2, 0) = 0.;
    i_col(3, 0) = 0.;

    int vout_index = 2;

    std::cout << m << std::endl;
    MatrixXcd m_inv = m.inverse();
    std::cout << m_inv << std::endl;
    MatrixXcd vout = m_inv.row(vout_index - 1) * i_col;

    std::cout << vout << std::endl;
    std::cout << transfer_function(f) << std::endl;
}