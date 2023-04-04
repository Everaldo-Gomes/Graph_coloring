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
#include "../header/config.h"

namespace GA
{
	class Genetic_algorithm
	{
		private:

			void init_population();
			void mutation_A(const int &offspring_index);
			void mutation_B(const int &offspring_index);
			void crossover_A(const std::vector<std::vector<int>> &selected_population);
			void crossover_B(const std::vector<std::vector<int>> &selected_population);
			std::vector<std::tuple<int, int, std::vector<int>>> objective_function();

			std::vector<std::vector<int>>
			selection(const std::vector<std::tuple<int, int, std::vector<int>>> &evaluated_population);

			void decrease_colors_num(const std::vector<std::tuple<int, int, std::vector<int>>> &evaluated_population);
			void resolve_conflicts(std::vector<int> &chromosome, const int &current_vertex);
			bool verify_conflict(const std::vector<int> &chromosome, const int &current_vertex, const int &current_vertex_color) const;

			int generation_num {0};
			int population_num {0};
			std::vector<std::vector<int>> population;


		public:

			Genetic_algorithm();
			void search();
	};
}
