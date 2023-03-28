#include "../header/config.h"

Config::Execution_param::Execution_param()
{
    g_execution_param[0].population_num       = 250;
    g_execution_param[0].execution_time_ms    = 1000;
    g_execution_param[0].generation_to_mutate = 200;
    g_execution_param[0].crossover            = 0;
    g_execution_param[0].mutation             = 0;
}