#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "../header/graph.h"


namespace GA
{
	class Genetic_algorithm
	{
	
	private:
		std::vector<std::vector<unsigned int>> population;
		const unsigned int population_num = 200;
	
	public:
		Genetic_algorithm(unsigned int graph_num_vertices);
		void init_population();
		std::map<unsigned int, std::vector<unsigned int>> objective_function(GP::Graph &graph) const;
		
		const unsigned int graph_num_vertices;
	};	
}
