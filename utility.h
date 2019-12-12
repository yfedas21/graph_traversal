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
		
		// IMPORTANT TO UNDERSTAND
		// (rows and columns start from 1. So, for example, 
		// if you want to get the value 7, its in the 1st row, 
		// and 8th column, but since the array also includes 0, 10, 20, etc, 
		// it is 0-indexed. So graphically, its the first row of a table, but 
		// in code, its the 0th row), use 

		// reason why the graphs were generated here was because 
		// didn't want to deal with passing large arrays between functions
		// generate random data for 10 x 10 matrix
		for (int i = 0; i < TEN; ++i) {
			for (int j = i; j < TEN; ++j)
				if (j == i) 
					ten_graph[i * TEN + j] = 0;
				else {
					ten_graph[i * TEN + j] = ten_graph[j * TEN + i] = rand() % 25;
				}
					
		}

		// EXAMPLE: HOW TO VIEW GRAPH AS 2D array
		// print the 10 x 10 matrix for debugging
		print_matrix(ten_graph, 10); 

		// create 100 x 100 matrix
		std::array<int, HUNDRED * HUNDRED> hun_graph;

		// generate adjacencies with semi-random numbers
		for (int i = 0; i < HUNDRED; ++i) {
			for (int j = i; j < HUNDRED; ++j)
				if (j == i)
					hun_graph[i * HUNDRED + j] = 0;
				else {
					hun_graph[i * HUNDRED + j] = hun_graph[j * HUNDRED + i] = rand() % 25;
				}

		}

		// create 1000 x 1000 matrix
		std::array<int, THOUSAND * THOUSAND> tho_graph;

		// generate adjacencies with semi-random numbers
		for (int i = 0; i < THOUSAND; ++i) {
			for (int j = i; j < THOUSAND; ++j)
				if (j == i)
					tho_graph[i * THOUSAND + j] = 0;
				else {
					tho_graph[i * THOUSAND + j] = tho_graph[j * THOUSAND + i] = rand() % 25;
				}

		}

		// EXAMPLE: access the graphs
		// the 10 x 10: ten_graph
		// 				hun_graph
		//				tho_graph
		
		// EXAMPLE: access the 5th element of the 7th row: (assert: value = 64)
		std::cout << ten_graph[6 * TEN + 4] << std::endl;
	}
}
