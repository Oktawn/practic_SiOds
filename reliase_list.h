#pragma once

#include <iostream>
using namespace std;

template <typename T>
struct cyr_knot
{
	T date;
	cyr_knot* next;
};

template <typename T>
struct cyr_list
{
private:
	cyr_knot<T>* head;
	cyr_knot<T>* tail;
	int count;
	bool isEmpty();

public:
	cyr_list();
	~cyr_list();

	void AddHead(T val);
	void AddTail(T val);
	void Insert(int idx,T val);
	void OutList();


	void delHead();
	void delTail();
	void del_knot(int idx);

	cyr_knot<T>* find_Last_Knot();
	cyr_knot<T>* search_knot(int idx);
};

template<typename T>
inline bool cyr_list<T>::isEmpty()
{
	return head == NULL;
}

template<typename T>
inline cyr_list<T>::cyr_list()
{
	head = tail = nullptr;
	count = 0;
}

template<typename T>
inline cyr_list<T>::~cyr_list()
{
	int temp = count;
	while (count--)
	{
		delHead();
	}
}

template<typename T>
inline void cyr_list<T>::AddHead(T val)
{
	cyr_knot<T>* knot = new cyr_knot<T>;
	knot->date = val;
	if (isEmpty())
	{
		knot->next = head;
		head = knot;
	}
	else
	{
		knot->next = head;
		tail = find_Last_Knot();
		tail->next = head;
		head = knot;
	}
	count++;
}

template<typename T>
inline void cyr_list<T>::AddTail(T val)
{
	cyr_knot<T>* knot = new cyr_knot<T>;
	knot->date = val;
	if (isEmpty()) AddHead(val);
	else
	{
		tail = find_Last_Knot();
		tail->next = knot;
		knot->next = head;
	}
	count++;
}

template<typename T>
inline void cyr_list<T>::Insert(int idx, T val)
{
	if (idx == 1) return AddHead(val);
	cyr_knot<T>* knot_prev = search_knot(idx - 1);
	if (knot_prev == nullptr) return AddHead(val);
	cyr_knot<T>* knot = new cyr_knot<T>;
	knot->date = val;
	knot->next = knot_prev->next;
	knot_prev->next = knot;
}

template<typename T>
inline void cyr_list<T>::OutList()
{
	int temp = count;
	cyr_knot<T>* knot = head;
	while (head)
	{
		cout << knot->date << " ";
		knot = knot->next;
	}
	cout << "\n";
}

template<typename T>
inline void cyr_list<T>::delHead()
{
	if (isEmpty()) return;
	cyr_knot<T>* del_knot = head;
	head = del_knot->next;
	tail->next = head;
	delete del_knot;
	count--;
}

template<typename T>
inline void cyr_list<T>::delTail()
{
	if (isEmpty()) return;
	cyr_knot<T>* knot = head;
	cyr_knot<T>* del_knot = find_Last_Knot();
	cyr_knot<T>* knot_tail = del_knot->next;
	if (knot == del_knot) delHead();
	while (knot->next && knot->next !=del_knot)
	{
		knot = knot->next;
	}
	if (knot->next)
	{
		knot->next = knot->next->next;
		delete del_knot;
	}
	count--;
}

template<typename T>
inline void cyr_list<T>::del_knot(int idx)
{
	cyr_knot<T>* del_knot = search_knot(idx);
	cyr_knot<T>* temp = head;
	while (temp->next!=del_knot)
	{
		temp = temp->next;
	}
	temp->next = del_knot->next;
	delete del_knot;
	count--;
}

template<typename T>
inline cyr_knot<T>* cyr_list<T>::find_Last_Knot()
{
	cyr_knot<T>* temp = head;
	while (temp)
	{
		temp = temp->next;
	}
	return temp;
}

template<typename T>
inline cyr_knot<T>* cyr_list<T>::search_knot(int idx)
{
	cyr_knot<T>* knot = head;
	while (knot!=NULL && idx>1)
	{
		knot = knot->next;
		idx--;
	}
	return knot;
}
