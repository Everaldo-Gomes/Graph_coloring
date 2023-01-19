#include "../header/genetic_algorithm.h"

// NOTE:
// Every operation that has -1. is because the list is not using the first position
// therefore it has an additional position that is not being used


GA::Genetic_algorithm::Genetic_algorithm()
{   
	population.resize(population_num, std::vector<int> (g_graph->num_vertices));
}


void GA::Genetic_algorithm::search()
{
	// summary
	// call all phases in the genetic algorithm
    // stop critiria: in seconds or reach the best known value
	// time is given in seconds
	
	auto start {std::chrono::high_resolution_clock::now()};
	constexpr int time_limit {1};//120
	
	init_population();
	
	while (true) 
	{
		//auto evaluated_population = objective_function();
		// 	auto selected_population  = selection(evaluated_population);
		// 	crossover(selected_population);
		
		auto stop     {std::chrono::high_resolution_clock::now()};
		auto duration {std::chrono::duration_cast<std::chrono::seconds>(stop - start)};

		static int instance_num {1};
		
		std::system("clear");
		std::cerr << "Instance:  " << instance_name << " [" << instance_num << "/16]\n"
				  << "XG:        " << instance_xg   << "\n"
				  << "Conflicts: " << conflict_qnt  << "\n"
				  << "Colors:    " << min_color     << "\n"
				  << "Time:      " << duration.count() << "/" << time_limit << " secs\n";
		
		if (duration >= std::chrono::seconds(time_limit) || min_color == instance_xg)
		{
			std::ofstream result_file ("../instance_results.txt", std::ios::app);
			
			result_file << "Instance:  " << instance_name << " [" << instance_num << "/16]\n"
						<< "XG:        " << instance_xg   << "\n"
						<< "Conflicts: " << conflict_qnt  << "\n"
						<< "Colors:    " << min_color     << "\n"
						<< "Time:      " << duration.count() << "/" << time_limit << " secs\n\n";

			result_file.close();
			++instance_num;
			break;
		}
	}
}


void GA::Genetic_algorithm::init_population()
{
	// summary
	// for each cromossome (possible solution), generate random values from 1 to max quantity of vertices

	std::vector<int> nums (g_graph->num_vertices + 1);
	std::iota(nums.begin(), nums.end(), 1);
	
	for (int i = 0; i < population_num; ++i)
	{
		std::random_shuffle(nums.begin(), nums.end());	
		population[i] = nums;
	}
}

/*
std::vector<std::tuple<int, int, std::vector<int>>> GA::Genetic_algorithm::objective_function() const
{
	// summary
	// check if adjacencies vertecies have the same color
	// count the quantity of colors in each possible solution and the quantity of conflicts (if any)
	// return the same population with its quantity of conflicts and colors
	
	std::vector<std::tuple<int, int, std::vector<int>>> evaluated_population(population_num);

	for (int i = 0; i < population_num; ++i)
	{
		std::set<int> color_qnt;
		int conflict_count {0};

		for (int current_vertex = 1; current_vertex <= g_graph->num_vertices; ++current_vertex)
		{
			const int current_vertex_color = population[i][current_vertex];
			color_qnt.insert(current_vertex_color);

			// searching in the adjacency list
			// check if the color in the vertex k is the same as its adjacancy veterx in the population
			// if so, there is a conflict
				
			for(int k = 0; k < g_graph->adj_list[current_vertex].size(); ++k)
			{
				const int population_vertex = g_graph->adj_list[current_vertex][k];

				// population_vertex must be >= to the current_vertex
				// because the colors before it were already counted
				if (population_vertex >= current_vertex && population[i][population_vertex] == current_vertex_color)
					++conflict_count;		
			}		
		}
		
		evaluated_population[i] = std::make_tuple(color_qnt.size(), conflict_count, population[i]);
	}

	sort(evaluated_population.begin(), evaluated_population.end());
	return evaluated_population;
}


std::vector<std::vector<int>>
GA::Genetic_algorithm::selection(const std::vector<std::tuple<int, int, std::vector<int>>> &evaluated_population)
{
	// summary
	// Get the population which only have the conflict value equal to 0

	std::vector<std::vector<int>> selected_population (population_num, std::vector<int> (graph.num_vertices + 1, 1));
	
	for (int i = 0; i < evaluated_population.size(); i++)
	{
		const auto t = evaluated_population[i];
		const  conflict_num = std::get<1>(t);
		const std::vector<int> vec = std::get<2>(t);

		if (min_color > std::get<0>(t) && conflict_num == 0)
		{
			min_color = std::get<0>(t);
			conflict_qnt = conflict_num;
		}
			
		if (conflict_num <= 10)
			selected_population[i] = vec;
	}

	return selected_population;
}


void GA::Genetic_algorithm::crossover(std::vector<std::vector<int>>& selected_population)
{
	// summary
	// each pair of parents will generate two offsprings and sometimes perform mutation in one of them

	// for all offsprings
	// fill first  half with the first  parent picking randomly
	// fill second half with the second aprent picking randomly
	
	//!!!!!!!!!!!!!!!!
	// try to change the seed in the main file here to see there's any change
	//!!!!!!!!!!!!!!!

	// index can be 0, because every cromossome has the same length
	const int selected_population_size = selected_population[0].size() - 1;
	const int first_half {selected_population_size / 2};
	int second_half {selected_population_size};
	
	if (selected_population[0].size() - 1 != 0)
	 	second_half = selected_population_size - first_half;
	    
	for (int parent_index = 0; parent_index < selected_population.size() - 1; parent_index += 2)
	{
		std::vector<int> offspring_a, offspring_b;
		int gene_index {}, gene {};
		
		// first half offspring A 
		for (int h1 = 0; h1 < first_half; h1++)
		{
			gene_index = (int) rand() % graph.num_vertices + 1;
			gene = selected_population[parent_index][gene_index];
			offspring_a.push_back(gene);
		}

		// second half offspring A 
		for (int h2 = 0; h2 < second_half; h2++)
		{
			gene_index = (int) rand() % graph.num_vertices + 1;
			gene = selected_population[parent_index+1][gene_index];
			offspring_a.push_back(gene);
		}

		// first half offspring B
		for (int h1 = 0; h1 < first_half; h1++)
		{
			gene_index = (int) rand() % graph.num_vertices + 1;
			gene = selected_population[parent_index+1][gene_index];
			offspring_b.push_back(gene);
		}

		// second half offspring B 
		for (int h2 = 0; h2 < second_half; h2++)
		{
			gene_index = (int) rand() % graph.num_vertices + 1;
			gene = selected_population[parent_index][gene_index];
			offspring_b.push_back(gene);
		}
		
	
		// index of the original population, starting from the half
		int k = population.size() / 2;

		// mutate when reach this amount of generations
		if (generation_num == 200)
		{
			// selecting an offspring to be mutated
			const int v = (int) rand() % graph.num_vertices + 1;
			
			if (v % 2 == 0)
				mutation(offspring_a);
			else
				mutation(offspring_b);
			
			generation_num = 0;
			decrease_colors(selected_population[parent_index]);
			decrease_colors(selected_population[parent_index+1]);
		}
		
		// put the offsprings in the original population from the second half to N (which is the worst population starts)
		population[k]   = offspring_a;
		population[k+1] = offspring_b;
		k += 2;
	}

	generation_num++;
}


void GA::Genetic_algorithm::mutation(std::vector<int>& offspring) const
{
	// summary
	// change only two genes
	// pick the color that repeats more and change for the one that has less occurrences

	// count colors
	std::map<int, int> qnt;
	
	for (int i = 0; i < offspring.size(); i++)
	{
		const int color = offspring[i];
		qnt[color]++;
	}

	// search for the minimum and maximum color quantity
	int ma = 0, mi = UINT_MAX, color_max, color_mim;

	for (auto x : qnt)
	{
		if (ma < x.second)
		{
			color_max = x.first;
			ma = x.second;
		}

		if (mi > x.second)
		{
			color_mim = x.first;
			mi = x.second;
		}
	}
	
	// search in the offspring the first occurence of the maximum e minimum values and set the new value
	const int stop = UINT_MAX;
	int max_index = stop, mim_index = stop;
	
	for (int i = 0; i < offspring.size(); i++)
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


void GA::Genetic_algorithm::decrease_colors(std::vector<int>& parent)
{
	// summary
	// descrease the number of colors from each pair of parents by 1
	// picking the color the appears less and replace it for color 1

	// count colors
	std::map<int, int> qnt_colors;
	
	for (int i = 0; i < parent.size(); i++)
	{
		const int color = parent[i];
		qnt_colors[color]++;
	}

	// search for the maximum color quantity
	int qnt = 0, color;

	for (auto x : qnt_colors)
	{
		if (qnt < x.second)
		{
			color = x.first;
			qnt = x.second;
		}
	}

	// coloring vertices that are not adjacency to the vertex with the same color
	for (int current_vertex = 1; current_vertex <= graph.num_vertices; current_vertex++)
	{
		const int current_vertex_color = parent[current_vertex];

		// searching in the adjacency list
		// check if the color in the vertex k is the same as its adjacancy veterx in the parent
				
		for(int k = 0; k < graph.adj_list[current_vertex].size(); k++)
		{
			const int parent_vertex = graph.adj_list[current_vertex][k];

			// parent_vertex must be >= to the current_vertex
			// because the colors before it were already counted
			if (parent_vertex >= current_vertex && parent[parent_vertex] != current_vertex_color && parent[current_vertex] == color)
				parent[current_vertex] = 1;
		}
	}
}
*/
