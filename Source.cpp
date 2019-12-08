// the driver file
#include <iostream>
#include "../graph_traversal/utility.h" // helper file

int main() {
	// use utility function 
	int num = 0;
	std::cout << "Dijsktra output: " << utility::dijkstra(num)  << std::endl;

	// run the algorithms
	utility::run_algs();
}