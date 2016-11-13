#include "trees.h"
#include <iostream>

using namespace std;

//Overload ostream operator to allow cout
ostream& operator<< (ostream &os, Trees &tree){
	os << tree.value;
	return os;
}

//Overloads istream operator to allow cin
istream& operator>> (istream &in, Trees &input){
	in >> input.value;
	return in;
}

//Overloads == operator to check equality of two nodes
bool Trees::operator== (Trees check) const{
	return (this->value == check.value);
}

//Allows allocation without passing any argument
Trees::Trees(){

}

//Creates a copy constructor
Trees::Trees (const Trees &cpy){
	value = cpy.value;
}

//Creates a constructor that assigns the passed val to the the value parameter of the object
Trees::Trees (int val){
	value = val;
}