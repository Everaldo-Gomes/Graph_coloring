#pragma once

#include <map>
#include <set>
#include <tuple>
#include <vector>
#include <chrono>
#include <climits>
#include <numeric>
#include <fstream>
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
		void decrease_colors(std::vector<int>& parent);
		void mutation(std::vector<int>& offspring) const;
		void crossover_A(const std::vector<std::vector<int>>& selected_population);
		void crossover_B(const std::vector<std::vector<int>>& selected_population);
		std::vector<std::tuple<int, int, std::vector<int>>> objective_function() const;
		
		std::vector<std::vector<int>>
		selection(const std::vector<std::tuple<int, int, std::vector<int>>>& evaluated_population);

		int min_color         {INT_MAX};
		int best_conflict_qnt {INT_MAX};
		int generation_num    {0};
		const int population_num {10};
		std::vector<std::vector<int>> population;
		
	
	public:

		Genetic_algorithm();
		void search();

		const int generation_to_mutate {200};
	};	
}
