#pragma once

#include <map>
#include <set>
#include <tuple>
#include <vector>
#include <chrono>
#include <climits>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

#include "../header/graph.h"


namespace GA
{
	class Genetic_algorithm
	{
	
	private:
		void init_population();
		void decrease_colors(std::vector<unsigned int> &parent);
		void mutation(std::vector<unsigned int> &offspring) const;
		void crossover(std::vector<std::vector<unsigned int>> &selected_population);
		std::vector<std::tuple<unsigned int, unsigned int, std::vector<unsigned int>>> objective_function() const;

		std::vector<std::vector<unsigned int>>
		selection(const std::vector<std::tuple<unsigned int, unsigned int, std::vector<unsigned int>>> &evaluated_population);

		
		GP::Graph graph;
		unsigned int min_color;
		unsigned int conflict_qnt;
		unsigned int generation_num;
		const unsigned int population_num = 100;
		std::vector<std::vector<unsigned int>> population;

	
	public:
		void search();
		Genetic_algorithm(GP::Graph &graph);
	};	
}
