#include "sort.h"


int main()
{
	srand((unsigned int)(time(NULL)));
	const int size = 100000;
	int ar[size];
	ar_create(ar, size);
	//ar_show(ar, size);
	auto start = steady_clock::now();
	selest_sort(ar, size);
	auto end = steady_clock::now();
	duration <double> elapsed = end - start;
	cout << "select sort time= " << elapsed.count() << "\n";
	//ar_show(ar, size);
	cout << "\n";
	ar_create(ar, size);
	//ar_show(ar, size);
	start = steady_clock::now();
	quick_sort(ar, size);
	end = steady_clock::now();
	elapsed = end - start;
	cout << "quick sort time= " << elapsed.count() << "\n";
	//ar_show(ar, size);

	//delete[] &ar;

	return 0;

}