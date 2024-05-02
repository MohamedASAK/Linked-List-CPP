#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
};

node* head = NULL;
node* current = NULL;
node* tail = NULL;

void insert(int newdata)
{
	current = new node;
	current->data = newdata;
	current->next = NULL;

	if (head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		tail->next = current;
		tail = tail->next;
	}
}
void AddToHead(int newdata)
{
	current = new node;
	current->data = newdata;
	current->next = NULL;
	if (head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		current->next = head;
		head = current;
	}
}
void deleteNode(int Deldata) {
	if (head != NULL)
	{
		current = head;
		if (current->data == Deldata)
		{
			head = head->next;
			delete current;
		}
		else
		{
			while (current != NULL)
			{
				if ((current->next)->data == Deldata)
				{
					(current->next) = (current->next)->next;
					break;
				}
				else { current = current->next; }
			}
		}
	}
	else { cout << "No Data Found" << endl; }
}
void destoryList()
{
	if (head != NULL)
	{
		current = head;
		while (current != NULL)
		{
			head = head->next;
			delete current;
			current = head;
		}
		head = NULL;
		tail = NULL;
		cout << "The list is Destroyed Successfully" << endl;
	}
	else
	{ cout << "There is no list to be destroyed" << endl; }
}
void display()
{
	if (head != NULL)
	{
		current = head;
		cout << "Data:" << endl;
		while (current != NULL)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	else
	{ cout << "No Data Found" << endl; }
}

void app() {
	/*
		op -> operation
		ath -> add to head
		dn -> deleted node
		c -> confirm
		ao -> another operation
		s -> starter app
	*/
	int op, ath, dn, c, ao, s;

	cout << "--- Welcome to linked list implementation---\n";
	do {
		cout << "Choise what do you want\n";
		cout << "Add to head -> (1)\n";
		cout << "Delete node -> (2)\n";
		cout << "Display -> (3)\n";
		cout << "Destory list -> (4)\n";
		cout << "Exit -> (5)\n";
		cin >> op;
		if (op == 1) {
			cout << "Enter value do you want to add to head\n";
			cin >> ath;
			AddToHead(ath);
			display();
		}
		else if (op == 2) {
			display();
			cout << "Choise the node \n";
			cin >> dn;
			cout << "Are you sure to delete this node\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				deleteNode(dn);
				cout << "\nCheck data of list after deleting node : \n ";
				display();
			}
			else
			{
				cout << "Delete is canceled\n";
			}
		}
		else if (op == 3) {
			cout << "\nThe Nodes of the Linked List are: \n";
			display();
		}
		else if (op == 4) {
			display();
			cout << "\nIF Destroyed the whole list\n \t The result will be: \n";
			cout << "Are you sure to destroy the whole list\n";
			cout << "To Confirm Enter -> (1)\n";
			cout << "To Cancel Enter -> any key\n";
			cin >> c;
			if (c == 1)
			{
				destoryList();
				cout << "\nCheck data of list after destroying : \n ";
				display();
			}
			else
			{
				cout << "Destroy is canceled\n";
			}
		}
		else if (op == 5)
		{
			return;
		}
		else { cout << "Error in entry\n"; }

		cout << "\n";

		cout << "Do you want another opration\n";
		cout << "Yes -> 1 \n";
		cout << "NO -> any key \n";
		cin >> ao;

	} while (ao == 1);
}
int main()
{
	app();
	return 0;
}