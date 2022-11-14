#include "../header/genetic_algorithm.h"

GA::Genetic_algorithm::Genetic_algorithm(unsigned int graph_num_vertices) : graph_num_vertices(graph_num_vertices)
{
	population.resize(population_num);
}


void GA::Genetic_algorithm::init_population()
{
	// for each cromossomo (possible solution), generate random values from 1 to max quantity of vertices
	
	for (unsigned int i = 0; i < population_num; i++)
	{
		unsigned int n = graph_num_vertices;

		while (n--)
			population[i].push_back((rand() % graph_num_vertices) + 1);
	}
}


std::map<unsigned int, std::vector<unsigned int>> GA::Genetic_algorithm::objective_function() const
{
	// check if adjacencies vertecies have the same color
	// count conflicts
	// return the same population with the quantity of conflicts
	
	std::map<unsigned int, std::vector<unsigned int>> evaluated_population;

	for (unsigned int i = 0; i < population_num; i++)
	{
		for (unsigned int j = 0; j < graph_num_vertices - 1; j++)
		{
			unsigned int a = population[i][j];
			unsigned int b = population[i][j+1];

			// search in the adjacency list if the verticies j and j+1 are adjacency
			// and if they have the same color

			//...
			
		}
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
