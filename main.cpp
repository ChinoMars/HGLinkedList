#include "heLinkedList.h"
#include <stdio.h>

using namespace std;

bool isListEmpty(heLinkedList&);
int lenofList(heLinkedList&);
void addListNode(heLinkedList&, heLinkedList&);
void insertListNode(heLinkedList&, heLinkedList&);
void deleteListNode(heLinkedList&, string&);
void emptyList(heLinkedList&);
heLinkedList* searchListNode(heLinkedList&, string&);

int main(int argc, char const *argv[])
{
	Ungraduate *n1;
	Graduate *n2;
	OnWorkGraduate *n3;
	Teacher *n4;
	Staff *n5;
	int personClass = 0;

	bool flag = true;
	int whtToDo = 0;
	heLinkedList *dataList = new heLinkedList;

	while(flag)
	{
		cout << "*************INPUT WHAT YOU WANT TO DO****************" << '\n'
			 << "1: show list; 2: add node; 3: search node" << '\n'
			 << "4: delete node; 5 empty list; 6: quit" 
			 << endl;
		whtToDo = getchar();
		cin.clear();
		cin.sync();
		switch(whtToDo)
		{
			case 49: // 打印链表数据
				cout << "*****************THE DATA**********************" << endl;
				dataList->printList();
				cout << "*****************DATA END**********************" << endl;
				break;
			case 50: // 增加node
			{
				cout << "***************PLEASE INPUT DATA***************" << '\n'
					 << "1: Ungraduate; 2: Graduate; 3: OnWorkGraduate;" << '\n'
					 << "4: Teacher;    5: Staff" << endl;
				personClass = getchar();
				cin.clear();
				cin.sync();
				heLinkedList *listNode = new heLinkedList;
				switch(personClass)
				{
					case 49:
					{
						n1 = new Ungraduate;
						// tips
						cout << "-NAME-AGE-GENDER-ID-MAJOR-MARK-" << endl;
						cin >> *n1;
						listNode->person = n1;
						break;
					}
					case 50:
					{
						n2 = new Graduate;
						// tips
						cout << "-NAME-AGE-GENDER-ID-MAJOR-TUTOR-" << endl;
						cin >> *n2;
						listNode->person = n2;
						break;
					}
					case 51:
					{
						n3 = new OnWorkGraduate;
						// tips
						cout << "-NAME-AGE-GENDER-ID-MAJOR-TUTOR-SALARY-" << endl;
						cin >> *n3;
						listNode->person = n3;
						break;
					}
					case 52:
					{
						n4 = new Teacher;
						// tips
						cout << "-NAME-AGE-GENDER-ID-SALARY-REASEARCH-" << endl;
						cin >> *n4;
						listNode->person = n4;
						break;
					}
						
					case 53:
					{
						n5 = new Staff;
						// tips
						cout << "-NAME-AGE-GENDER-ID-SALARY-POSITION-" << endl;
						cin >> *n5;
						listNode->person = n5;
						break;
					}
					default:
						delete listNode;
						break;
				}
				cin.clear();
				cin.sync();
				addListNode(*dataList,*listNode);
				break;
			}
			case 51: // 搜索node
			{
				string targetID;
				cout << "**************INPUT ID NUMBER******************" << endl;
				cin >> targetID;
				cin.clear();
				cin.sync();
				heLinkedList *searchres = searchListNode(*dataList,targetID);
				if(searchres)
				{
					cout << "***************SEARCH RESULT*******************" << endl;
					searchres->Next->printNode();	
				}
				break;
			}
			case 52: // 删除node
			{
				string targetID;
				// tips
				cout << "**************INPUT ID NUMBER******************" << endl;
				cin >> targetID;
				cin.clear();
				cin.sync();
				deleteListNode(*dataList,targetID);
				break;
			}
			case 53: // 清空node
			{
				cout << "CONFIRM TO EMPTY THE LIST? Y/N: ";
				int con = 0;
				con = getchar();
				cin.clear();
				cin.sync();
				if(con = 89)
				{
					emptyList(*dataList);
				}
				break;
			}
			case 54: // 退出程序
				flag = false;
				break;
			default:
				break;
		}
	}



	delete dataList;

	system("pause");
	return 0;


}


bool isListEmpty(heLinkedList& list) // 判空
{
	if(list.Next == NULL)
	{
		// cout << "NULL LIST!" << endl;
		return true;
	}

	else return false;
}

int lenofList(heLinkedList& list) // 链表长度
{
	int len = 0;
	if(isListEmpty(list)) return len;

	heLinkedList* p = &list;
	while(p->Next != NULL)
	{
		p = p->Next;
		len++;
	}

	return len;
}

void addListNode(heLinkedList& list, heLinkedList& node) // 插入到链表末尾
{
	if(isListEmpty(list))
	{
		list.Next = &node;
		cout << "ADD SUCCESS!" << endl;
	}
	else if(!(searchListNode(list,(node.person)->getIdNum())))
	{
		heLinkedList* p = &list;
		while(p->Next != NULL)
		{
			p = p->Next;
		}
		p->Next = &node;	
		cout << "ADD SUCCESS!" << endl;
	}
	else
	{
		cout << "DATA EXSIT!" << endl;
	}
	
}


void insertListNode(heLinkedList& list, heLinkedList& node) // 插入到节点后, 或从头插
{
	heLinkedList* nodeTmp = list.Next;
	list.Next = &node;
	node.Next = nodeTmp;
}

void deleteListNode(heLinkedList& list, string& id) // 删除查找到的节点
{
	if(isListEmpty(list))
	{
		cout << "NULL LIST!" << endl;
		cout << "CANNOT DELETE!" << endl;
		return;
	}
	heLinkedList *dPreTmp = searchListNode(list,id);
	if(dPreTmp)
	{
		heLinkedList *dTmp = dPreTmp->Next;
		dPreTmp->Next = dTmp->Next;
		delete dTmp->person;
		delete dTmp;
		cout << "DELETE SUCCESS!" << endl;
		return;
	}
	else
	{
		cout << "NO EXIST DATA!" << endl;
	}

	

}


void emptyList(heLinkedList& list) // 清空链表
{
	if(!(&list)) return;
	if(list.Next == NULL)
	{
		if(list.person != NULL)
		{
			delete list.person;
		}
		cout << "DATA CLEARED!" << endl;
		return;
	}

	while(list.Next)
	{
		heLinkedList *p = list.Next;
		list.Next = list.Next->Next;
		if(p->person) delete p->person;
		delete p;
	}

	cout << "DATA CLEARED!" << endl;
	return;

}


heLinkedList* searchListNode(heLinkedList& list, string& id) // ID为关键字查找节点
{
	if(isListEmpty(list))
	{
		cout << "NULL LIST!" << endl;
		return NULL;
	}
	
	heLinkedList* p = list.Next;
	if((p->person)->getIdNum() == id)
		return &list;


	while((p->Next))
	{
		if(p->Next->person->getIdNum() == id)
		{
			return p; 
		}
		p = p->Next;
	}

	cout << "NOT FOUND!" << endl;
	return NULL;
}