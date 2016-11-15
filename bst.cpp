#include "trees.h"
#include <iostream>

using namespace std;

Node root = 0;

Node min (Node parent){
	if (parent && parent->lChild)
		return min (parent->lChild);
	return parent;
}

bool insert (Node, Node);		//Declares insert for use in del

//Deletes the node which has the same value as the node passed
//Returns true or false depending on if the delete was successful
Node del (Node cNode, Node parent){
	if (!parent)
		return parent;
	else if (cNode < parent)
		parent->lChild = del (cNode, parent->lChild);
	else if (cNode > parent)
		parent->rChild = del (cNode, parent->rChild);
	else{
		if (!parent->lChild && !parent->rChild){
			delete parent;
			parent = 0;
		}
		else if (!parent->lChild){
			Node temp = parent;
			parent = parent->rChild;
			delete temp;
		}
		else if (!parent->rChild){
			Node temp = parent;
			parent = parent->lChild;
			delete temp;
		}
		else{
			Node temp = min (parent->rChild);
			parent->value = temp->value;
			parent->rChild = del (temp, parent->rChild);
		}
		return parent;
	}

}

//Deletes the entire tree
void del_all (Node cNode){
	if (cNode->rChild)
		del_all (cNode->rChild);
	if (cNode->lChild)
		del_all (cNode->lChild);
	delete (cNode);
}

//Inserts a new node into the tree.
//Returns true or false depending on whether the insert was successful or not.
bool insert (Node cNode, Node parent){
	if (!root){			//If root is null, insert at root
		root = cNode;
		return true;
	}
	//The following line checks if we need to insert the new node in the right branch or the left branch.
	//If the required child does not exist, it inserts the node there.
	//Otherwise, it recurses the insert call on the correct child.
	if (*cNode > *parent){
		if (!parent->rChild){
			parent->rChild = cNode;
			return true;
		}
		insert (cNode, parent->rChild);
	}
	else{
		if (!parent->lChild){
			parent->lChild = cNode;
			return true;
		}
		insert (cNode, parent->lChild);
	}
	return false;
}

//Traverses and prints the entire tree.
//Returns false if tree is empty and true otherwise.
bool traverse (Node cNode){
	if (!cNode)
		return false;
	if (cNode->lChild)
		traverse (cNode->lChild);	//Checks and traverses the left branch of the tree
	cout << cNode->value << "\t";	//Prints the value contained in the current branch
	if (cNode->rChild)
		traverse (cNode->rChild);	//Checks and traverses the right branch of the tree
	return true;
}