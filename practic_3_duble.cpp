#include "sort.h"


int main()
{
	srand((unsigned int)(time(NULL)));
	const int size = 100000;
	cout << "size: " << size << "\n";
	int ar[size];
	ar_create_best(ar, size);
	auto start = steady_clock::now();
	//selest_sort(ar, size);
	quick_sort(ar, size);
	auto end = steady_clock::now();
	duration <double> elapsed = end - start;
	cout << "\n";
	cout << "swap= " << swaps << endl;
	cout << "compare= " << comparer << endl;
	//cout << "select sort time= " << elapsed.count() << "\n";
	cout << "quick sort time= " << elapsed.count() << "\n";

	ar_create(ar, size);

	start = steady_clock::now();
	//selest_sort(ar, size);
	quick_sort(ar, size);
	end = steady_clock::now();
	elapsed = end - start;
	cout << "\n";
	cout << "swap= " << swaps << endl;
	cout << "compare= " << comparer << endl;
	//cout << "select sort time= " << elapsed.count() << "\n";
	cout << "quick sort time= " << elapsed.count() << "\n";

	ar_create_bad(ar, size);
	start = steady_clock::now();
	//selest_sort(ar, size);
	quick_sort(ar, size);
	end = steady_clock::now();
	elapsed = end - start;
	cout << "\n";
	cout << "swap= " << swaps << endl;
	cout << "compare= " << comparer << endl;
	//cout << "select sort time= " << elapsed.count() << "\n";
	cout << "quick sort time= " << elapsed.count() << "\n";

	//ar_create(ar, size);
	////ar_show(ar, size);
	//start = steady_clock::now();
	//quick_sort(ar, size);
	//end = steady_clock::now();
	//elapsed = end - start;
	//cout << "quick sort time= " << elapsed.count() << "\n";
	//ar_show(ar, size);

	return 0;

}