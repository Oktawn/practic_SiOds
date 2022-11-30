#include "reliase_list.h"


int main()
{
	cyr_list<int> list;
	list.AddHead(55);
	list.AddTail(44);
	list.AddTail(11);
	list.AddHead(15);
	list.OutList();
	list.delHead();
	list.Insert(2, 99);
	list.Insert(7, 32);
	list.OutList();


	return 0;
}
