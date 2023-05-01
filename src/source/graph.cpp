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