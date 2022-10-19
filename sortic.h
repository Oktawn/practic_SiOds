#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;


template <class T>
void ar_random(vector <T> &ar);
template <class T>
void ar_show(vector <T> ar);


template <class T>
void quick_sort(vector<T> &ar, int left, int right);
template <class T>
void select_sort(vector<T> &ar);
template <class T>
void quick_sort1(vector<T>& ar,int size);

template <class T>
int partic(vector<T> &ar, int left, int right);


template<class T>
inline void ar_random(vector<T> &ar)
{
	if(typeid(double)==typeid(ar))
		for (int i = 0; i < ar.size(); i++)
		{
		ar[i] = (double)(rand()) / RAND_MAX*20;
		}
	if (typeid(int) == typeid(ar))
		for (int i = 0; i < ar.size(); i++)
		{
			ar[i] = rand() % RAND_MAX ;
		}
}

template<class T>
inline void ar_show(vector<T> ar)
{
	for (int i = 0; i < ar.size(); i++)
		cout << ar[i] << " ";
}

template<class T>
inline void quick_sort(vector<T> &ar, int left, int right)
{
	if (right <= left) return;
	int i = partic(ar, left, right);
	quick_sort(ar, left, i - 1);
	quick_sort(ar, i+1, right);

}

template<class T>
inline void select_sort(vector<T> &ar)
{
	int min;
	for (int i = 0; i < ar.size(); i++)
	{
		min = i;
		for (int j = i + 1; j < ar.size(); j++)
		{
			min = (ar[j] < ar[min]) ? j : min;
		}
		swap(ar[i], ar[min]);
	}
}

template<class T>
inline void quick_sort1(vector<T>& ar, int size)
{
	int i = 0; int j = size - 1; int mid = ar[size / 2];
	do
	{
		while (ar[i] < mid) i++;
		while (ar[j] > mid) j--;
		if (i <= j) { swap(ar[i], ar[j]); i++; j--; }
	} while (i <= j);

	if (j > 0) { quick_sort1(ar, j + 1); }
	if (i < size) { quick_sort1(ar[i], size - i); }
}

template<class T>
inline int partic(vector<T> &ar, int left, int right)
{
	int i = left - 1; int j = right; T v = ar[right];

	for (;;)
	{
		while (ar[++i] < v);
		while (v< ar[--j])
			if (j == left) 
				break;
		if (i >= j) break;

		swap(ar[i], ar[j]);
	}
	swap(ar[i], ar[right]);
	return i;
}

