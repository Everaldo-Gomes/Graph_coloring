#include <time.h>
#include <iostream>

#include "../header/config.h"
#include "../header/graph.h"
#include "../header/genetic_algorithm.h"

std::unique_ptr<GP::Graph> g_graph;
std::unique_ptr<Config::System> g_sys;
Config::Execution_param g_execution_param[MAX_CONFIG_NUM];


int main (int argc, char *argv[])
{	
	std::cout << argc;
	const int instance_index = std::stoi(argv[1]);
	const std::string config = argv[2];
	const std::string exec_num = argv[3];
	
	// init graph settings
	g_graph = std::make_unique<GP::Graph>();

	auto t {g_graph->graph_instances[instance_index]};
	std::string instance_path {std::get<0>(t)};

	g_graph->build_adj_list(instance_path);
	g_graph->instance_name = instance_path.erase(0,22);
	g_graph->instance_xg   = std::get<1>(t);			

	// init system settings
	g_sys = std::make_unique<Config::System>(instance_index, config, exec_num);
	remove (g_sys->remove_file());

	// start searching
	GA::Genetic_algorithm ga;
	ga.search(); 
		
	return 0;
}
