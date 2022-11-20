#include <iostream>
#include <time.h>
 
#include "../header/graph.h"
#include "../header/genetic_algorithm.h"

int main ()
{
	// used to prevent the random number from being the same every time the program is run
	// using using the return value of time as seed
	srand(time(0));
	
	GP::Graph graph;
	graph.build_adj_list(graph.graph_instances[0]);

	GA::Genetic_algorithm ga(graph);
	ga.search();
	
	return 0;
}
