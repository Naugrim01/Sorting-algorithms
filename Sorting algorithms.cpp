#include <iostream>
#include <iomanip>
#include <time.h>

int ile; //size of dynamic array to sort
clock_t start, stop; //variables for time counting
double bubble_time = 0;
double select_time = 0;



double time_check(clock_t start, clock_t stop);
void fill_array(int* t, int n); //function for fill array by random values
void print_array(int* t, int n);//function for show array
void copy_array(int* t, int* t2, int n);//fuction for copy array

//sorting functions:
void bubble_sort(int* t, int n);
void select_sort(int* t, int n);

int main()
{
	std::cout << "set array size: \n";
	std::cin >> ile; 

	int* tab; //create array
	tab = new int[ile]; //reserve space for array
	
	int* tab2; //create second array for sorting
	tab2 = new int[ile];

	fill_array(tab, ile);
	//print_array(tab,ile);
	copy_array(tab, tab2, ile);

	start = clock();
	bubble_sort(tab2, ile);
	stop = clock();
	bubble_time = time_check(start, stop);
	std::cout << "bubble sort: \ntime: " << bubble_time << '\n';
	//print_array(tab2, ile);
	copy_array(tab, tab2, ile);

	//print_array(tab2, ile);

	start = clock();
	select_sort(tab2, ile);
	stop = clock();
	select_time = time_check(start, stop);
	std::cout << "select sort: \ntime: " << select_time << '\n';
	//print_array(tab2, ile);

	delete[] tab; //memory release - delete first array
	delete[] tab2;
	return 0;
}

double time_check(clock_t start, clock_t stop)
{
	return (static_cast<double>(stop - start) / CLOCKS_PER_SEC);
}

void fill_array(int* t, int n)
{
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
		t[i] = rand() % 10001;
}

void print_array(int* t, int n)
{
	std:: cout<< "array:\n";
	for (int i = 0; i < n; i++)
	{
		std::cout << std::setw(8);
		std::cout << t[i];
		if ((i + 1) % 10 == 0)
			std::cout << "\n";
	}
}

void copy_array(int* t, int* t2, int n)
{
	for (int i = 0; i < n; i++)
		t2[i] = t[i];
}

//sorting fuctions bodies:
void bubble_sort(int* t, int n)
{
	int temporary;

	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++) //internal loop
			if (t[j - 1] > t[j])//faster way:swap (tab[j - 1], tab[j]);
			{
				temporary = t[j];
				t[j] = t[j-1];
				t[j-1] = temporary;
			}
	
}

void select_sort(int* t, int n)
{
	int k, temporary;
	for (int i = 0; i < n - 1; i++)
	{
		k = i;
		for (int j = i + 1; j < n; j++)
			if (t[j] < t[k]) k = j;

		temporary = t[i];
		t[i] = t[k];
		t[k] = temporary;
	}
}