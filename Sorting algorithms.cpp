#include <iostream>
#include <iomanip>

int ile; //size of dynamic array to sort
void fill_array(int* t, int n); //function for fill array by random values
void print_array(int* t, int n);//function for show array


int main()
{
	std::cout << "set array size: \n";
	std::cin >> ile; 

	int* tab; //create array
	tab = new int[ile]; //reserve space for array

	fill_array(tab, ile);
	print_array(tab, ile);

	delete[] tab; //memory release - delete first array

	return 0;
}

void fill_array(int* t, int n)
{
	srand(time(nullptr));
	for (int i = 0; i < n; i++)
	{
		t[i] = rand() % 10001;
	}
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