#pragma once

#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;


long long int swaps;
long long int comparer;


void ar_create(int ar[], int size);
void ar_create_bad(int ar[], int size);
void ar_create_best(int ar[], int size);
void ar_show(int ar[], int size);

void selest_sort(int ar[], int size);
void quick_sort(int ar[], int size);




inline void ar_create(int ar[], int size)
{
	for (int i = 0; i < size; i++)
		ar[i] = 0 + rand() % (size - 0 + 1);
}

inline void ar_create_bad(int ar[], int size)
{
	for (int i = 0; i < size; i++)
		ar[i] = INT_MAX - i;
}

inline void ar_create_best(int ar[], int size)
{
	for (int i = 0; i < size; i++)
		ar[i] = i;
}

inline void ar_show(int ar[], int size)
{
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << "\n";
}

inline void selest_sort(int ar[], int size)
{
	int swap=0;
	int compare=0;
	int temp;
	for(int i=0;i<size;i++)
		for (int j = i + 1; j < size; j++)
		{
			if (ar[i] > ar[j])
			{
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
				swap++;	
			}
			compare++;
		}
	swaps = swap;
	comparer = compare;
}

inline void quick_sort(int ar[], int size)
{
	int swap = 0, compare = 0;
	int left = 0; int right = size - 1; int mid = ar[size / 2];
	int temp;
	do
	{
		while (ar[left] < mid) { left++; compare++; }
		while (ar[right] > mid) { right--; compare++;}
		if (left <= right)
		{
			temp = ar[left];
			ar[left] = ar[right];
			ar[right] = temp;
			left++;
			right--;
			compare++; swap++;
		}
	} while (left <= right);
	if (right > 0) quick_sort(ar, right + 1);
	if (left < size) quick_sort(&ar[left], size - left);
	comparer = compare;
	swaps = swap;
}
