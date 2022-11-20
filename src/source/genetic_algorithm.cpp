#include "../header/genetic_algorithm.h"

GA::Genetic_algorithm::Genetic_algorithm(GP::Graph &graph) : graph(graph)
{
	// +1 because the first position (0) won't be used, only from 1 to n.
	population.resize(population_num, std::vector<unsigned int> (graph.num_vertices + 1));
	init_population();
}


void GA::Genetic_algorithm::search()
{
	// summary
	// call all phases in the genetic algorithm

	auto evaluated_population = objective_function();
    auto selected_population  = selection(evaluated_population);
	crossover(selected_population);
}


void GA::Genetic_algorithm::init_population()
{
	// summary
	// for each cromossome (possible solution), generate random values from 1 to max quantity of vertices

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

		evaluated_population[i] = std::make_tuple(conflict_count, color_qnt.size(), population[i]);
	}

	sort(evaluated_population.begin(), evaluated_population.end());
	return evaluated_population;
}


std::vector<std::vector<unsigned int>> GA::Genetic_algorithm::selection(const auto &evaluated_population) const
{
	// summary
	// Get the first half of the evaluated_population,
	// which contain the population with the minimum numbers of colors

	const unsigned int half = evaluated_population.size() / 2;
	std::vector<std::vector<unsigned int>> selected_population (half, std::vector<unsigned int> (graph.num_vertices + 1));

	for (size_t i = 0; i < half; i++)
	{
		auto t = evaluated_population[i];
		selected_population[i] = std::get<2>(t);
	}

	return selected_population;
}


void GA::Genetic_algorithm::crossover(const auto &selected_population)
{
	// summary:
	// each pair of parents will generate two offsprings and sometimes perform mutation in one of them

	
	// size of each cromossome. can be index 0, beucase every cromossome has the same length
	const unsigned int first_half  = selected_population[0].size() / 2;
	const unsigned int second_half = selected_population[0].size() / 2 + 1;
	
	// index of the original population, starting from the half
	unsigned int k = population.size() / 2 ;

	// for each parent, divided it in two halves
	// pick genes randomly from the parent A to form the first  half of the offspring A
	// pick genes randomly from the parent B to form the second half of the offspring A
	// pick genes randomly from the parent B to form the first  half of the offspring B
	// pick genes randomly from the parent A to form the second half of the offspring B

	for (size_t parent_index = 0; parent_index < selected_population.size() - 1; parent_index += 2)
	{
		std::vector<unsigned int> offspring_a, offspring_b;
		unsigned int gene_index = 0, gene = 0;

		// first half offspring A 
		for (size_t h1 = 0; h1 < first_half; h1++)
		{
			gene_index = rand() % graph.num_vertices + 1;
			gene = selected_population[parent_index][gene_index];
			offspring_a.push_back(gene);
		}

		// second half offspring A 
		for (size_t h2 = 0; h2 < second_half; h2++)
		{
			gene_index = rand() % graph.num_vertices + 1;
			gene = selected_population[parent_index+1][gene_index];
			offspring_a.push_back(gene);
			
		}

		// first half offspring B 
		for (size_t h1 = 0; h1 < first_half; h1++)
		{
			gene_index = rand() % graph.num_vertices + 1;
			gene = selected_population[parent_index+1][gene_index];
			offspring_b.push_back(gene);
		}

		// second half offspring B 
		for (size_t h2 = 0; h2 < second_half; h2++)
		{
			gene_index = rand() % graph.num_vertices + 1;
			gene = selected_population[parent_index][gene_index];
			offspring_b.push_back(gene);
		}
		
		// muatation
		
		// put the offsprings in the original population from the second half to N (which is the worst population starts)
		population[k]   = offspring_a;
		population[k+1] = offspring_b;
		k += 2;
	}
}
