#ifndef UTILITY_H
#define UTILITY_H
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <ctime>

void show_menu();
float** create_matrix(int row, int col);
int* create_array(int col);
void delete_matrix(float*** matrix, int row);
void delete_array(int** array);

void random_matrix(float** matrix, int row, int col, float min , float max);
void random_array(int* array, int row, int min, int max);
void show_matrix(float** matrix, int row, int col,float min, float max, int precision);
void show_array(int* array, int row);
int* array_swap(int* array, int row, int pos);
int* array_find(int* array, int row, int tol, int x);
float* minimal_array_from_matrix(float** matrix, int col, int row);
float** swap_matrix_diagonals(float*** matrix, int rows, int cols);
float** multiply_matrcies(float** mat1,int row, int col,int min ,int max,int prec);

bool ascending(int a,int b);
bool decending(int a,int b);

int find_pos(int x, int* array, int row);

void show_sort_methods();
void show_sort_directions();

void simple_sort(int* arr, int size, bool (*intCMP)(int,int ));
void simple_insert_sort(int* arr, int size, bool (*intCMP)(int,int ));
void simple_choice_sort(int* arr, int size, bool (*intCMP)(int,int ));
void heapSort(int* array, int row ,bool (*comp_func)(int,int));
void shell_sort(int* arr, int size,bool (*comp_func)(int,int));
void quick_sort(int* array, int left, int right , bool (*intCMP)(int,int));

float* routing_matrix(float** mat,int col,int row);
float** routing_matrix_out(float* array,int col,int row);
float** sort_matrix(float** matrix, int col, int row, float* (*routing_matrix_in)(float**,int,int), bool (*comp_func)(int,int), float** (*routing_matrix_out)(float* array,int col,int row));
int* array_processing (int** array,int size, int indicator);

#endif // UTILITY_H
