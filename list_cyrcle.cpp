#include "reliase_list.h"


int main()
{
	cyr_list<int> list;
	list.AddHead(55);
	list.AddTail(44);
	list.AddTail(11);
	list.AddHead(15);
	list.OutList();

	return 0;
}