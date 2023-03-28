#include "../header/config.h"

Config::Execution_param::Execution_param()
{
    g_execution_param[0].population_num       = 250;
    g_execution_param[0].execution_time_ms    = 1000;
    g_execution_param[0].generation_to_mutate = 200;
    g_execution_param[0].crossover            = CROSSOVER_A;
    g_execution_param[0].mutation             = MUTATION_A;

    g_execution_param[1].population_num       = 250;
    g_execution_param[1].execution_time_ms    = 1000;
    g_execution_param[1].generation_to_mutate = 200;
    g_execution_param[1].crossover            = CROSSOVER_A;
    g_execution_param[1].mutation             = MUTATION_B;

    g_execution_param[2].population_num       = 150;
    g_execution_param[2].execution_time_ms    = 1000;
    g_execution_param[2].generation_to_mutate = 700;
    g_execution_param[2].crossover            = CROSSOVER_B;
    g_execution_param[2].mutation             = MUTATION_A;

    g_execution_param[3].population_num       = 150;
    g_execution_param[3].execution_time_ms    = 1000;
    g_execution_param[3].generation_to_mutate = 700;
    g_execution_param[3].crossover            = CROSSOVER_B;
    g_execution_param[3].mutation             = MUTATION_B;

    g_execution_param[4].population_num       = 300;
    g_execution_param[4].execution_time_ms    = 1000;
    g_execution_param[4].generation_to_mutate = 1000;
    g_execution_param[4].crossover            = CROSSOVER_A;
    g_execution_param[4].mutation             = MUTATION_A;

    g_execution_param[5].population_num       = 300;
    g_execution_param[5].execution_time_ms    = 1000;
    g_execution_param[5].generation_to_mutate = 1000;
    g_execution_param[5].crossover            = CROSSOVER_B;
    g_execution_param[5].mutation             = MUTATION_B;

    g_execution_param[6].population_num       = 300;
    g_execution_param[6].execution_time_ms    = 1000;
    g_execution_param[6].generation_to_mutate = 2000;
    g_execution_param[6].crossover            = CROSSOVER_B;
    g_execution_param[6].mutation             = MUTATION_A;
}