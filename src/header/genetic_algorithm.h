
#pragma once

#include <iostream>
#include <vector>
#include <numeric>   
#include <algorithm>

namespace GA
{
	class Genetic_algorithm
	{
	
	private:
		std::vector<std::vector<int>> population;

		const short int population_num = 100;
	
	public:
		Genetic_algorithm(unsigned short int graph_num_vertices);
		void init_population();
		
		unsigned short int graph_num_vertices;
	};	
}
