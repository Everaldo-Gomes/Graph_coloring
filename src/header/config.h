#pragma once

#define MAX_CONFIG_NUM 5

namespace Config
{
    class Execution_param
	{
		public:
			int execution_time_ms {};
			int population_num {};
			int crossover {};
			int mutation {};
			int generation_to_mutate {};

			Execution_param();
	};
}

extern Config::Execution_param g_execution_param[MAX_CONFIG_NUM];