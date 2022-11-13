#include <iostream>
 
#include "../header/graph.h"
#include "../header/genetic_algorithm.h"

int main ()
{	
	GP::Graph graph;
	graph.build_adj_list(graph.graph_instances[0]);

	GA::Genetic_algorithm ga(graph.num_vertices);
	ga.init_population();
	
	return 0;
}
