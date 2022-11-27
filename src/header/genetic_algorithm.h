#pragma once

#include <map>
#include <set>
#include <tuple>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

#include "../header/graph.h"


namespace GA
{
	class Genetic_algorithm
	{
	
	private:
		void init_population();
		void mutation(std::vector<unsigned int> &offspring) const;
		void crossover(const std::vector<std::vector<unsigned int>> &selected_population);
		std::vector<std::tuple<unsigned int, unsigned int, std::vector<unsigned int>>> objective_function() const;

		std::vector<std::vector<unsigned int>>
		selection(const std::vector<std::tuple<unsigned int, unsigned int, std::vector<unsigned int>>> &evaluated_population) const;
		
		GP::Graph graph;
		unsigned int generation_num;
		const unsigned int population_num = 200;
		std::vector<std::vector<unsigned int>> population;
	
	public:
		void search();
		Genetic_algorithm(GP::Graph &graph);
	};	
}
