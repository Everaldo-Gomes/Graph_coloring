#include "../header/genetic_algorithm.h"

// NOTE:
// Every operation that has -1. is because the list is not using the first position
// therefore it has an additional position that is not being used


GA::Genetic_algorithm::Genetic_algorithm() : population(0, std::vector<int>(0))
{
	population_num = g_execution_param[g_execution_param->current_config].population_num + 1;
	population.resize(population_num, std::vector<int>(g_graph->num_vertices));
}


void GA::Genetic_algorithm::search()
{
	// summary
	// call all phases in the genetic algorithm
	// stop critiria: in miliseconds or when reach the best known value
	// save result to a file

	auto start{std::chrono::high_resolution_clock::now()};
	const int time_limit {g_execution_param[g_execution_param->current_config].execution_time_ms};

	init_population();

	while (true)
	{
		auto evaluated_population {objective_function()};		
		auto selected_population  {selection(evaluated_population)};
		crossover(selected_population);
		mutate();

		auto stop {std::chrono::high_resolution_clock::now()};
		auto duration {std::chrono::duration_cast<std::chrono::milliseconds>(stop - start)};
		
		std::system("clear");
		std::cerr << "Instance:  " << g_graph->instance_name                << "\t"
				  << "N: ["        << g_graph->instance_count               << "/"    << g_graph->graph_instances.size() - 1 << "]  "
				  << "XG: "        << g_graph->instance_xg                  << "\n\n"
				  << "Exe:       " << g_execution_param->current_exe        << "\n"
				  << "Config:    " << g_execution_param->current_config     << "\n" 
				  << "Colors:    " << g_graph->min_color                    << "\n"
				  << "Time:      " << duration.count() << "/" << time_limit << "\n\n"; 

		if (duration >= std::chrono::milliseconds(time_limit) || (g_graph->min_color == g_graph->instance_xg))
		{
			std::ofstream result_file(g_sys->_file_name, std::ios::app);

			result_file << "Instance: " << g_graph->instance_name << "\n";
			result_file << "XG:       " << g_graph->instance_xg   << "\n";
			result_file << "Colors:   " << g_graph->min_color     << "\n";
			result_file << "time(ms): " << duration.count()       << "\n\n";
    		result_file.close();  

			break;
		}
	
		decrease_colors_num(evaluated_population);
	}
}


void GA::Genetic_algorithm::init_population()
{
	// summary
	// for each cromossome, generate random values from 1 to max quantity of vertices

	for (int i = 0; i < population_num; ++i)
	{
		for (int j = 1; j < g_graph->num_vertices; ++j)
		{
			srand(time(0) + i + j);
			population[i][j] = rand() % (g_graph->num_vertices - 1) + 1;
		}
	}
}


std::vector<std::tuple<int, std::vector<int>>> GA::Genetic_algorithm::objective_function()
{
	// summary
	// check if adjacencies vertecies have the same color
	// count the quantity of colors in each possible solution and the quantity of conflicts (if any)
	// return the same population with its quantity of conflicts and colors

	std::vector<std::tuple<int, std::vector<int>>> evaluated_population(population_num);

	for (int i = 0; i < population_num; ++i)
	{
		std::set<int> color_qnt;

		for (int current_vertex = 1; current_vertex < g_graph->num_vertices; ++current_vertex)
		{
			const int current_vertex_color = population[i][current_vertex];
			color_qnt.insert(current_vertex_color);

			const bool conflict_exists {verify_conflict(population[i], current_vertex, current_vertex_color)};

			if (conflict_exists)
				resolve_conflicts(population[i], current_vertex);
		}

		evaluated_population[i] = std::make_tuple(color_qnt.size(), population[i]);
	}

	sort(evaluated_population.begin(), evaluated_population.end());
	return evaluated_population;
}


std::vector<std::vector<int>>
GA::Genetic_algorithm::selection(const std::vector<std::tuple<int, std::vector<int>>> &evaluated_population)
{
	// summary
	// Get the first half of the population which have the smallest color quantity
	// NOTE: the best individuos are already sorted, from the minium to maximum color quantity

	int half_population {population_num / 2};

	// in the seection func the vector will be incremented by 2, therefore this must be odd becuase this starts from position 0
	if (half_population % 2 == 0)
		++half_population;

	std::vector<std::vector<int>> selected_population(half_population, std::vector<int>(g_graph->num_vertices, 1));

	for (int i = 0; i < half_population; ++i)
	{
		const auto t         {evaluated_population[i]};
		const auto color_qnt {std::get<0>(t)};
		const auto vec       {std::get<1>(t)};

		if (g_graph->min_color > color_qnt && color_qnt >= g_graph->instance_xg)
			g_graph->min_color = color_qnt;
			
		selected_population[i] = vec;
	}

	return selected_population;
}


void GA::Genetic_algorithm::crossover(const std::vector<std::vector<int>> &selected_population)
{
	if (g_execution_param[g_execution_param->current_config].crossover == CROSSOVER_A)
		crossover_A(selected_population);
	else
		crossover_B(selected_population);
}


void GA::Genetic_algorithm::crossover_A(const std::vector<std::vector<int>> &selected_population)
{
	// summary
	// each pair of parents will generate two offsprings and perform mutation in one of them
	// the 1st half of the child A will receive a random gene from parente A
	// the 2nd half of the child A will receive a random gene from parente B

	const int selected_population_size = selected_population[0].size() - 1;
	const int first_half  {selected_population_size / 2};
	const int second_half {selected_population_size};

	// save the offsprings from this positions
	int offspring_pos {population_num / 2};

	#pragma omp parallel for
	for (size_t parent_index = 0; parent_index < selected_population.size() - 1; parent_index += 2)
	{
		std::vector<int> offspring_1, offspring_2;
		int gene_index{}, gene{};

		// first half offspring 1
		for (int h1 = 0; h1 <= first_half; ++h1)
		{
			srand(time(0) + h1);
			gene_index = rand() % (g_graph->num_vertices - 1) + 1;
			gene = selected_population[parent_index][gene_index];
			offspring_1.push_back(gene);
		}

		// second half offspring 1
		for (int h2 = first_half + 1; h2 < second_half; ++h2)
		{
			srand(time(0) + h2);
			gene_index = rand() % (g_graph->num_vertices - 1) + 1;
			gene = selected_population[parent_index][gene_index];
			offspring_1.push_back(gene);
		}

		// first half offspring 2
		for (int h1 = 0; h1 <= first_half; ++h1)
		{
			srand(time(0) + h1);
			gene_index = rand() % (g_graph->num_vertices - 1) + 1;
			gene = selected_population[parent_index + 1][gene_index];
			offspring_2.push_back(gene);
		}

		// second half offspring 2
		for (int h2 = first_half + 1; h2 < second_half; ++h2)
		{
			srand(time(0) + h2);
			gene_index = rand() % (g_graph->num_vertices - 1) + 1;
			gene = selected_population[parent_index + 1][gene_index];
			offspring_2.push_back(gene);
		}

		// put the offsprings in the original population from the second half to N (which is the worst population starts)
		population[offspring_pos]     = offspring_1;
		population[offspring_pos + 1] = offspring_2;

		offspring_pos += 2;
	}
}


void GA::Genetic_algorithm::crossover_B(const std::vector<std::vector<int>> &selected_population)
{
	// summary
  	// each pair of parents will generate two offsprings and perform mutation in one of them
	// divide the parents into two parts, and distribute it between the two offsprings

	// P1A) 0000  P1B) 0000
	// P2A) 0000  P2B) 0000

	const int selected_population_size = selected_population[0].size() - 1;
	const int first_half  {selected_population_size / 2};
	const int second_half {selected_population_size};
	int offspring_pos     {population_num / 2};
	int gene              {0};

	for (size_t parent_index = 0; parent_index < selected_population.size() - 1; parent_index += 2)
	{
		std::vector<int> P1A, P1B,
					 	 P2A, P2B,
					 	 offspring_1, 
					 	 offspring_2;

		// P1A
		for (int i = 1; i <= first_half; ++i)
		{
			gene = selected_population[parent_index][i];
			P1A.push_back(gene);
		}
		
		// P1B
		for (int i = first_half + 1; i <= second_half; ++i)
		{
			gene = selected_population[parent_index][i];
			P1B.push_back(gene);
		}

		// P2A
		for (int i = 1; i <= first_half; ++i)
		{
			gene = selected_population[parent_index + 1][i];
			P2A.push_back(gene);
		}

		// P2B
		for (int i = first_half + 1; i <= second_half; ++i)
		{
			gene = selected_population[parent_index + 1][i];
			P2B.push_back(gene);
		}

		// all possibile configurations for P1 + P2 and P2 + P1

		// offspring 1 configuration
		srand(time(0) + parent_index);
		const int config_offspring_1 {rand() % 7};

		switch(config_offspring_1)
		{
			case 0:
			{
				// P1A + P2A
				offspring_1 = P1A;
				offspring_1.insert(offspring_1.end(), P2A.begin(), P2A.end());
				break;
			}
			case 1:
			{
				// P1A + P2B
				offspring_1 = P1A;
				offspring_1.insert(offspring_1.end(), P2B.begin(), P2B.end());
				break;
			}
			case 2:
			{
				// P1B + P2A
				offspring_1 = P1B;
				offspring_1.insert(offspring_1.end(), P2A.begin(), P2A.end());
				break;
			}
			case 3:
			{
				// P1B + P2B
				offspring_1 = P1B;
				offspring_1.insert(offspring_1.end(), P2B.begin(), P2B.end());
				break;
			}
			case 4:
			{
				// P2A + P1A
				offspring_1 = P2A;
				offspring_1.insert(offspring_1.end(), P1A.begin(), P1A.end());
				break;
			}
			case 5:
			{
				// P2A + P1B
				offspring_1 = P2A;
				offspring_1.insert(offspring_1.end(), P1B.begin(), P1B.end());
				break;
			}
			case 6:
			{
				// P2B + P1A
				offspring_1 = P2B;
				offspring_1.insert(offspring_1.end(), P1A.begin(), P1A.end());
				break;
			}
			case 7:
			{
				// P2B + P1B
				offspring_1 = P2B;
				offspring_1.insert(offspring_1.end(), P1B.begin(), P1B.end());
				break;
			}
		}

		
		// offspring 2 configuration
		
		srand(time(0) + parent_index);
		const int config_offspring_2{rand() % 7};

		switch(config_offspring_2)
		{
			case 0:
			{
				// P1A + P2A
				offspring_2 = P1A;
				offspring_2.insert(offspring_2.end(), P2A.begin(), P2A.end());
				break;
			}
			case 1:
			{
				// P1A + P2B
				offspring_2 = P1A;
				offspring_2.insert(offspring_2.end(), P2B.begin(), P2B.end());
				break;
			}
			case 2:
			{
				// P1B + P2A
				offspring_2 = P1B;
				offspring_2.insert(offspring_2.end(), P2A.begin(), P2A.end());
				break;
			}
			case 3:
			{
				// P1B + P2B
				offspring_2 = P1B;
				offspring_2.insert(offspring_2.end(), P2B.begin(), P2B.end());
				break;
			}
			case 4:
			{
				// P2A + P1A
				offspring_2 = P2A;
				offspring_2.insert(offspring_2.end(), P1A.begin(), P1A.end());
				break;
			}
			case 5:
			{
				// P2A + P1B
				offspring_2 = P2A;
				offspring_2.insert(offspring_2.end(), P1B.begin(), P1B.end());
				break;
			}
			case 6:
			{
				// P2B + P1A
				offspring_2 = P2B;
				offspring_2.insert(offspring_2.end(), P1A.begin(), P1A.end());
				break;
			}
			case 7:
			{
				// P2B + P1B
				offspring_2 = P2B;
				offspring_2.insert(offspring_1.end(), P1B.begin(), P1B.end());
				break;
			}
		}
		
		population[offspring_pos]     = offspring_1;
		population[offspring_pos + 1] = offspring_2;
		offspring_pos += 2;
	}
}


void GA::Genetic_algorithm::mutate()
{
	int num_offsprint_to_muate
	{
		static_cast<int>(population_num * g_execution_param[g_execution_param->current_config].mutate_rate)
	};
	
	const int offspring_start_at {population_num / 2};
	std::vector<int> mutated_offspring;
	std::vector<int>::iterator itr;

	while (--num_offsprint_to_muate)
	{
		srand(time(0) + num_offsprint_to_muate);
		const int offspring_index {rand() % (population_num - offspring_start_at)  + offspring_start_at};

		itr = find(mutated_offspring.begin(), mutated_offspring.end(), offspring_index);

		if (itr == mutated_offspring.end())
		{
			mutated_offspring.push_back(offspring_index);
			
			if (g_execution_param[g_execution_param->current_config].mutation == MUTATION_A)
				mutation_A(offspring_index);
			else
				mutation_B(offspring_index);	
		}
	}
}


void GA::Genetic_algorithm::mutation_A(const int &offspring_index)
{
	// summary
	// change only one genes
	// pick the color that repeats more and replace it with the one that has less occurrences

	std::map<int, int> colors;

	for (int i = 1; i < g_graph->num_vertices; ++i)
	{
		const int color_num{population[offspring_index][i]};
		colors[color_num]++;
	}

	int repeated_qnt_max_color {0},
		repeated_qnt_min_color {INT_MAX},
		index_num_max_color {0},
		index_num_min_color {0},
		index {0};

	for (auto &color : colors)
	{
		if (repeated_qnt_max_color < color.second)
		{
			repeated_qnt_max_color = color.second;
			index_num_max_color    = ++index;
		}

		if (repeated_qnt_min_color > color.second)
		{
			repeated_qnt_min_color = color.second;
			index_num_min_color    = ++index;
		}

		++index;
	}

	population[offspring_index][index_num_max_color] = population[offspring_index][index_num_min_color];
}


void GA::Genetic_algorithm::mutation_B(const int &offspring_index)
{
	srand(time(0) + g_graph->instance_xg);
	const int gene         {rand() % (g_graph->num_vertices - 1) + 1};
	const int gene_val     {population[offspring_index][gene]};
	const int new_gene_val {gene_val - 1 > 1 ? gene_val - 1 : 1};

	population[offspring_index][gene] = new_gene_val;
}


void GA::Genetic_algorithm::decrease_colors_num(const std::vector<std::tuple<int, std::vector<int>>> &evaluated_population)
{
	// summary
	// descrease the number of colors from each parent (i,e the first 50% of the array)
	// replace the highest color with a new color chosen randomly if no comflict is detected
	// if there is a conflict the new color will be highest color - 1

	const int half_population {population_num / 2};

	for (int i = 0; i < half_population; ++i)
	{
		const auto t         {evaluated_population[i]};
		const auto color_qnt {std::get<0>(t)};
		const auto vec       {std::get<1>(t)};

		if (color_qnt > g_graph->instance_xg && vec.size() > 0)
		{
			// get the highest num color and save the indexes it appears
			std::vector<int> indexes, vec_aux {vec};

			sort(vec_aux.rbegin(), vec_aux.rend());

			const int highest_color_num = vec_aux[0];
			
			for (size_t k = 1; k < vec.size(); ++k)
			{
				if (vec[k] == highest_color_num)
					indexes.push_back(k);
			}

			// for all indexes, check if the new color will cause a conflict			
			for (size_t k = 0; k < indexes.size(); ++k)
			{
				srand(time(0) + k);
				const int current_color_index  {indexes[k]};
				int current_vertex_color       {population[i][current_color_index]};
				int new_color                  {current_vertex_color};

				while (new_color >= current_vertex_color && current_vertex_color > 1)
					new_color = rand() % (g_graph->num_vertices - 1) + 1;
				

				// if there is a conflict set all the indexes to the highest color - 1
				bool conflicted {false};

				for (size_t k = 0; k < g_graph->adj_list[current_color_index].size(); ++k)
				{
					const int neighbor_vertex = g_graph->adj_list[current_color_index][k];
					
					if (population[i][neighbor_vertex] == new_color)
					{
						conflicted = true;
						break;
					}
				}

				if (conflicted)
					new_color = highest_color_num - 1;
				
				for (const auto& index : indexes)
					population[i][index] = new_color;
			}
		}
	}
}


bool GA::Genetic_algorithm::verify_conflict(const std::vector<int> &chromosome, const int &current_vertex, const int &current_vertex_color) const
{	
	// summary
	// check if the color in the vertex k is the same as its adjacancy veterx in the population
	// if so, there is a conflict
	
	for (size_t k = 0; k < g_graph->adj_list[current_vertex].size(); ++k)
	{
		const int neighbor_vertex = g_graph->adj_list[current_vertex][k];

		if (chromosome[neighbor_vertex] == current_vertex_color && current_vertex != neighbor_vertex)
			return true;
	}	

	return false;
}


void GA::Genetic_algorithm::resolve_conflicts(std::vector<int> &chromosome, const int &current_vertex)
{
	// summary
	// if there is a conflict between the current and the neighbor vertices, change the color of the current vertex

	int color {0};
	bool conflict_exists {false};

	do 
	{
		++color;
		chromosome[current_vertex] = color;
		conflict_exists = verify_conflict(chromosome, current_vertex, color);

	} while (conflict_exists);
}
