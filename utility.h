#include <iostream> // for io
#include <stdio.h>  // for random number generator
#include <stdlib.h> // ""    ""     ""      ""
#include <time.h>   // seed based on time
#include <array>	// vector unnecessary because of static size

#include <algorithm> 
#include <ctime>	// for timing 

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

	// function to create an n x n graph using 1-D array
	// @inputs graph_loc: mem addr of first element 
	//		   SIZE: number of elements in array
	// @return the mem addr of graph (first element of array)
	void populate_graph(int* graph_loc, int SIZE) {
		for (int i = 0; i < SIZE; ++i) {
			for (int j = i; j < SIZE; ++j) {
				if (j == i)
					graph_loc[i * SIZE + j] = 0;
				else {
					graph_loc[i * SIZE + j] = graph_loc[j * SIZE + i] = rand() % 24 + 1;
				}
			}
		}
	}

	// print an array of any size
	void print_graph(int* arr, int LEN) {
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
	void print_upper_t(int* arr, int LEN) {
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

	// function to run algorithm comparisons
	void run_algs()
	{
		// STEP 1: GENERATE GRAPH

		// IMPORTANT TO UNDERSTAND
		// (rows and columns start from 1. So, for example, 
		// if you want to get the value 7, its in the 1st row, 
		// and 8th column, but since the array also includes 0, 10, 20, etc, 
		// it is 0-indexed. So graphically, its the first row of a table, but 
		// in code, its the 0th row), use 

		// 10 x 10 graph; remember to deallocate!
		int* ten_graph;
		ten_graph = new int[TEN * TEN];

		// populate the graph with random values (complete graph) 
		populate_graph(ten_graph, TEN); 


		// 100 x 100 graph; remember to deallocate!
		int* hun_graph;
		hun_graph = new int[HUNDRED * HUNDRED];

		populate_graph(hun_graph, HUNDRED);

		// 1000 x 1000 graph; remember to deallocate!
		int* tho_graph;
		tho_graph = new int[THOUSAND * THOUSAND];

		populate_graph(tho_graph, THOUSAND);

		// EXAMPLE: HOW TO VIEW GRAPH AS 2D array
		// print the 10 x 10 matrix for debugging
		print_graph(ten_graph, 10);


		// EXAMPLE: access the graphs
		// the 10 x 10: ten_graph
		// 				hun_graph
		//				tho_graph

		// EXAMPLE: access the 5th element of the 7th row:
		std::cout << ten_graph[6 * TEN + 4] << std::endl;

		// deallocate memory
		delete[] ten_graph; 
		delete[] hun_graph; 
		delete[] tho_graph; 
	}
}
