#pragma once

#include <tuple>
#include <memory>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <climits>
#include <sstream>
#include <string.h>
#include <iostream>

//#include "../header/config.h"

namespace GP
{
	class Graph
	{
		private:

			const std::string instances_path {"./src/graph_instances/"};

		public:

			Graph();
			void build_adj_list(const std::string& graph_instance_path);

		    int num_vertices {0};
			std::vector<std::vector<int>> adj_list;

			const std::vector<std::tuple<std::string, int>> graph_instances
			{
				// instance name and its best known XG
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

			std::string instance_name  {};
			int instance_xg            {0};
			int instance_count         {0};
			int instance_run_count     {0};
			int min_color              {INT_MAX};
			int current_repetition     {0};

			std::vector<int>    colors;
			std::vector<double> times;
			std::vector<double> avg_of_avg_colors;
			std::vector<double> avg_all_standad_deviation;
			std::vector<double> avg_of_avg_time;
	};
}

extern std::unique_ptr<GP::Graph> g_graph;
