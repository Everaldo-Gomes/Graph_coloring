#!/bin/bash

inst_qnt=15
config_qnt=80
exec_qnt=10

for ((inst=1; inst<=15; inst++))
do
    for ((config=0; config<$config_qnt; config++))
    do
        for ((exec=1; exec<=$exec_qnt; exec++))
        do
            make run inst=$inst config=$config exec_num=$exec
        done
    done
done
