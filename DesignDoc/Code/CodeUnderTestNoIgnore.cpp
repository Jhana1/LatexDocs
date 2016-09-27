#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void random_fill(float *starting_vec, size_t size){
    for (size_t i = 0; i < size; ++i)
        starting_vec[i] = (float) rand(); 
}

void reshape2mat(float *in_vec, float *out_vec[], size_t dim){
    for (size_t i = 0; i < dim; ++i)
        for (size_t j = 0; j < dim; ++j)
            out_vec[i][j] = in_vec[i*dim + j];
}

void mmult(float **A, float **B, float **C, size_t dim);
