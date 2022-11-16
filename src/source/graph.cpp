#include "../header/graph.h"

GP::Graph::Graph() : num_vertices(0)
{
	
}

void GP::Graph::build_adj_list(std::string graph_instance_path)
{
	// summary
	// read the instances file in order to fill the adjacency list
	
	std::ifstream graph_instance (graph_instance_path);
	std::string line;

	while (getline(graph_instance, line))
	{
		// getting graph info
		if (line[0] == 'p')
		{
			size_t pos = 0, i = 0;
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
			}
		}

		// getting graph values to fill adjacency list
		else if (line[0] == 'e')
		{
			size_t pos = 0, i = 0, u = 0, v = 0;
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

	for(int i = 1; i<=4; i++) {
		std::cout << i << "---> ";
		std::vector<unsigned int>::iterator it;
		
		for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	graph_instance.close();
}


bool GP::Graph::is_adjacent(unsigned int &current_vertex, unsigned int &current_vertex_color) const
{
	// summary
	// search in the adjacency list if the verticies v1 and v2 are adjacency and if they have the same color

	// if they have the same color, check if they are adjacency vertices
	
	for(unsigned int i = 1; i <= num_vertices; i++)
	{
		for(unsigned int j = 0; j < adj_list[i].size(); j++)
		{
			
			std::cout << j <<"\n";
		}
		//if (adj_list[v1][i] == v2)
		// {std::cout << adj_list[v1][i] << " "<< v2 << "\n";
		// 	return true;
		// 	break;
		// }
	}

	return false;
}
