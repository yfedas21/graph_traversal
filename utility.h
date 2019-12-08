#include <iostream> // for io
#include <stdio.h>  // for random number generator
#include <stdlib.h> // ""    ""     ""      ""
#include <time.h>   // seed based on time
#include <array>	// vector unnecessary because of static size

	// define the graph sizes as constants
	// to generate 2D arrays
#define TEN		10
#define HUNDRED 100
#define THOUSAND 1000
#define INF 1000000000	// define inf as large unsigned int

// file that holds the different algorithm code

namespace utility {
	// sample subroutine format,
	// change as you see fit
	int dijkstra(int number) {
		return(++number);
	}

	// print an array of any size
	template<std::size_t SIZE>
	void print_matrix(std::array<int, SIZE> arr, int LEN) {
		// debug function; see whats in the array
		//for (int i = 0; i < ten_graph.size(); ++i)
		//	std::cout << ten_graph[i] << std::endl;

		// print in array style
		for (int i = 0; i < LEN; ++i) {
			std::cout << "< ";
			for (int j = 0; j < LEN; ++j)
				std::cout << arr[i * LEN + j] << " ";
			std::cout << ">" << std::endl;
		}
	}

	// print upper triangular including main diagonal 
	template<std::size_t SIZE>
	void print_upper_t(std::array<int, SIZE> arr, int LEN) {
		// debug function; see whats in the array
		//for (int i = 0; i < ten_graph.size(); ++i)
		//	std::cout << ten_graph[i] << std::endl;

		// print in array style
		for (int i = 0; i < LEN; ++i) {
			std::cout << "< ";
			for (int j = i; j < LEN; ++j)
				std::cout << arr[i * LEN + j] << " ";
			std::cout << ">" << std::endl;
		}
	}

	// function to input random data into graphs of arbitrary size
	template<std::size_t SIZE>
	void input_rand_data(std::array<int, SIZE> arr, int LEN) {
		// use rand() % 25 to get weights between 0 to 25
		for (int i = 0; i < LEN; ++i) {
			std::cout << "< ";
			for (int j = i; j < LEN; ++j)
				arr[i * LEN + j] = rand() % 25;
			std::cout << ">" << std::endl;
		}
	}

	// function to run algorithm comparisons
	void run_algs()
	{
		// STEP 1: GENERATE GRAPH
		// 10 ROWS by 10 COLUMNS graph  (PAY ATTENTION TO ROW/COL ORDER!!!)
		//				ROW * COL
		std::array<int, TEN * TEN> ten_graph;

		// insert values into graph
		for (int i = 0; i < ten_graph.size(); ++i)
			ten_graph[i] = i;
		
		// IMPORTANT TO UNDERSTAND
		// (rows and columns start from 1. So, for example, 
		// if you want to get the value 7, its in the 1st row, 
		// and 8th column, but since the array also includes 0, 10, 20, etc, 
		// it is 0-indexed. So graphically, its the first row of a table, but 
		// in code, its the 0th row), use 
		print_matrix(ten_graph, TEN);
		print_upper_t(ten_graph, TEN);

		// generate random data for 10 x 10 matrix
		for (int i = 0; i < TEN; ++i) {
			for (int j = i; j < TEN; ++j)
				if (j == i) 
					ten_graph[i * TEN + j] = 0;
				else {
					ten_graph[i * TEN + j] = ten_graph[j * TEN + i] = rand() % 25;
				}
					
		}

		std::cout << "\n\n\n";
		print_matrix(ten_graph, TEN); 


		// EXAMPLE
		// to access the 5th element of the 7th row: (assert value = 64)
		std::cout << ten_graph[6 * TEN + 4] << std::endl;
	}
}
