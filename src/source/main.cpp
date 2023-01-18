#include <time.h>
#include <iostream>
 
#include "../header/graph.h"
#include "../header/genetic_algorithm.h"


std::unique_ptr<GP::Graph> g_graph;


int main ()
{
	// used to prevent the random number from being the same every time the program is run
	// using the return value of time as seed
	srand(time(0));
	
	g_graph = std::make_unique<GP::Graph>();
	GA::Genetic_algorithm ga;
	
	// for each instance repeat N times
	for (size_t inst = 0; inst < 16; ++inst)
	{
		for (size_t j = 0; j < 15; ++j)
		{
			g_graph->build_adj_list(g_graph->graph_instances[inst]);
			ga.search();		
		}
	}

	
	return 0;
}
