# =================================================
# variables
# =================================================

path_bin        = ./bin
source_path     = ./src/source
graph_path      = ./src/graph_instances
compile_flags   = g++ -g -Wall -o2 -std=c++20


# =================================================
# execution parameters
# =================================================

# valgrind
ifeq (${v}, 1)
	exe_command = valgrind --leak-check=full
endif

# time
ifeq (${t}, 1)
	exe_command += time 
endif



# =================================================
# Rules
# =================================================

all: clean source run


source: ${source_path}/*.cpp

	$(info ******************* Compiling *******************)
	$(info *************************************************)

	@${compile_flags} ${source_path}/*.cpp -o ${path_bin}/exe
	@clear

run:
	$(info ******************* Running *********************)
	$(info *************************************************)

	@${exe_command} ${path_bin}/exe

clean:
	@clear
	@rm -rf ${path_bin}/*.exe
