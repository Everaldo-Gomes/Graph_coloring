#include <sstream>
#include "../header/graph.h"

GP::Graph::Graph() : adj_list(0, std::vector<int>(0))
{
}


void GP::Graph::build_adj_list(const std::string& graph_instance_path)
{
	// summary
	// read the DIMACS instances file in order to fill the adjacency list
	
	std::ifstream graph_instance_file (graph_instance_path);
	std::string line;

	while (getline(graph_instance_file, line))
	{
		// getting values to set the adjacency list
		if (line[0] == 'p')
		{
			std::string a, b;
			int v{}, e{};

			std::istringstream val(line);
			val >> a;
			val >> b;
			val >> v;
			val >> e;

			// +1 because the first position (0) won't be used.
			num_vertices = v + 1;
			adj_list.resize(num_vertices);
		}

		// getting graph values to fill adjacency list
		else if (line[0] == 'e')
		{
			std::string a{};
			int u_{}, v_{};

			std::stringstream val(line);
			val >> a;
			val >> u_;
			val >> v_;
		    
			auto u = u_;
			auto v = v_;
		    
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		} 
	}

	graph_instance_file.close();
}


void GP::Graph::insert_header()
{
	std::ofstream result_file("../instance_results.txt", std::ios::app);

	result_file << "Instance: " << g_graph->instance_name << "\n"
	     		<< "XG:       " << g_graph->instance_xg   << "\n\n";

	result_file << "Colors";
	result_file.width(10);
	result_file << "time(ms)";
	result_file.width(10);
	result_file << "config\n\n";

    result_file.close();  
}


void GP::Graph::save_colors_avg_and_standard_deviation()
{
	double avg {0.0};
 	double sum {0.0};
	double sd  {0.0};

	for (const auto &x : g_graph->colors)
		sum += x;

	avg = sum / g_graph->colors.size() -1;

	for (const auto &x : g_graph->colors)
		sd += pow(x - avg, 2);

	sd = sqrt(sd / g_graph->colors.size() -1);

	g_graph->colors.clear();

	std::ofstream result_file("../instance_results.txt", std::ios::app);

	result_file << "\n"
				<< "Average_colors:      " << avg << "\n"
				<< "Standard deviation:  " << sd  << "\n"
				<< "------------------------------\n\n";

	result_file.close();
}