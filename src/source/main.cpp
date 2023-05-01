#include <time.h>
#include <iostream>
#include <filesystem>

#include "../header/config.h"
#include "../header/graph.h"
#include "../header/genetic_algorithm.h"

std::unique_ptr<GP::Graph> g_graph;
std::unique_ptr<Config::System> g_sys;
Config::Execution_param g_execution_param[MAX_CONFIG_NUM];


int main (int argc, char *argv[])
{	
	std::cout << argc;
	const int instance_index   {std::stoi(argv[1])};
	const std::string config   {argv[2]};
	const std::string exec_num {argv[3]};
	
	// setting up execution config 
	g_execution_param->current_config = std::stoi(config);
	g_execution_param->current_exe    = std::stoi(exec_num);

	// setting up graph
	g_graph = std::make_unique<GP::Graph>();

	auto t {g_graph->graph_instances[instance_index]};
	std::string instance_path {std::get<0>(t)};

	g_graph->build_adj_list(instance_path);
	g_graph->instance_name  = instance_path.erase(0,22);
	g_graph->instance_xg    = std::get<1>(t);
	g_graph->instance_count = instance_index;

	// setting up system
	g_sys = std::make_unique<Config::System>(config, exec_num);
	std::filesystem::remove(g_sys->_file_name);

	// start searching
	GA::Genetic_algorithm ga;
	ga.search(); 
		
	return 0;
}