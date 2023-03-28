#pragma once

#define MAX_CONFIG_NUM 7
#define CROSSOVER_A 0
#define CROSSOVER_B 1
#define MUTATION_A 0
#define MUTATION_B 1


namespace Config
{
    class Execution_param
	{
		public:
			int execution_time_ms    {0};
			int population_num       {0};
			int crossover            {0};
			int mutation             {0};
			int generation_to_mutate {0};
			int current_config       {0};

			Execution_param();
	};
}

extern Config::Execution_param g_execution_param[MAX_CONFIG_NUM];