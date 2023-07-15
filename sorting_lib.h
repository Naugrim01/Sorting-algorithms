#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>

bool isRight(); // validation
double time_check(clock_t start, clock_t stop);
void fill_array(int* t, int n); //function for fill array by random values
void print_array(int* t, int n);//function for show array
void copy_array(int* t, int* t2, int n);//fuction for copy array

//sorting functions:
void bubble_sort(int* t, int n);
void select_sort(int* t, int n);
void insert_sort(int* t, int n);
void quick_sort(int* t, int l, int r);
void merge(int tab[], int start_tab, int middle_tab, int end_tab);//internal funcrion for merge sort
void merge_sort(int tab[], int start_tab, int end_tab);
void sorting_times();
