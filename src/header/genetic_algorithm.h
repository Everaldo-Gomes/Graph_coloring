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
		void decrease_colors(std::vector<int> &parent);
		void mutation(std::vector<int> &offspring) const;
		void crossover(std::vector<std::vector<int>> &selected_population);
		std::vector<std::tuple<int, int, std::vector<int>>> objective_function() const;

		std::vector<std::vector<int>>
		selection(const std::vector<std::tuple<int, int, std::vector<int>>> &evaluated_population);

		
		int min_color      {INT_MAX};
		int conflict_qnt   {INT_MAX};
		int generation_num {0};
		const int population_num {100};
		std::vector<std::vector<int>> population;
		
	
	public:
		
		Genetic_algorithm();
		void search();
	};	
}
