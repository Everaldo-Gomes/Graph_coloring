#pragma once

#include <memory>
#include <string>

#include "../header/graph.h"

#define MAX_TIME_LIMIT 80000
#define MAX_CONFIG_NUM 80
#define CROSSOVER_A    0
#define CROSSOVER_B    1
#define MUTATION_A     0
#define MUTATION_B     1


namespace Config
{
	class System
	{
		private:
			std::string _config_num {};
			std::string _exec_num   {};

		public:
			const std::string _file_name = "../inst=" + g_graph->instance_name + "_config=" + _config_num + "_exec=" + _exec_num + "_result.txt";
			
			System(const std::string &config_num, const std::string &exec_num);
	};


    class Execution_param
	{
		public:
			int execution_time_ms {0};
			int population_num    {0};
			int crossover         {0};
			int mutation          {0};
			double mutate_rate    {0};
			int current_config    {0};
			int current_exe       {0};

			Execution_param();
	};
}


extern std::unique_ptr<Config::System> g_sys;
extern Config::Execution_param g_execution_param[MAX_CONFIG_NUM];