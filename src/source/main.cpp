#include <time.h>
#include <iostream>

#include "../header/config.h"
#include "../header/graph.h"
#include "../header/genetic_algorithm.h"

std::unique_ptr<GP::Graph> g_graph;
Config::Execution_param g_execution_param[MAX_CONFIG_NUM];


int main ()
{
	remove ("../instance_results.txt");
	
	g_graph = std::make_unique<GP::Graph>();

	for (int config = 0; config < MAX_CONFIG_NUM; ++config)
	{
		g_execution_param->current_config = config;
		g_graph->instance_count = 0;

		for (int inst = 0; inst < g_graph->instance_qnt; ++inst)
		{
			++g_graph->instance_count;

			for (int j = 1; j <= g_graph->max_instance_run; ++j)
			{
				++g_graph->instance_run_count;

				auto t { g_graph->graph_instances[inst] };
				std::string instance_path { std::get<0>(t) };

				g_graph->build_adj_list(instance_path);
				g_graph->instance_name = instance_path.erase(0,22);
				g_graph->instance_xg   = std::get<1>(t);			

				GA::Genetic_algorithm ga;
				ga.search(); 
			}

			g_graph->min_color         = INT_MAX;
			g_graph->best_conflict_qnt = INT_MAX;		
		}

		std::ofstream result_file("../instance_results.txt", std::ios::app);
		result_file << "================================================\n";
		result_file.close();
	}

	return 0;
}
