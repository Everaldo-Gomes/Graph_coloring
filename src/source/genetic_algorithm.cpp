#include "../header/genetic_algorithm.h"

GA::Genetic_algorithm::Genetic_algorithm(unsigned int graph_num_vertices) : graph_num_vertices(graph_num_vertices)
{
	// +1 because the first position (0) wont be used, only from 1 to n.
	population.resize(population_num, std::vector<unsigned int> (graph_num_vertices + 1));
}


void GA::Genetic_algorithm::init_population()
{
	// summary
	// for each cromossomo (possible solution), generate random values from 1 to max quantity of vertices

	for (unsigned int i = 0; i < population_num; i++)
	{
		for (unsigned int j = 1; j <= graph_num_vertices; j++)
			population[i][j] = rand() % graph_num_vertices + 1;
	}
}


std::map<unsigned int, std::vector<unsigned int>> GA::Genetic_algorithm::objective_function(GP::Graph &graph) const
{
	// summary
	// check if adjacencies vertecies have the same color
	// count conflicts
	// return the same population with its quantity of conflicts
	
	std::map<unsigned int, std::vector<unsigned int>> evaluated_population;

	for (unsigned int i = 0; i < population_num; i++)
	{
		unsigned int conflict_count = 0;

		for (unsigned int current_vertex = 1; current_vertex <= graph_num_vertices; current_vertex++)
		{
			const unsigned int current_vertex_color = population[i][current_vertex];

			// searching in the adjacency list
			// check if the color in the vertex k is the same as its adjacancy veterx in the population
			// if so, there is a conflict
				
			for(unsigned int k = 1; k < graph.adj_list[current_vertex].size(); k++)
			{
				const unsigned int population_vertex = graph.adj_list[current_vertex][k];
					
				if (population[i][population_vertex] == current_vertex_color)
					conflict_count++;						
			}		
		}

		evaluated_population[conflict_count] = population[i];
	}
	
	return evaluated_population;
}
