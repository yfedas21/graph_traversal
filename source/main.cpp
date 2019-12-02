// the driver file

#include <iostream>
#include "..\headers\utility.h"


int main() {
    std::cout << "Hello, world!" << std::endl;

    // use utility function 
    int num = 0;
    std::cout << "Dijsktra output: " << utility::dijkstra(num) << std::endl;
}