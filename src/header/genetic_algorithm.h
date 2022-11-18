#pragma once

#include <set>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

#include "../header/graph.h"


namespace GA
{
	class Genetic_algorithm
	{
	
	private:
		void init_population();
		std::vector<std::vector<unsigned int>> selection(const auto &evaluated_population) const;
		std::vector<std::tuple<unsigned int, unsigned int, std::vector<unsigned int>>> objective_function() const;
		
		GP::Graph graph;
		const unsigned int population_num = 200;
		std::vector<std::vector<unsigned int>> population;
	
	public:
		void search();
		Genetic_algorithm(GP::Graph &graph);
	};	
}
