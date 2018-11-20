!/bin/bash

#PBS -l nodes=1:ppn=4,mem=32gb,walltime=00:10:00
#PBS -M da.garzon1@uniandes.edu.co
#PBS -m abe
#PBS -N ejercicio27


module load anaconda/python3
cd $PBS_O_WORKDIR 
gcc -fopenmp HelloWorld.c -o HelloWorld.x

./HelloWorld.x