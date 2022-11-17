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
		std::vector<std::tuple<size_t, size_t, std::vector<size_t>>> objective_function() const;
		
		GP::Graph graph;
		const size_t population_num = 10;
		std::vector<std::vector<size_t>> population;
	
	public:
		void search();
		Genetic_algorithm(GP::Graph &graph);
	};	
}
