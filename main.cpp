#include <iostream>
#include <cstdlib>
#include "trees.h"

using namespace std;

extern Node root;
extern bool insert (Node, Node);
extern Node del (Node, Node);
extern bool traverse (Node);
extern Node min (Node);

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
	cout << pos << "5. Exit";
	cout << pos;
}

//Acts on the user's choice
void act (int choice){
	Node temp = new node;	//Take input for various action
	temp->lChild = temp->rChild = 0;
	bool check = false;				//Holds if the function returned successfully
	switch (choice){
		case 1:
			cout << "Enter data to be inserted: ";
			cin >> *temp;
			check = insert (temp, root);
			if (!check)
				cout << "Some error occured.";
			break;
		case 2:
			cout << "Enter data to be deleted: ";
			cin >> *temp;
			root = del (temp, root);
			break;
		case 3:
			check = traverse (root);
			if (!check)
				cout << "Tree empty.";
			break;
		case 4:
			cout << "\nMin is: ";
			temp = min (root);
			if (temp)
				cout << *temp;
			else
				cout << "Tree empty";
			break;
		case 5:
			exit (0);
		default:
			cout << "Wrong choice.";
	}
}

int main (){
	while (1){
		menu ();
		int choice;
		cin >> choice;
		act (choice);
		cout << endl;
		cout << "Press any key to continue";
		cin.clear ();
		cin.ignore (1000, '\n');
		getchar ();
	}
	return 0;
}