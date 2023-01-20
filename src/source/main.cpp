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

	for (int inst = 0; inst < g_graph->instance_qnt; ++inst)
	{
		++g_graph->instance_count;
		g_graph->instance_run_count = 1;

		for (int j = 0; j < g_graph->max_instance_run; ++j)
		{	
			auto t { g_graph->graph_instances[inst] };
			std::string instance_path { std::get<0>(t) };
			
			g_graph->build_adj_list(instance_path);
			g_graph->instance_name = instance_path.erase(0,22);
			g_graph->instance_xg   = std::get<1>(t);			

			GA::Genetic_algorithm ga;
			ga.search();

			++g_graph->instance_run_count;
		}
	}

	return 0;
}
