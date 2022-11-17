#include "../header/genetic_algorithm.h"

GA::Genetic_algorithm::Genetic_algorithm(GP::Graph &graph) : graph(graph)
{
	// +1 because the first position (0) wont be used, only from 1 to n.
	population.resize(population_num, std::vector<unsigned int> (graph.num_vertices + 1));
}


void GA::Genetic_algorithm::search()
{
	// summary
	// call all phases in the genetic algorithm

	init_population();
	auto evaluated_population = objective_function();

	// sorting by the number of colors in each solution
	sort(evaluated_population.begin(), evaluated_population.end());

	

	// ======================= DELETE - DEBUG ==================================

	for(int i = 1; i<=4; i++)
	{
		std::cout << i << "---> ";
		std::vector<unsigned int>::iterator it;
		
		for(it = graph.adj_list[i].begin(); it != graph.adj_list[i].end(); ++it)
			std::cout << *it << " ";

		std::cout << "\n";
	}
	std::cout << "\n\n";
	
	// print vector of tuple
	std::cout << "k c    v...\n";
	for (size_t i = 0; i < evaluated_population.size(); i++)
	{
		int k, c;
		std::vector<unsigned int> v;
		
		auto t = evaluated_population[i];

		std::tie(k, c, v) = t;
		std::cout << k << " " << c << " -> ";
		
		for (size_t i = 1; i < v.size(); i++)
			std::cout << v[i] << " " ;

		std::cout << "\n";
	}
	// ======================================================================
}


void GA::Genetic_algorithm::init_population()
{
	// summary
	// for each cromossomo (possible solution), generate random values from 1 to max quantity of vertices

	for (size_t i = 0; i < population_num; i++)
	{
		for (size_t j = 1; j <= graph.num_vertices; j++)
			population[i][j] = rand() % graph.num_vertices + 1;
	}
}


std::vector<std::tuple<unsigned int, unsigned int, std::vector<unsigned int>>> GA::Genetic_algorithm::objective_function() const
{
	// summary
	// check if adjacencies vertecies have the same color
	// count quantity of colors in each possible solution and quantity of conflicts
	// return the same population with its quantity of conflicts
	
	std::vector<std::tuple<unsigned int, unsigned int, std::vector<unsigned int>>> evaluated_population(population_num);

	for (size_t i = 0; i < population_num; i++)
	{
		std::set<unsigned int> color_qnt;
		unsigned int conflict_count = 0;

		for (size_t current_vertex = 1; current_vertex <= graph.num_vertices; current_vertex++)
		{
			const unsigned int current_vertex_color = population[i][current_vertex];
			color_qnt.insert(current_vertex_color);

			// searching in the adjacency list
			// check if the color in the vertex k is the same as its adjacancy veterx in the population
			// if so, there is a conflict
				
			for(size_t k = 0; k < graph.adj_list[current_vertex].size(); k++)
			{
				const unsigned int population_vertex = graph.adj_list[current_vertex][k];

				// population_vertex must be >= to the current_vertex
				// becuase the colors before it were already counted
				if (population_vertex >= current_vertex && population[i][population_vertex] == current_vertex_color)
					conflict_count++;		
			}		
		}

		evaluated_population[i] = std::make_tuple(color_qnt.size(), conflict_count, population[i]);
	}
    	
	return evaluated_population;
}
