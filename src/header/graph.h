#pragma once

#include <vector>
#include <fstream>

class Graph
{

private:

	int num_vertices;
    
public:

	Graph();
	std::vector<std::vector<int>> adj_list;

	void build_adj_list(std::string graph_instance_path);

};
