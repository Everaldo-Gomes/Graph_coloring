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
			population[i][j] = rand() % graph_num_vertices;
	}
}


std::map<unsigned int, std::vector<unsigned int>> GA::Genetic_algorithm::objective_function(GP::Graph &graph) const
{
	// summary
	// check if adjacencies vertecies have the same color
	// count conflicts
	// return the same population with the quantity of conflicts

	std::map<unsigned int, std::vector<unsigned int>> evaluated_population;
	
	for (unsigned int i = 0; i < population_num; i++)
	{	
		unsigned int conflict_count = 0;
		
		for (unsigned int current_vertex = 1; current_vertex <= graph_num_vertices; current_vertex++)
		{
			for (unsigned int next_vertex = 1; next_vertex <= graph_num_vertices; next_vertex++)
			{
				unsigned int current_vertex_color = population[i][current_vertex];
				conflict_count += graph.is_adjacent(current_vertex, current_vertex_color) ? 1 : 0;
			}
		}

		std::cout << conflict_count << "\n";
		//evaluated_population[conflict_count] = population[i];
	}
	
	return evaluated_population;
}


/*
for (unsigned int i = 0; i < population_num; i++)
	{
		
		for (auto x : population[i])
			std::cout <<  x << " ";
		std::cout << "\n";
	}
*/
