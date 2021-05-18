#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <vector>

//defining "j"
const std::complex<double> j (0, 1.);

//LPF filter for testing
std::complex<double> transfer_function(double f){
    double C = pow(10, -6);
    double R = pow(10, 3);
    double omega = f * 2. * M_PI;
    return (j * omega * R * C + 1.) / (j * omega * 4. * R * C + 1.);
}

//convert magnitude to dB
double conv_dB(double x){
    return 20. * log10(x);
}

int main(){
    // create a new file
    std::ofstream myfile("simdata.csv");

    //output settings
    const int upper_lim = 1.0e7;
    const int samples_decade = 20;
    int num_decades = log10(upper_lim);

    //output loop
    for(int i = 0; i < num_decades; i++){
        double f = pow(10, i);
        for(int ii = 0; ii < samples_decade; ii++){
            std::complex<double> val = transfer_function(f);
            myfile << f << "," << conv_dB(abs(val)) << "," << arg(val) << "\n";
            f = f * pow(10, 1. / samples_decade);
        }
    }
    myfile.close();
}