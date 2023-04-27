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

    g_execution_param[4].population_num    = 300;
    g_execution_param[4].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[4].mutate_rate       = 0.07;
    g_execution_param[4].crossover         = CROSSOVER_A;
    g_execution_param[4].mutation          = MUTATION_A;

    g_execution_param[5].population_num    = 300;
    g_execution_param[5].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[5].mutate_rate       = 0.07;
    g_execution_param[5].crossover         = CROSSOVER_A;
    g_execution_param[5].mutation          = MUTATION_B;

    g_execution_param[6].population_num    = 300;
    g_execution_param[6].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[6].mutate_rate       = 0.07;
    g_execution_param[6].crossover         = CROSSOVER_A;
    g_execution_param[6].mutation          = MUTATION_A;

    g_execution_param[7].population_num    = 300;
    g_execution_param[7].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[7].mutate_rate       = 0.07;
    g_execution_param[7].crossover         = CROSSOVER_A;
    g_execution_param[7].mutation          = MUTATION_B;

    g_execution_param[8].population_num    = 200;
    g_execution_param[8].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[8].mutate_rate       = 0.07;
    g_execution_param[8].crossover         = CROSSOVER_A;
    g_execution_param[8].mutation          = MUTATION_A;

    g_execution_param[9].population_num    = 200;
    g_execution_param[9].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[9].mutate_rate       = 0.07;
    g_execution_param[9].crossover         = CROSSOVER_A;
    g_execution_param[9].mutation          = MUTATION_B;

    g_execution_param[10].population_num    = 200;
    g_execution_param[10].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[10].mutate_rate       = 0.07;
    g_execution_param[10].crossover         = CROSSOVER_B;
    g_execution_param[10].mutation          = MUTATION_A;

    g_execution_param[11].population_num    = 200;
    g_execution_param[11].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[11].mutate_rate       = 0.07;
    g_execution_param[11].crossover         = CROSSOVER_B;
    g_execution_param[11].mutation          = MUTATION_B;

    g_execution_param[12].population_num    = 300;
    g_execution_param[12].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[12].mutate_rate       = 0.07;
    g_execution_param[12].crossover         = CROSSOVER_A;
    g_execution_param[12].mutation          = MUTATION_A;

    g_execution_param[13].population_num    = 300;
    g_execution_param[13].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[13].mutate_rate       = 0.07;
    g_execution_param[13].crossover         = CROSSOVER_A;
    g_execution_param[13].mutation          = MUTATION_B;

    g_execution_param[14].population_num    = 300;
    g_execution_param[14].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[14].mutate_rate       = 0.07;
    g_execution_param[14].crossover         = CROSSOVER_B;
    g_execution_param[14].mutation          = MUTATION_A;

    g_execution_param[15].population_num    = 300;
    g_execution_param[15].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[15].mutate_rate       = 0.07;
    g_execution_param[15].crossover         = CROSSOVER_B;
    g_execution_param[15].mutation          = MUTATION_B;

    g_execution_param[16].population_num    = 200;
    g_execution_param[16].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[16].mutate_rate       = 0.1;
    g_execution_param[16].crossover         = CROSSOVER_A;
    g_execution_param[16].mutation          = MUTATION_A;

    g_execution_param[17].population_num    = 200;
    g_execution_param[17].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[17].mutate_rate       = 0.1;
    g_execution_param[17].crossover         = CROSSOVER_A;
    g_execution_param[17].mutation          = MUTATION_B;

    g_execution_param[18].population_num    = 200;
    g_execution_param[18].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[18].mutate_rate       = 0.1;
    g_execution_param[18].crossover         = CROSSOVER_A;
    g_execution_param[18].mutation          = MUTATION_A;

    g_execution_param[19].population_num    = 200;
    g_execution_param[19].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[19].mutate_rate       = 0.1;
    g_execution_param[19].crossover         = CROSSOVER_A;
    g_execution_param[19].mutation          = MUTATION_B;

    g_execution_param[20].population_num    = 300;
    g_execution_param[20].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[20].mutate_rate       = 0.1;
    g_execution_param[20].crossover         = CROSSOVER_A;
    g_execution_param[20].mutation          = MUTATION_A;

    g_execution_param[21].population_num    = 300;
    g_execution_param[21].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[21].mutate_rate       = 0.1;
    g_execution_param[21].crossover         = CROSSOVER_A;
    g_execution_param[21].mutation          = MUTATION_B;

    g_execution_param[22].population_num    = 300;
    g_execution_param[22].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[22].mutate_rate       = 0.1;
    g_execution_param[22].crossover         = CROSSOVER_A;
    g_execution_param[22].mutation          = MUTATION_A;

    g_execution_param[23].population_num    = 300;
    g_execution_param[23].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[23].mutate_rate       = 0.1;
    g_execution_param[23].crossover         = CROSSOVER_A;
    g_execution_param[23].mutation          = MUTATION_B;

    g_execution_param[24].population_num    = 200;
    g_execution_param[24].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[24].mutate_rate       = 0.1;
    g_execution_param[24].crossover         = CROSSOVER_A;
    g_execution_param[24].mutation          = MUTATION_A;

    g_execution_param[25].population_num    = 200;
    g_execution_param[25].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[25].mutate_rate       = 0.1;
    g_execution_param[25].crossover         = CROSSOVER_A;
    g_execution_param[25].mutation          = MUTATION_B;

    g_execution_param[26].population_num    = 200;
    g_execution_param[26].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[26].mutate_rate       = 0.1;
    g_execution_param[26].crossover         = CROSSOVER_B;
    g_execution_param[26].mutation          = MUTATION_A;

    g_execution_param[27].population_num    = 200;
    g_execution_param[27].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[27].mutate_rate       = 0.1;
    g_execution_param[27].crossover         = CROSSOVER_B;
    g_execution_param[27].mutation          = MUTATION_B;

    g_execution_param[28].population_num    = 300;
    g_execution_param[28].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[28].mutate_rate       = 0.1;
    g_execution_param[28].crossover         = CROSSOVER_A;
    g_execution_param[28].mutation          = MUTATION_A;

    g_execution_param[29].population_num    = 300;
    g_execution_param[29].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[29].mutate_rate       = 0.1;
    g_execution_param[29].crossover         = CROSSOVER_A;
    g_execution_param[29].mutation          = MUTATION_B;

    g_execution_param[30].population_num    = 300;
    g_execution_param[30].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[30].mutate_rate       = 0.1;
    g_execution_param[30].crossover         = CROSSOVER_B;
    g_execution_param[30].mutation          = MUTATION_A;

    g_execution_param[31].population_num    = 300;
    g_execution_param[31].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[31].mutate_rate       = 0.1;
    g_execution_param[31].crossover         = CROSSOVER_B;
    g_execution_param[31].mutation          = MUTATION_B;

	g_execution_param[32].population_num    = 100;
    g_execution_param[32].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[32].mutate_rate       = 0.07;
    g_execution_param[32].crossover         = CROSSOVER_A;
    g_execution_param[32].mutation          = MUTATION_A;

	g_execution_param[33].population_num    = 100;
    g_execution_param[33].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[33].mutate_rate       = 0.07;
    g_execution_param[33].crossover         = CROSSOVER_A;
    g_execution_param[33].mutation          = MUTATION_B;

	g_execution_param[34].population_num    = 100;
    g_execution_param[34].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[34].mutate_rate       = 0.07;
    g_execution_param[34].crossover         = CROSSOVER_B;
    g_execution_param[34].mutation          = MUTATION_A;

	g_execution_param[35].population_num    = 100;
    g_execution_param[35].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[35].mutate_rate       = 0.07;
    g_execution_param[35].crossover         = CROSSOVER_B;
    g_execution_param[35].mutation          = MUTATION_B;
}
