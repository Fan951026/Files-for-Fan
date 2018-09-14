#ifndef AVLTREE_H 
#define AVLREE_H
#include <string> 
#include <iostream> 
#include <fstream>
#include <sstream>
using namespace std ;
class AvlNode {
public: string word; 
		int height; 
		AvlNode *ptrLeft, *ptrRight; 
		AvlNode(); // Default constructor 
		AvlNode(string s) ; // Constructor with one parameter 

} ;
typedef AvlNode * AvlNodeptr ;
class AvlTree {

private:
	AvlNodeptr root;
public:
	AvlTree(); // Initializes root to NULL. 
	AvlTree(const AvlTree &); //Copy constructor
	~AvlTree(); // Destructor. 
	int Size(); // Return the number of nodes in the tree. 
	int Height(); // Return the path length from the root node to a deepest leaf node in the tree. 
	void Delete(string s); // Delete a string. 
	string Traverse(); // return a string containing all strings stored in the binary search tree in 
	// the descending order and print the strings in pre-order
	void Insert(string s); // Insert a string into the binary search tree.
	bool Find(string s); // search s in the list. Return true if s is found; otherwise, return false.
	int FindComparisons(string s); // search s in the list and return the number of comparisons to // determine whether s is in the tree. 
	int CountTwoChildren(); // return the number of nodes with two children 
	int CountOneChild(); // return the number of nodes with one child 
	int CountLeaves(); // return the number of leave nodes 
	int GetHeight(AvlNodeptr v); // return the height of node v 
	string GetRoot(); // return the word contained in the root node
	string Traverse1();
	void Print();
private:
	// You need to add the following private functions to implement the rebalance operations.
	// You may need to add other private functions you feel appropriate 
	void balance(AvlNodeptr &); // make the tree balanced after insert and delete 
	void rightRotate(AvlNodeptr &); // Right rotation 
	void leftRotate(AvlNodeptr &); // Left rotation
	void doubleLeftRightRotate(AvlNodeptr &); // Left right double rotation 
	void doubleRightLeftRotate(AvlNodeptr &); // Right left double rotation
	void Avltree(AvlNodeptr &);
	string RTraverse(AvlNodeptr);
	int RHeight(AvlNode* ptr);
	int RSize(AvlNodeptr&);
	
	int max(int , int);
	void RInsert(AvlNode*& ptr, string );
	void RDelete(AvlNode*& ptr, string s);
	void DelNode(AvlNode*&ptr);
	string RRTraverse(AvlNodeptr ptr);
	bool RFind(string, AvlNodeptr ptr);
	int RcountTwoChildren(AvlNodeptr ptr);
	int RcountOneChildren(AvlNodeptr ptr);
	int RcountLeaves(AvlNodeptr ptr);
	void Print(AvlNodeptr ptr, string);
	int RFindComparisons(string, AvlNodeptr ptr);
} ;
#endif