#include "heLinkedList.h"

heLinkedList::heLinkedList(Person* p, heLinkedList* n):person(p), Next(n){}

heLinkedList::~heLinkedList()
{
	// delete person;
}

void heLinkedList::printList()
{
	heLinkedList* p = this;
	while(p != NULL)
	{
		if(p->person != NULL)
			(*(p->person)).disp();
		p = p->Next;
	}
}

void heLinkedList::printNode()
{
	if(person)
	{
		person->disp();
	}
	else
	{
		std::cout << "NULL DATA!" << std::endl;
	}
}
