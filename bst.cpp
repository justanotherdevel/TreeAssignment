#include "trees.h"
#include <iostream>

using namespace std;

//Deletes the entire tree
void del_all (Node cNode){
	if (cNode->rChild)
		del_all (cNode->rChild);
	if (cNode->lChild)
		del_all (cNode->lChild);
	delete (cNode);
}

//Cretes a new node with the given data
Node create (int val){
	Node temp = new node;
	temp->value = val;
	temp->lChild = temp->rChild = 0;		//Initializes both child of the node to NULL
	return temp;
}

//Returns the minimum value element of the tree
Node min (Node root){
	if (root && root->lChild)
		return min (root->lChild);
	return root;
}

//Returns the maximum value element of the tree
Node max (Node root){
	if (root && root->rChild)
		return min (root->rChild);
	return root;
}

//Inserts a new node in the tree
Node insert (Node root, int data){
	if (!root)		//Handles the base case where tree is empty
		return create (data);
	//Checks where to insert the new node
	if (data < root->value)
		root->lChild = insert (root->lChild, data);
	else
		root->rChild = insert (root->rChild, data);
	return root;
}

//Searches for the present of element in a tree
//Returns true or false depending on if the element exist
bool search (Node root, int data){
	if (!root)
		return false;
	if (root->value == data)
		return true;
	else if (data <= root->value)
		return search (root->rChild, data);
	else
		return search (root->lChild, data);
}

//Deletes the node which has the same value as the node passed
//Returns true or false depending on if the delete was successful
Node del (Node root, int data){
	if (!root)		//Handles base case if tree is empty
		return root;
	else if (data < root->value)		//If deletion needs to be done in left branch
		root->lChild = del (root->lChild, data);
	else if (data > root->value)		//If deletion needs to be done in right branch
		root->rChild = del (root->rChild, data);
	else{
		if (!root->lChild && !root->rChild){		//If deletion at leaf
			delete root;
			root = 0;
		}
		//Handles case with only one child
		else if (!root->lChild){
			Node temp = root;
			root = root->rChild;
			delete temp;
		}
		else if (!root->rChild){
			Node temp = root;
			root = root->lChild;
			delete temp;
		}
		//Handles case with two child
		else{
			Node temp = min (root->rChild);
			root->value = temp->value;
			root->rChild = del (root->rChild, temp->value);
		}
		return root;
	}

}

//Prints the entire tree (inorder)
void traverse (Node root){
	if (!root)
		return;
	if (root->lChild)
		traverse(root->lChild);
	cout << root->value << "\t";
	if (root->rChild)
		traverse (root->rChild);
}
