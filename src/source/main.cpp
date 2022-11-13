#include <iostream>
#include <vector>

#include "../header/graph.h"

int main ()
{	
	Graph graph;
	graph.build_adj_list(graph.graph_instances[0]);
	
	return 0;
}
