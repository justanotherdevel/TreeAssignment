#include <iostream>
#include <cstdlib>
#include "trees.h"

using namespace std;

//Function defined in a different file
extern Node insert (Node, int);
extern Node del (Node, int);
extern void traverse (Node);
extern Node min (Node);
extern bool search (Node, int);
extern Node max (Node);

//Little function to beautify menu
ostream& pos (ostream &position){
	position << "\n\t\t\t";
	return position;
}

//Displays the menu
void menu (){
	system ("clear");
	cout << endl << endl << endl;
	cout << pos << "1. Insert";
	cout << pos << "2. Delete";
	cout << pos << "3. Display";
	cout << pos << "4. Display Minimum";
	cout << pos << "5. Search";
	cout << pos << "6. Exit";
	cout << pos;
}

int main (){
	Node root = 0, temp;
	int data;			//Takes data to be operated upon
	while (1){
		menu ();
		int choice;
		cin >> choice;
		system ("clear");
		switch (choice){
			case 1:
				cout << "Enter data to be inserted: ";
				cin >> data;
				root = insert(root, data);
				break;
			case 2:
				cout << "Enter data to be deleted: ";
				cin >> data;
				root = del (root, data);
				break;
			case 3:
				traverse (root);
				break;
			case 4:
				temp = min (root);
				if (temp)
					cout << "Minimum is: " << temp->value;
				else
					cout << "Tree is empty.";
				break;
			case 5:
				cout << "Enter data to be searched: ";
				cin >> data;
				if (search (root, data))
					cout << "\nData present";
				else
					cout << "\nData not present";
				break;
			case 6:
				exit(0);
			default:
				cout << "Wrong choice";
		}
		cout << "\nPress return key to continue...";
		cin.clear();
		cin.ignore(1000,'\n');
		getchar();
	}
}