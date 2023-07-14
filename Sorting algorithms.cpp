#include <iostream>
#include <iomanip>
#include <time.h>
#include <string>

//variables:
int ile; //size of dynamic array to sort
clock_t start, stop; //variables for time counting
double bubble_time = 0;
double select_time = 0;
double insert_time = 0;
double quick_time = 0;
double merge_time = 0;

//functions:

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

int main()
{
	do{

	std::cout << "set array size: \n";
	std::cin >> ile;
		
	}while (!isRight()); //validate

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

	copy_array(tab, tab2, ile);
	start = clock();
	insert_sort(tab2, ile);
	stop = clock();
	insert_time = time_check(start, stop);
	//print_array(tab2, ile);
	//print_array(tab, ile);
	std::cout << "insert sort: \ntime: " << insert_time << '\n';


	copy_array(tab, tab2, ile);
	start = clock();
	quick_sort(tab2, 0, ile - 1);
	stop = clock();
	quick_time = time_check(start, stop);
	//print_array(tab2, ile);
	//print_array(tab, ile);
	std::cout << "quick sort: \ntime: " << quick_time << '\n';

	copy_array(tab, tab2, ile);
	start = clock();
	merge_sort(tab2, 0, ile - 1);
	stop = clock();
	merge_time = time_check(start, stop);
	//print_array(tab2, ile);
	//print_array(tab, ile);
	std::cout << "merge sort: \ntime: " << merge_time << '\n';

	delete[] tab; //memory release - delete first array
	delete[] tab2; //memory release - delete tmp array
	system("pause");
	return 0;
}

bool isRight()
{
	if (std::cin.rdstate())
	{
		std::cin.clear();
		std::cin.ignore(1024, '\n');

		system("cls");

		return false;
	}

	return true;
}

double time_check(clock_t start, clock_t stop)
{
	return (((static_cast<double>(stop)) - (static_cast<double>(start))) / CLOCKS_PER_SEC);
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
		for (int j = i + 1; j < n; j++)//internal loop
			if (t[j] < t[k]) k = j;//select the smallest element in internal loop iteration

		temporary = t[i];  //swap instruction
		t[i] = t[k];
		t[k] = temporary;
	}
}

void insert_sort(int* t, int n)
{
	int x, i, j; //tmp values
	for (j = n - 2; j >= 0; j--)
	{
		x = t[j];
		i = j + 1;
		while ((i < n) && (x > t[i])) //moving on the array and checking elements
		{
			t[i - 1] = t[i];//swap
			i++;
		}
		t[i - 1] = x; //swap
	}
}

void quick_sort(int* t, int l, int r)
{
	int v = t[(l + r) / 2];
	int i, j, x;
	i = l;
	j = r;
	do
	{
		while (t[i] < v) i++;
		while (t[j] > v) j--;
		if (i <= j)
		{
			x = t[i];
			t[i] = t[j];
			t[j] = x;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > l) quick_sort(t, l, j);
	if (i < r) quick_sort(t, i, r);
}

void merge(int tab[], int start_tab, int middle_tab, int end_tab)
{
	int* tmp_tab = new int[(end_tab - start_tab)]; //crerate tmp array
	int i = start_tab, j = middle_tab + 1, k = 0; 

	while (i <= middle_tab && j <= end_tab)
	{
		if (tab[j] < tab[i])
		{
			tmp_tab[k] = tab[j];
			j++;
		}
		else
		{
			tmp_tab[k] = tab[i];
			i++;
		}
		k++;
	}

	if (i <= middle_tab)
	{
		while (i <= middle_tab)
		{
			tmp_tab[k] = tab[i];
			i++;
			k++;
		}
	}
	else
	{
		while (j <= end_tab)
		{
			tmp_tab[k] = tab[j];
			j++;
			k++;
		}
	}

	for (i = 0; i <= end_tab - start_tab; i++)
		tab[start_tab + i] = tmp_tab[i];


}

void merge_sort(int tab[], int start_tab, int end_tab)
{
	int middle_tab;

	if (start_tab != end_tab)
	{
		middle_tab = (start_tab + end_tab) / 2;
		merge_sort(tab, start_tab, middle_tab);
		merge_sort(tab, middle_tab + 1, end_tab);
		merge(tab, start_tab, middle_tab, end_tab);
	}
}