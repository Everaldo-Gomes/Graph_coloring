#include <iostream>
#include <vector>

#include "../header/graph.h"


int main ()
{
	const std::vector<std::string> graph_instances =
		{
			"./src/graph_instances/test.txt"
		};
	
	Graph graph;
	graph.build_adj_list(graph_instances[0]);

	return 0;
}
