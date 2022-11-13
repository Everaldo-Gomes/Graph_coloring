#include "../header/genetic_algorithm.h"

GA::Genetic_algorithm::Genetic_algorithm(unsigned short int graph_num_vertices) : graph_num_vertices(graph_num_vertices)
{
	population.resize(graph_num_vertices);
}

void GA::Genetic_algorithm::init_population()
{
	for (short int i = 0; i < population_num; i++)
	{
		std::vector<int> new_population(graph_num_vertices-130);
		
		std::iota(new_population.begin(), new_population.end(), 1);
		std::random_shuffle(new_population.begin(), new_population.end());
		
		population[i] = new_population;
	}		
}
