#include <time.h>
#include <iostream>

#include "../header/config.h"
#include "../header/graph.h"
#include "../header/genetic_algorithm.h"

std::unique_ptr<GP::Graph> g_graph;
Config::Execution_param g_execution_param[MAX_CONFIG_NUM];


int main (int argc, char *argv[])
{	
	std::cout << argc;
	const int config {atoi(argv[1])};
	
	remove ("../instance_results.txt");
	
	g_graph = std::make_unique<GP::Graph>();
	
	g_execution_param->current_config = config;
	g_graph->instance_count = 0;

	for (unsigned int inst = 1; inst < g_graph->graph_instances.size(); ++inst)
	{	
		++g_graph->instance_count;
		g_graph->current_repetition = 0;
		
		bool set_header {true};

		for (int j = 1; j <= g_graph->max_instance_run; ++j)
		{
			++g_graph->instance_run_count;
			++g_graph->current_repetition;
			auto t {g_graph->graph_instances[inst]};
			std::string instance_path {std::get<0>(t)};
			g_graph->build_adj_list(instance_path);
			g_graph->instance_name = instance_path.erase(0,22);
			g_graph->instance_xg   = std::get<1>(t);			
			
			if (set_header) 
			{
				g_graph->insert_header();
				set_header = false;
			}
			GA::Genetic_algorithm ga;
			ga.search(); 
			
			g_graph->min_color = INT_MAX;
		}

		g_graph->save_colors_avg_and_standard_deviation();
	}
	
	return 0;
}
