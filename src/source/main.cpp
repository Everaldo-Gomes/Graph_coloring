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
	g_graph->build_adj_list(g_graph->graph_instances[0]);

	GA::Genetic_algorithm ga;
	ga.search();
	
	return 0;
}
