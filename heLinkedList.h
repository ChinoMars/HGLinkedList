#include "People.h"

class heLinkedList
{
	public:
		heLinkedList(Person* p = NULL, heLinkedList* n = NULL);
		virtual ~heLinkedList();

		void printList();
		void printNode();

	// protected:
		Person* person;
		heLinkedList* Next;

};