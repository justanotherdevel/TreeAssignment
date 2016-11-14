#ifndef __B_S_T__
#define __B_S_T__

#include <iostream>

class BST{
		Node root;				//Maintains the root of the tree.
		int count;				//Maintains the number of element in the tree
	public:
		BST ();					//Initilaizes root and count to 0
		bool del (Node*);		//Deletes a node from the tree
		void traverse (Node*);	//Traverses and prints the tree
		void insert (Node*);	//Inserts a new node into the tree while maintaining the property
		void del_all (Node*);	//Deletes the entire tree
		~BST();
};

#endif