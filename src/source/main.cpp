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
	remove ("../instance_results.txt");

	g_graph = std::make_unique<GP::Graph>();
	GA::Genetic_algorithm ga;

	for (size_t inst = 0; inst < 16; ++inst)
	{
		for (size_t j = 0; j < 1; ++j) // SET TO 15
		{
			auto t { g_graph->graph_instances[inst] };
			const std::string instance { std::get<0>(t) };
			
			g_graph->build_adj_list(instance);

			ga.instance_name = std::get<0>(t);
			ga.instance_xg   = std::get<1>(t);
			ga.search();		
		}
	}
	
	return 0;
}
