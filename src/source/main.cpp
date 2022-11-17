#include <iostream>
 
#include "../header/graph.h"
#include "../header/genetic_algorithm.h"

int main ()
{	
	GP::Graph graph;
	graph.build_adj_list(graph.graph_instances[1]);

	GA::Genetic_algorithm ga(graph);
	ga.search();
	
	return 0;
}
