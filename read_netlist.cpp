#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

//takes in a string e.g. val = 100Meg and returns the number it represents
double get_num_value(std::string val){
    //i is the index of the last character in the numerical part of the value
    //e.g. val = 100Meg, i = 2
    int i = val.size() - 1;
    while(!isdigit(val[i])){
        i--;
    }

    //numerical part of the value and suffix
    double num_val = std::stod(val.substr(0, i + 1));
    std::string suffix = val.substr(i + 1);

    //find the appropriate multiplier for the suffix
    double multiplier = 1;
    if(suffix == "p"){
        multiplier = 1e-12;
    } else if(suffix == "n"){
        multiplier = 1e-9;
    } else if(suffix == "u"){
        multiplier = 1e-6;
    } else if(suffix == "m"){
        multiplier = 1e-3;
    } else if(suffix == "k"){
        multiplier = 1e3;
    } else if(suffix == "Meg"){
        multiplier = 1e6;
    } else{
        std::cout<<"Error: unrecognised component value"<<std::endl;
    }
    return num_val * multiplier;
}

void print_vector(std::vector<std::string> in){
    for(int i = 0; i < in.size(); i++){
        std::cout<<in[i] + " ";
    }
    std::cout<<std::endl;
}

int main(){
    std::ifstream infile;
    infile.open("netlistex1.txt");
    if(!infile.is_open()){
        std::cout<<"Error opening file"<<std::endl;
        return EXIT_FAILURE;
    }
    std::string line;
    std::string delim = " ";
    while(std::getline(infile, line)){
        std::string component = "";
        std::string name;
        std::vector<std::string> nodes;
        int num_nodes = 2;
        std::string value;
        std::vector<std::string> info;

        std::size_t pos = 0;
        while((pos = line.find(delim)) != std::string::npos){
            info.push_back(line.substr(0,pos));
            line.erase(0,pos + delim.size());
        };
        info.push_back(line);

        for(int i = 0; i < info.size(); i++){
            std::cout<< info[i] <<std::endl;
        };
        name = info[0];
        if(name == ".ac"){
            
        } else{
            switch (name[0]){
                case 'V':
                    component = "Voltage Source";
                    break;
                case 'I':
                    component = "Current Source";
                    break;
                case 'R':
                    component = "Resistor";
                    break;
                case 'C':
                    component = "Capacitor";
                    break;
                case 'L':
                    component = "Inductor";
                    break;
                case 'D':
                    component = "Diode";
                    break;
                case 'Q':
                    component = "BJT";
                    num_nodes = 3;
                    break;
                case 'M':
                    component = "MOSFET";
                    num_nodes = 3;
                    break;
                case 'G':
                    component = "Voltage-controlled Current Souce";
                    num_nodes = 4;
                    break;
                default:
                    component = "Not a component";
                }
            for(int i = 1; i <= num_nodes; i++){
                nodes.push_back(info[i]);
            }
            
        }
        // std::cout<< component + " " + name + " value: " + value << std::endl;
    };
}