#include <iostream>
#include <iomanip>
#include <time.h>

int ile; //size of dynamic array to sort
clock_t start, stop; //variables for time counting

void fill_array(int* t, int n); //function for fill array by random values
void print_array(int* t, int n);//function for show array
void copy_array(int* t, int* t2, int n);//fuction for copy array

//sorting functions:
void bubble_sort(int* t, int n);

int main()
{
	std::cout << "set array size: \n";
	std::cin >> ile; 

	int* tab; //create array
	tab = new int[ile]; //reserve space for array
	
	int* tab2; //create second array for sorting
	tab2 = new int[ile];

	fill_array(tab, ile);
	print_array(tab,ile);
	copy_array(tab, tab2, ile);
	bubble_sort(tab2, ile);
	print_array(tab2, ile);

	delete[] tab; //memory release - delete first array

	return 0;
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