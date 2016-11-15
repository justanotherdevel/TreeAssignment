#ifndef __BST_TREES__
#define __BST_TREES__

#include <iostream>

using namespace std;

struct Trees{
	int value;				//Stores the value
	Trees *lChild;			//Stores address for the left child
	Trees *rChild;			//Stores address for the right child
	bool operator== (Trees) const;
	friend ostream& operator<< (ostream&, Trees&);
	friend istream& operator>> (istream&, Trees&);
	bool operator> (Trees) const;
	Trees ();
	Trees (const Trees&);
	Trees (int);
};

typedef Trees node;			//Creates alias named node for Trees
typedef node *link;			//Creates alias named link for node *
typedef link Node;			//Creates aleas named Node for link as link points to a node

#endif