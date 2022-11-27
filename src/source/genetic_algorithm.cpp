#include "../header/genetic_algorithm.h"

// NOTE:
// Every operation that has -1. is because the list is not using the first position
// therefore it has an additional position that is not being used


GA::Genetic_algorithm::Genetic_algorithm(GP::Graph &graph) : graph(graph), generation_num(0)
{
	// +1 because the first position (0) won't be used, only from 1 to n.
	population.resize(population_num, std::vector<unsigned int> (graph.num_vertices + 1));
	init_population();
}


void GA::Genetic_algorithm::search()
{
	// summary
	// call all phases in the genetic algorithm
	
    // stop critiria
	unsigned int max_generation = 1;//700000;

	while (max_generation--) 
	{
		auto evaluated_population = objective_function();
		auto selected_population = selection(evaluated_population);		
		crossover(selected_population);
	}
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
	// return the same population with its quantity of conflicts and colors
	
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
	
	sort(evaluated_population.begin(), evaluated_population.end());
	return evaluated_population;
}


std::vector<std::vector<unsigned int>>
GA::Genetic_algorithm::selection(const std::vector<std::tuple<unsigned int, unsigned int, std::vector<unsigned int>>> &evaluated_population) const
{
	// summary
	// Get the population which only have the conflict value equal to 0

	std::vector<std::vector<unsigned int>> selected_population (population_num, std::vector<unsigned int> (graph.num_vertices + 1, 1));
	
	for (size_t i = 0; i < evaluated_population.size(); i++)
	{
		const auto t = evaluated_population[i];
		const unsigned int conflict_qnt     = std::get<1>(t);
		const std::vector<unsigned int> vec = std::get<2>(t);
		
		if (conflict_qnt == 0)
			selected_population[i] = vec;
	}

	return selected_population;
}


void GA::Genetic_algorithm::crossover(const std::vector<std::vector<unsigned int>> &selected_population)
{
	// summary
	// each pair of parents will generate two offsprings and sometimes perform mutation in one of them

	// for all offsprings
	// fill first  half with the first  parent picking randomly
	// fill second half with the second aprent picking randomly

	// index can be 0, because every cromossome has the same length
	const unsigned int selected_population_size = selected_population[0].size() - 1;
	const unsigned int first_half  = selected_population_size / 2;
	unsigned int second_half = selected_population_size;
	
	if (selected_population[0].size() - 1 != 0)
	 	second_half = selected_population_size - first_half;
	    
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
		
	
		// index of the original population, starting from the half
		unsigned int k = population.size() / 2 ;

		// mutate when reach this amount of generations
		if (generation_num == 700)
		{
			// selecting an offspring to be mutated
			const unsigned int v = rand() % graph.num_vertices + 1;
			
			if (v % 2 == 0)
				mutation(offspring_a);
			else
				mutation(offspring_b);
			
			generation_num = 0;
		}
		
		// put the offsprings in the original population from the second half to N (which is the worst population starts)
		population[k]   = offspring_a;
		population[k+1] = offspring_b;
		k += 2; 
	}

	generation_num++;
}


void GA::Genetic_algorithm::mutation(std::vector<unsigned int> &offspring) const
{
	// summary
	// change only two genes
	// pick the color that repeats more and change for the one that has less occurrences

	// count colors
	std::map<unsigned int, unsigned int> qnt;
	
	for (size_t i = 0; i < offspring.size(); i++)
	{
		const unsigned int color = offspring[i];
		qnt[color]++;
	}

	// search for the minimum and maximum color quantity
	unsigned int ma = 0, mi = UINT_MAX, color_max, color_mim;

	for (auto x : qnt)
	{
		if (ma < x.second)
		{
			ma = x.second;
			color_max = x.first;
		}

		if (mi > x.second)
		{
			mi = x.second;
			color_mim = x.first;
		}
	}
	
	// search in the offspring the first occurence of the maximum e minimum values and set the new value
	const unsigned int stop = UINT_MAX;
	unsigned int max_index = stop, mim_index = stop;
	
	for (size_t i = 0; i < offspring.size(); i++)
	{
		if (max_index != stop && mim_index != stop)
		{
			offspring[max_index] = offspring[mim_index];
			break;
		}
			
		if (offspring[i] == color_max)
			max_index = i;
		
		if (offspring[i] == color_mim)
			mim_index = i;
	}
}
