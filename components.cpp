#include <string>
#include <vector>
#include <iostream>

class Node{

public:
    std::vector<Component> components;

private:

};

class Component{

public:
    Component(std::string d): designator(d){
    }
    // Component(std::string d){
    //     designator = d;
    // }
    std::string designator;
    std::vector<Node> nodes;
};

int main(){
    std::string input;
    std::cin>>input;
    Component c1(input);
    std::cout<< c1.designator <<std::endl;
}

