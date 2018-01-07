#include <iostream>
using namespace std;
struct nodeStruct
{
	int data;
	nodeStruct *next;
	nodeStruct *prev;
};
class doubly
{
private:
	nodeStruct *head;
	nodeStruct *tail;
public:
	doubly()
	{
		head = NULL;
		tail = NULL;
	}

	void creatNode(int value)
	{
		nodeStruct *temp = new nodeStruct;
		temp->data = value;
		temp->prev = NULL;
		temp->next = NULL;
		tail = head;
		if (head == NULL)
		{
			head = tail = temp;
		}
		else
		{
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			temp->prev = tail->next;
			tail->next = temp;
			tail = temp;
		}
	}
	void insertEnd(int value)
	{
		nodeStruct *cur = new nodeStruct;
		cur->data = value;
		cur->next = NULL;
		cur->prev = NULL;
		tail = head;
		if (head == NULL)
		{
			head = cur = tail;
		}
		else {
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			cur->prev = tail->next;
			tail->next = cur;
			tail = cur;
		}
	}

	void insertStart(int value)
	{
		nodeStruct *temp = new nodeStruct;
		temp->prev = NULL;
		temp->data = value;//let temp->prev=NULL because if we put " temp->prev=head"  (it will)
		temp->next = head;//start accessing the next node instead of head itself
		head->prev = temp;
		head = temp;

	}
	void insertRand(int pos)
	{
		nodeStruct *temp = new nodeStruct;
		nodeStruct *cur = new nodeStruct;
		nodeStruct *pre = new nodeStruct;
		cout << endl;
		cout << "ENTER DATA: " << endl;
		cin >> temp->data;
		cur = head;
		for (int i = 0; i < pos; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		pre->next = temp;
		temp->next = cur;
	}
	void deleteStart()
	{
		nodeStruct *temp = head;
		head = temp;
		head = head->next;
		delete temp;
	}
	void deleteEnd()
	{
		nodeStruct *temp = new nodeStruct;
		nodeStruct *cur = new nodeStruct;
		cur = head;

		while (cur->next != NULL)
		{
			temp = cur;
			cur = cur->next;
		}
		temp->next = NULL;
		delete cur;
	}
	void deleteRand(int pos)
	{
		nodeStruct *temp = new nodeStruct;
		nodeStruct *cur = new nodeStruct;
		nodeStruct *prev = new nodeStruct;
		cur = head;
		for (int i = 0; i < pos; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		cur->prev = NULL;
		prev->next = cur->next;
		delete cur;
	}
	void display()
	{
		nodeStruct *temp = new nodeStruct;
		temp = head;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};
int main()
{
	doubly obj;
	obj.creatNode(31);
	obj.creatNode(32);
	obj.creatNode(33);
	obj.creatNode(34);
	cout << "------------Displaying All Nodes-------------" << endl;
	obj.display();
	obj.insertEnd(321);
	cout << "-------------Inserting at END--------------" << endl;
	obj.display();
	obj.insertStart(123);
	cout << "-------------Inserting at START--------------" << endl;
	obj.display();
	obj.insertRand(3);//passing position to remove element
	cout << "-------------Inserting at RANDOM-------------" << endl;
	obj.display();
	obj.deleteStart();
	cout << "-------------DELETING at START-------------" << endl;
	obj.display();
	obj.deleteEnd();
	cout << "-------------DELETING at END-------------" << endl;
	obj.display();
	obj.deleteRand(3);//passing position to remove element
	cout << "-------------DELETING at RANDOM-------------" << endl;
	obj.display();

	system("pause");
}