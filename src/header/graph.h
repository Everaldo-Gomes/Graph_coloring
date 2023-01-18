#pragma once

#include <map>
#include <memory>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>

namespace GP
{
	class Graph
	{

	private:
		
		const std::string instances_path {"./src/graph_instances/"};

	public:
		
		Graph();
		void build_adj_list(std::string graph_instance_path);

	    int num_vertices {0};
		std::vector<std::vector<int>> adj_list;

		const std::map<std::string, int> graph_instances
		{
			{instances_path + "0_test.col",      2},
			{instances_path + "anna.col",       11},
			{instances_path + "david.col",      11},
			{instances_path + "fpsol2.i.1.col", 65},
			{instances_path + "games120.col",    9},
			{instances_path + "homer.col",      13},
			{instances_path + "huck.col",       11},
			{instances_path + "jean.col",       10},
			{instances_path + "miles250.col",    8},
			{instances_path + "miles1000.col",  42},
			{instances_path + "myciel3.col",     4},
			{instances_path + "myciel4.col",     5},
			{instances_path + "queen5_5.col",    5},
			{instances_path + "queen6_6.col",    7},
			{instances_path + "queen7_7.col",    7},
			{instances_path + "queen8_8.col",    9}
		};
		/*
		const std::vector<std::string> graph_instances
		{
			instances_path + "0_test.col",
			instances_path + "anna.col",
			instances_path + "david.col",
			instances_path + "fpsol2.i.1.col",
			instances_path + "games120.col",
			instances_path + "homer.col",
			instances_path + "huck.col",
			instances_path + "jean.col",
			instances_path + "miles250.col",
			instances_path + "miles1000.col",
			instances_path + "myciel3.col",
			instances_path + "myciel4.col",
			instances_path + "queen5_5.col",
			instances_path + "queen6_6.col",
			instances_path + "queen7_7.col",
			instances_path + "queen8_8.col",
			}; */
	};
}

extern std::unique_ptr<GP::Graph> g_graph;
