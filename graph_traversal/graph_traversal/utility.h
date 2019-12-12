#include <iostream> // for io
#include <stdio.h>  // for random number generator
#include <stdlib.h> // ""    ""     ""      ""
#include <time.h>   // seed based on time
#include <array>	// vector unnecessary because of static size
#include <vector>

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

	// compute the trasitive property of a graph using warshalls algorithm
	// checks all intermediary nodes and updates given weight matrix if there is a shorter path between nodes
	// @input arr: the starting memory address of array; LEN the length of a row or column in a weighted adjacency matrix;
	void warshalls(int* arr, int LEN) {
		int i, j, k;

		// add the set of intermediate vertices/nodes
		for (i = 0; i < LEN; i++) {
			// pick a vertex as the source one by one
			for (j = 0; j < LEN; j++) {
				// pick all vertices as destination nodes for previously selected sources
				for (k = 0; k < LEN; k++) {
					// checks if the source->intermediate + intermediate->dest is less costly than known minimum cost from source->dest
					if ((arr[j * LEN + i] != INF && arr[i * LEN + k] != INF)  && (arr[j * LEN + i] + arr[i * LEN + k] < arr[j * LEN + k])) {
						arr[j * LEN + k] = arr[j * LEN + i] + arr[i * LEN + k];
					}
				}
			}
		}
	}

	// &&&&&&&&&&&&&&& Dijkstra implementation &&&&&&&&&&&&&&&&&&&&&&
	// Yuriy 
	// all sources dijstra's algorithm
	// @input graph: the start mem addr; NUM_VERTS: the # of V's
	int all_dijkstra(int* graph, int NUM_VERTS) {

		// ********************* put timing in here *************************************

		// run dijsktra's algorithm on every source node 
		for (int i = 0; i < NUM_VERTS; ++i) {
			//dijkstra(graph, NUM_VERTS, i); 
		}

		return 0; 
	}

	// calculate the minimum distance between vertex with min distance value 
	// from the set not already in the tree
	int min_dist(std::vector<int> costs, std::vector<bool> sp_tree, int SIZE) {
		int min = INF, min_index;
	
		// compare values of min with current min
		for (int i = 0; i < SIZE; ++i) {
			if (sp_tree.at(i) == false && costs.at(i) <= min)
				min = costs.at(i), min_index = i; 
		}
			
		std::cout << " min_index is " << min_index << std::endl;

		return min_index; 
	}

	// dijstra's algorithm on single source
	// @input graph: the mem addr of graph, SIZE: the # of V's
	//		  src: 0-indexed source (ie first elemnt is graph[0]
	void dijkstra(int* graph, int SIZE, int src) {
		// create vector that holds vertices included
		// in the shortest path tree
		std::vector<bool> sp_tree(SIZE, false); 

		// distance to all nodes; init to INF besides the source
		std::vector<int> dist(SIZE, INF); 
		// set the source node to cost 0 so it gets picked 

		dist.at(src) = 0; // lowest cost

		// src is cost 0, included in sp_tree
		//sp_tree.at(src) = true; 

		// for every vertex in the graph 
		for (int v = 0; v < SIZE - 1; ++v) {
			int min = min_dist(dist, sp_tree, SIZE);

			// mark as picked 
			sp_tree.at(min) = true;

			// implementation
			for (int vv = 0; vv < SIZE; ++vv) {
				if (!sp_tree.at(vv) && graph[min * SIZE + vv] && dist.at(min) != INF
					&& dist.at(min) + graph[min * SIZE + vv] < dist.at(vv))
					dist.at(vv) = dist.at(min) + graph[min * SIZE + vv];
			}
		}

		// print costs[], debug function 
		// for (int j = 0; j < dist.size(); ++j)
		// 	std::cout << "j is " << j << " and costs.at(j) is " << dist.at(j) << std::endl;
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

		// populate 100 * 100 graph with rand values 
		populate_graph(hun_graph, HUNDRED);

		// 1000 x 1000 graph; remember to deallocate!
		int* tho_graph;
		tho_graph = new int[THOUSAND * THOUSAND];

		// populate 1000 * 1000 graph with random values 
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


		warshalls(ten_graph, 10);


		// deallocate memory
		delete[] ten_graph; 
		delete[] hun_graph; 
		delete[] tho_graph; 
	}
}
