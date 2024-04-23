#!/bin/bash
#SBATCH --job-name=Homework1
#SBATCH --output=./output/my_output_%j.out
#SBATCH --error=./error/my_error_%j.err
#SBATCH --partition=edu5
#SBATCH --nodes=1
#SBATCH --gres=gpu:1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1

srun ./bin/GPUComp_H1 4
