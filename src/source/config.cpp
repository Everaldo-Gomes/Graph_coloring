#include "../header/config.h"

Config::Execution_param::Execution_param()
{
    g_execution_param[0].population_num    = 200;
    g_execution_param[0].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[0].mutate_rate       = 0.07;
    g_execution_param[0].crossover         = CROSSOVER_A;
    g_execution_param[0].mutation          = MUTATION_A;

    g_execution_param[1].population_num    = 200;
    g_execution_param[1].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[1].mutate_rate       = 0.07;
    g_execution_param[1].crossover         = CROSSOVER_A;
    g_execution_param[1].mutation          = MUTATION_B;

    g_execution_param[2].population_num    = 200;
    g_execution_param[2].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[2].mutate_rate       = 0.07;
    g_execution_param[2].crossover         = CROSSOVER_A;
    g_execution_param[2].mutation          = MUTATION_A;

    g_execution_param[3].population_num    = 200;
    g_execution_param[3].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[3].mutate_rate       = 0.07;
    g_execution_param[3].crossover         = CROSSOVER_A;
    g_execution_param[3].mutation          = MUTATION_B;
}