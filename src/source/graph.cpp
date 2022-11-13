#include "../header/graph.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

Graph::Graph() : num_vertices(0)
{
	
}

void Graph::build_adj_list(std::string graph_instance_path)
{
	std::ifstream graph_instance (graph_instance_path);
	std::string line;
	bool configured = false;
    
	while (getline(graph_instance, line))
	{
		if (line[0] == 'p')
		{
			// getting graph info
			if (!configured)
			{
				int pos = 0, i = 0;
				std::string value, delimiter = " ";
				
				while ((pos = line.find(delimiter)) != std::string::npos)
				{
					value = line.substr(0, pos);
					line.erase(0, pos + delimiter.length());
					i++;

					if (i == 3)
					{
						num_vertices = stoi(value);
						adj_list.resize(stoi(line));
					}
						
					configured = true;
				}
			}
		}

		// getting graph values && fill adjacency list
		else if (line[0] == 'e')
		{
			int pos = 0, i = 0, u = 0, v = 0;
			std::string value, delimiter = " ";
				
			while ((pos = line.find(delimiter)) != std::string::npos)
			{
				value = line.substr(0, pos);
				line.erase(0, pos + delimiter.length());
				i++;
				
				if (i == 2)
				{
					u = stoi(value);
					v = stoi(line);
				}
			}
			
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
	}

	graph_instance.close();
}
