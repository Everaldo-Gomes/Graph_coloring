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
		void crossover(std::vector<std::vector<int>>& selected_population);
		std::vector<std::tuple<int, int, std::vector<int>>> objective_function() const;
		
		std::vector<std::vector<int>>
		selection(const std::vector<std::tuple<int, int, std::vector<int>>>& evaluated_population);

		int min_color      {INT_MAX};
		int conflict_qnt   {INT_MAX};
		int generation_num {0};
		const int population_num {200};
		std::vector<std::vector<int>> population;
		
	
	public:

		std::string instance_name {};
		int instance_xg {0};
		
		Genetic_algorithm();
		void search();
	};	
}
