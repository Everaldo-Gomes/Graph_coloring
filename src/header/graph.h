#pragma once

#include <memory>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>

namespace GP
{
	class Graph
	{

	private:
		
		const std::string instances_path {"./src/graph_instances/"};

	public:
		
		Graph();
		void build_adj_list(std::string graph_instance_path);

		size_t num_vertices {0};
		std::vector<std::vector<int>> adj_list;
		
		const std::vector<std::string> graph_instances
		{
			instances_path + "0_test.col",
			instances_path + "anna.col",
			instances_path + "david.col",
			instances_path + "DSJC500.9.col",
			instances_path + "DSJC1000.9.col",
			instances_path + "flat300_28_0.col",
			instances_path + "flat1000_76_0.col",
			instances_path + "fpsol2.i.1.col",
			instances_path + "games120.col",
			instances_path + "homer.col",
			instances_path + "huck.col",
			instances_path + "jean.col",
			instances_path + "miles250.col",
			instances_path + "miles500.col",
			instances_path + "miles1000.col",
			instances_path + "myciel3.col",
			instances_path + "myciel4.col",
			instances_path + "myciel5.col",  
			instances_path + "myciel6.col",  
			instances_path + "myciel7.col",
			instances_path + "queen5_5.col",
			instances_path + "queen6_6.col",
			instances_path + "queen7_7.col",
			instances_path + "queen8_8.col",
		}; 
	};
}

extern std::unique_ptr<GP::Graph> g_graph;
