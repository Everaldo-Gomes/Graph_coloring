#include "../header/graph.h"
#include <iostream>

GP::Graph::Graph() : adj_list(0, std::vector<int>(0))
{
}


void GP::Graph::build_adj_list(std::string graph_instance_path)
{
	// summary
	// read the DIMACS instances file in order to fill the adjacency list
	
	std::ifstream graph_instance (graph_instance_path);
	std::string line;

	while (getline(graph_instance, line))
	{
		// getting graph info
		if (line[0] == 'p')
		{
			size_t pos {}, i {0};
			std::string value, delimiter = " ";
				
			while ((pos = line.find(delimiter)) != std::string::npos)
			{
				value = line.substr(0, pos);
				line.erase(0, pos + delimiter.length());
				++i;

				if (i == 3)
				{
					num_vertices = (size_t) stoi(value);
					adj_list.resize(num_vertices + 1);
				}						
			}
		}

		// getting graph values to fill adjacency list
		else if (line[0] == 'e')
		{
			size_t pos {}, i {0}, u {0}, v {0};
			std::string value, delimiter = " ";
				
			while ((pos = line.find(delimiter)) != std::string::npos)
			{
				value = line.substr(0, pos);
				line.erase(0, pos + delimiter.length());
				++i;
				
				if (i == 2)
				{
					u = (size_t) stoi(value);
					v = (size_t) stoi(line);
				}
			}
			
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		} 
	}

	graph_instance.close();
}
