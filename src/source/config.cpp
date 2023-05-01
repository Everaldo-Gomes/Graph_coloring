#include "../header/config.h"

Config::System::System(const std::string &config_num, const std::string &exec_num) : _config_num(config_num), _exec_num(exec_num)
{
}


Config::Execution_param::Execution_param()
{   
	g_execution_param[0].population_num    = 100;
    g_execution_param[0].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[0].mutate_rate       = 0.1;
    g_execution_param[0].crossover         = CROSSOVER_A;
    g_execution_param[0].mutation          = MUTATION_A;

	g_execution_param[1].population_num    = 100;
    g_execution_param[1].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[1].mutate_rate       = 0.2;
    g_execution_param[1].crossover         = CROSSOVER_A;
    g_execution_param[1].mutation          = MUTATION_A;

	g_execution_param[2].population_num    = 100;
    g_execution_param[2].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[2].mutate_rate       = 0.3;
    g_execution_param[2].crossover         = CROSSOVER_A;
    g_execution_param[2].mutation          = MUTATION_A;

	g_execution_param[3].population_num    = 100;
    g_execution_param[3].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[3].mutate_rate       = 0.4;
    g_execution_param[3].crossover         = CROSSOVER_A;
    g_execution_param[3].mutation          = MUTATION_A;

	g_execution_param[4].population_num    = 100;
    g_execution_param[4].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[4].mutate_rate       = 0.5;
    g_execution_param[4].crossover         = CROSSOVER_A;
    g_execution_param[4].mutation          = MUTATION_A;

	g_execution_param[5].population_num    = 100;
    g_execution_param[5].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[5].mutate_rate       = 0.6;
    g_execution_param[5].crossover         = CROSSOVER_A;
    g_execution_param[5].mutation          = MUTATION_A;

	g_execution_param[6].population_num    = 100;
    g_execution_param[6].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[6].mutate_rate       = 0.7;
    g_execution_param[6].crossover         = CROSSOVER_A;
    g_execution_param[6].mutation          = MUTATION_A;

	g_execution_param[7].population_num    = 100;
    g_execution_param[7].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[7].mutate_rate       = 0.8;
    g_execution_param[7].crossover         = CROSSOVER_A;
    g_execution_param[7].mutation          = MUTATION_A;

	g_execution_param[8].population_num    = 100;
    g_execution_param[8].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[8].mutate_rate       = 0.9;
    g_execution_param[8].crossover         = CROSSOVER_A;
    g_execution_param[8].mutation          = MUTATION_A;

	g_execution_param[9].population_num    = 100;
    g_execution_param[9].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[9].mutate_rate       = 1;
    g_execution_param[9].crossover         = CROSSOVER_A;
    g_execution_param[9].mutation          = MUTATION_A;

    g_execution_param[10].population_num    = 100;
    g_execution_param[10].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[10].mutate_rate       = 0.1;
    g_execution_param[10].crossover         = CROSSOVER_A;
    g_execution_param[10].mutation          = MUTATION_B;

	g_execution_param[11].population_num    = 100;
    g_execution_param[11].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[11].mutate_rate       = 0.2;
    g_execution_param[11].crossover         = CROSSOVER_A;
    g_execution_param[11].mutation          = MUTATION_B;

	g_execution_param[12].population_num    = 100;
    g_execution_param[12].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[12].mutate_rate       = 0.3;
    g_execution_param[12].crossover         = CROSSOVER_A;
    g_execution_param[12].mutation          = MUTATION_B;

	g_execution_param[13].population_num    = 100;
    g_execution_param[13].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[13].mutate_rate       = 0.4;
    g_execution_param[13].crossover         = CROSSOVER_A;
    g_execution_param[13].mutation          = MUTATION_B;

	g_execution_param[14].population_num    = 100;
    g_execution_param[14].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[14].mutate_rate       = 0.5;
    g_execution_param[14].crossover         = CROSSOVER_A;
    g_execution_param[14].mutation          = MUTATION_B;

	g_execution_param[15].population_num    = 100;
    g_execution_param[15].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[15].mutate_rate       = 0.6;
    g_execution_param[15].crossover         = CROSSOVER_A;
    g_execution_param[15].mutation          = MUTATION_B;

	g_execution_param[16].population_num    = 100;
    g_execution_param[16].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[16].mutate_rate       = 0.7;
    g_execution_param[16].crossover         = CROSSOVER_A;
    g_execution_param[16].mutation          = MUTATION_B;

	g_execution_param[17].population_num    = 100;
    g_execution_param[17].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[17].mutate_rate       = 0.8;
    g_execution_param[17].crossover         = CROSSOVER_A;
    g_execution_param[17].mutation          = MUTATION_B;

	g_execution_param[18].population_num    = 100;
    g_execution_param[18].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[18].mutate_rate       = 0.9;
    g_execution_param[18].crossover         = CROSSOVER_A;
    g_execution_param[18].mutation          = MUTATION_B;

	g_execution_param[19].population_num    = 100;
    g_execution_param[19].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[19].mutate_rate       = 1;
    g_execution_param[19].crossover         = CROSSOVER_A;
    g_execution_param[19].mutation          = MUTATION_B;

    g_execution_param[20].population_num    = 100;
    g_execution_param[20].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[20].mutate_rate       = 0.1;
    g_execution_param[20].crossover         = CROSSOVER_B;
    g_execution_param[20].mutation          = MUTATION_A;

	g_execution_param[21].population_num    = 100;
    g_execution_param[21].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[21].mutate_rate       = 0.2;
    g_execution_param[21].crossover         = CROSSOVER_B;
    g_execution_param[21].mutation          = MUTATION_A;

	g_execution_param[22].population_num    = 100;
    g_execution_param[22].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[22].mutate_rate       = 0.3;
    g_execution_param[22].crossover         = CROSSOVER_B;
    g_execution_param[22].mutation          = MUTATION_A;

	g_execution_param[23].population_num    = 100;
    g_execution_param[23].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[23].mutate_rate       = 0.4;
    g_execution_param[23].crossover         = CROSSOVER_B;
    g_execution_param[23].mutation          = MUTATION_A;

	g_execution_param[24].population_num    = 100;
    g_execution_param[24].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[24].mutate_rate       = 0.5;
    g_execution_param[24].crossover         = CROSSOVER_B;
    g_execution_param[24].mutation          = MUTATION_A;

	g_execution_param[25].population_num    = 100;
    g_execution_param[25].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[25].mutate_rate       = 0.6;
    g_execution_param[25].crossover         = CROSSOVER_B;
    g_execution_param[25].mutation          = MUTATION_A;

	g_execution_param[26].population_num    = 100;
    g_execution_param[26].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[26].mutate_rate       = 0.7;
    g_execution_param[26].crossover         = CROSSOVER_B;
    g_execution_param[26].mutation          = MUTATION_A;

	g_execution_param[27].population_num    = 100;
    g_execution_param[27].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[27].mutate_rate       = 0.8;
    g_execution_param[27].crossover         = CROSSOVER_B;
    g_execution_param[27].mutation          = MUTATION_A;

	g_execution_param[28].population_num    = 100;
    g_execution_param[28].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[28].mutate_rate       = 0.9;
    g_execution_param[28].crossover         = CROSSOVER_B;
    g_execution_param[28].mutation          = MUTATION_A;

	g_execution_param[29].population_num    = 100;
    g_execution_param[29].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[29].mutate_rate       = 1;
    g_execution_param[29].crossover         = CROSSOVER_B;
    g_execution_param[29].mutation          = MUTATION_A;


    g_execution_param[30].population_num    = 100;
    g_execution_param[30].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[30].mutate_rate       = 0.1;
    g_execution_param[30].crossover         = CROSSOVER_B;
    g_execution_param[30].mutation          = MUTATION_B;

	g_execution_param[31].population_num    = 100;
    g_execution_param[31].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[31].mutate_rate       = 0.2;
    g_execution_param[31].crossover         = CROSSOVER_B;
    g_execution_param[31].mutation          = MUTATION_B;

	g_execution_param[32].population_num    = 100;
    g_execution_param[32].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[32].mutate_rate       = 0.3;
    g_execution_param[32].crossover         = CROSSOVER_B;
    g_execution_param[32].mutation          = MUTATION_B;

	g_execution_param[33].population_num    = 100;
    g_execution_param[33].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[33].mutate_rate       = 0.4;
    g_execution_param[33].crossover         = CROSSOVER_B;
    g_execution_param[33].mutation          = MUTATION_B;

	g_execution_param[34].population_num    = 100;
    g_execution_param[34].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[34].mutate_rate       = 0.5;
    g_execution_param[34].crossover         = CROSSOVER_B;
    g_execution_param[34].mutation          = MUTATION_B;

	g_execution_param[35].population_num    = 100;
    g_execution_param[35].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[35].mutate_rate       = 0.6;
    g_execution_param[35].crossover         = CROSSOVER_B;
    g_execution_param[35].mutation          = MUTATION_B;

	g_execution_param[36].population_num    = 100;
    g_execution_param[36].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[36].mutate_rate       = 0.7;
    g_execution_param[36].crossover         = CROSSOVER_B;
    g_execution_param[36].mutation          = MUTATION_B;

	g_execution_param[37].population_num    = 100;
    g_execution_param[37].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[37].mutate_rate       = 0.8;
    g_execution_param[37].crossover         = CROSSOVER_B;
    g_execution_param[37].mutation          = MUTATION_B;

	g_execution_param[38].population_num    = 100;
    g_execution_param[38].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[38].mutate_rate       = 0.9;
    g_execution_param[38].crossover         = CROSSOVER_B;
    g_execution_param[38].mutation          = MUTATION_B;

	g_execution_param[39].population_num    = 100;
    g_execution_param[39].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[39].mutate_rate       = 1;
    g_execution_param[39].crossover         = CROSSOVER_B;
    g_execution_param[39].mutation          = MUTATION_B;

    //
    g_execution_param[40].population_num    = 300;
    g_execution_param[40].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[40].mutate_rate       = 0.1;
    g_execution_param[40].crossover         = CROSSOVER_A;
    g_execution_param[40].mutation          = MUTATION_A;

	g_execution_param[41].population_num    = 300;
    g_execution_param[41].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[41].mutate_rate       = 0.2;
    g_execution_param[41].crossover         = CROSSOVER_A;
    g_execution_param[41].mutation          = MUTATION_A;

	g_execution_param[42].population_num    = 300;
    g_execution_param[42].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[42].mutate_rate       = 0.3;
    g_execution_param[42].crossover         = CROSSOVER_A;
    g_execution_param[42].mutation          = MUTATION_A;

	g_execution_param[43].population_num    = 300;
    g_execution_param[43].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[43].mutate_rate       = 0.4;
    g_execution_param[43].crossover         = CROSSOVER_A;
    g_execution_param[43].mutation          = MUTATION_A;

	g_execution_param[44].population_num    = 300;
    g_execution_param[44].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[44].mutate_rate       = 0.5;
    g_execution_param[44].crossover         = CROSSOVER_A;
    g_execution_param[44].mutation          = MUTATION_A;

	g_execution_param[45].population_num    = 300;
    g_execution_param[45].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[45].mutate_rate       = 0.6;
    g_execution_param[45].crossover         = CROSSOVER_A;
    g_execution_param[45].mutation          = MUTATION_A;

	g_execution_param[46].population_num    = 300;
    g_execution_param[46].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[46].mutate_rate       = 0.7;
    g_execution_param[46].crossover         = CROSSOVER_A;
    g_execution_param[46].mutation          = MUTATION_A;

	g_execution_param[47].population_num    = 300;
    g_execution_param[47].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[47].mutate_rate       = 0.8;
    g_execution_param[47].crossover         = CROSSOVER_A;
    g_execution_param[47].mutation          = MUTATION_A;

	g_execution_param[48].population_num    = 300;
    g_execution_param[48].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[48].mutate_rate       = 0.9;
    g_execution_param[48].crossover         = CROSSOVER_A;
    g_execution_param[48].mutation          = MUTATION_A;

	g_execution_param[49].population_num    = 300;
    g_execution_param[49].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[49].mutate_rate       = 1;
    g_execution_param[49].crossover         = CROSSOVER_A;
    g_execution_param[49].mutation          = MUTATION_A;

    g_execution_param[50].population_num    = 300;
    g_execution_param[50].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[50].mutate_rate       = 0.1;
    g_execution_param[50].crossover         = CROSSOVER_A;
    g_execution_param[50].mutation          = MUTATION_B;

	g_execution_param[51].population_num    = 300;
    g_execution_param[51].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[51].mutate_rate       = 0.2;
    g_execution_param[51].crossover         = CROSSOVER_A;
    g_execution_param[51].mutation          = MUTATION_B;

	g_execution_param[52].population_num    = 300;
    g_execution_param[52].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[52].mutate_rate       = 0.3;
    g_execution_param[52].crossover         = CROSSOVER_A;
    g_execution_param[52].mutation          = MUTATION_B;

	g_execution_param[53].population_num    = 300;
    g_execution_param[53].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[53].mutate_rate       = 0.4;
    g_execution_param[53].crossover         = CROSSOVER_A;
    g_execution_param[53].mutation          = MUTATION_B;

	g_execution_param[54].population_num    = 300;
    g_execution_param[54].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[54].mutate_rate       = 0.5;
    g_execution_param[54].crossover         = CROSSOVER_A;
    g_execution_param[54].mutation          = MUTATION_B;

	g_execution_param[55].population_num    = 300;
    g_execution_param[55].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[55].mutate_rate       = 0.6;
    g_execution_param[55].crossover         = CROSSOVER_A;
    g_execution_param[55].mutation          = MUTATION_B;

	g_execution_param[56].population_num    = 300;
    g_execution_param[56].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[56].mutate_rate       = 0.7;
    g_execution_param[56].crossover         = CROSSOVER_A;
    g_execution_param[56].mutation          = MUTATION_B;

	g_execution_param[57].population_num    = 300;
    g_execution_param[57].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[57].mutate_rate       = 0.8;
    g_execution_param[57].crossover         = CROSSOVER_A;
    g_execution_param[57].mutation          = MUTATION_B;

	g_execution_param[58].population_num    = 300;
    g_execution_param[58].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[58].mutate_rate       = 0.9;
    g_execution_param[58].crossover         = CROSSOVER_A;
    g_execution_param[58].mutation          = MUTATION_B;

	g_execution_param[59].population_num    = 300;
    g_execution_param[59].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[59].mutate_rate       = 1;
    g_execution_param[59].crossover         = CROSSOVER_A;
    g_execution_param[59].mutation          = MUTATION_B;

    g_execution_param[60].population_num    = 300;
    g_execution_param[60].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[60].mutate_rate       = 0.1;
    g_execution_param[60].crossover         = CROSSOVER_B;
    g_execution_param[60].mutation          = MUTATION_A;

	g_execution_param[61].population_num    = 300;
    g_execution_param[61].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[61].mutate_rate       = 0.2;
    g_execution_param[61].crossover         = CROSSOVER_B;
    g_execution_param[61].mutation          = MUTATION_A;

	g_execution_param[62].population_num    = 300;
    g_execution_param[62].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[62].mutate_rate       = 0.3;
    g_execution_param[62].crossover         = CROSSOVER_B;
    g_execution_param[62].mutation          = MUTATION_A;

	g_execution_param[63].population_num    = 300;
    g_execution_param[63].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[63].mutate_rate       = 0.4;
    g_execution_param[63].crossover         = CROSSOVER_B;
    g_execution_param[63].mutation          = MUTATION_A;

	g_execution_param[64].population_num    = 300;
    g_execution_param[64].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[64].mutate_rate       = 0.5;
    g_execution_param[64].crossover         = CROSSOVER_B;
    g_execution_param[64].mutation          = MUTATION_A;

	g_execution_param[65].population_num    = 300;
    g_execution_param[65].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[65].mutate_rate       = 0.6;
    g_execution_param[65].crossover         = CROSSOVER_B;
    g_execution_param[65].mutation          = MUTATION_A;

	g_execution_param[66].population_num    = 300;
    g_execution_param[66].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[66].mutate_rate       = 0.7;
    g_execution_param[66].crossover         = CROSSOVER_B;
    g_execution_param[66].mutation          = MUTATION_A;

	g_execution_param[67].population_num    = 300;
    g_execution_param[67].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[67].mutate_rate       = 0.8;
    g_execution_param[67].crossover         = CROSSOVER_B;
    g_execution_param[67].mutation          = MUTATION_A;

	g_execution_param[68].population_num    = 300;
    g_execution_param[68].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[68].mutate_rate       = 0.9;
    g_execution_param[68].crossover         = CROSSOVER_B;
    g_execution_param[68].mutation          = MUTATION_A;

	g_execution_param[69].population_num    = 300;
    g_execution_param[69].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[69].mutate_rate       = 1;
    g_execution_param[69].crossover         = CROSSOVER_B;
    g_execution_param[69].mutation          = MUTATION_A;


    g_execution_param[70].population_num    = 300;
    g_execution_param[70].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[70].mutate_rate       = 0.1;
    g_execution_param[70].crossover         = CROSSOVER_B;
    g_execution_param[70].mutation          = MUTATION_B;

	g_execution_param[71].population_num    = 300;
    g_execution_param[71].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[71].mutate_rate       = 0.2;
    g_execution_param[71].crossover         = CROSSOVER_B;
    g_execution_param[71].mutation          = MUTATION_B;

	g_execution_param[72].population_num    = 300;
    g_execution_param[72].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[72].mutate_rate       = 0.3;
    g_execution_param[72].crossover         = CROSSOVER_B;
    g_execution_param[72].mutation          = MUTATION_B;

	g_execution_param[73].population_num    = 300;
    g_execution_param[73].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[73].mutate_rate       = 0.4;
    g_execution_param[73].crossover         = CROSSOVER_B;
    g_execution_param[73].mutation          = MUTATION_B;

	g_execution_param[74].population_num    = 300;
    g_execution_param[74].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[74].mutate_rate       = 0.5;
    g_execution_param[74].crossover         = CROSSOVER_B;
    g_execution_param[74].mutation          = MUTATION_B;

	g_execution_param[75].population_num    = 300;
    g_execution_param[75].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[75].mutate_rate       = 0.6;
    g_execution_param[75].crossover         = CROSSOVER_B;
    g_execution_param[75].mutation          = MUTATION_B;

	g_execution_param[76].population_num    = 300;
    g_execution_param[76].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[76].mutate_rate       = 0.7;
    g_execution_param[76].crossover         = CROSSOVER_B;
    g_execution_param[76].mutation          = MUTATION_B;

	g_execution_param[77].population_num    = 300;
    g_execution_param[77].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[77].mutate_rate       = 0.8;
    g_execution_param[77].crossover         = CROSSOVER_B;
    g_execution_param[77].mutation          = MUTATION_B;

	g_execution_param[78].population_num    = 300;
    g_execution_param[78].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[78].mutate_rate       = 0.9;
    g_execution_param[78].crossover         = CROSSOVER_B;
    g_execution_param[78].mutation          = MUTATION_B;

	g_execution_param[79].population_num    = 300;
    g_execution_param[79].execution_time_ms = MAX_TIME_LIMIT;
    g_execution_param[79].mutate_rate       = 1;
    g_execution_param[79].crossover         = CROSSOVER_B;
    g_execution_param[79].mutation          = MUTATION_B;



	
	/*
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
    g_execution_param[35].mutation          = MUTATION_B; */
}
