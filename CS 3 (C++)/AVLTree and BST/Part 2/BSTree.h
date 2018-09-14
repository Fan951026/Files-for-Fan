#ifndef BSTREE_H 
#define BSTREE_H
#include <string>
#include <iostream> 
using namespace std;
class TreeNode {
public:

	string word;
	TreeNode *ptrLeft, *ptrRight;
	TreeNode(); // Default constructor. 
	TreeNode(string s); // Constructor with one parameter
};
typedef TreeNode* TreeNodeptr;
class BSTree {
private:
	TreeNodeptr root;
public:
	BSTree(); // Initializes root to NULL. 
	BSTree(const BSTree &); //Copy constructor 
	~BSTree(); // Destructor. 
	int Size(); // Return the number of nodes in the tree. 
	int Height(); // Return the path length from the root node to a deepest leaf node in the tree. 
	void Delete(string s); // Delete a string. 
	string Traverse(); // return a string containing all strings stored in the binary search tree in
	// the descending order.
	void Insert(string s); // Insert a string into the binary search tree. 
	string GetRoot();
	int CountLeaves();
	int CountTwoChildren();
	int CountOneChild();
	int FindComparisons(string s);
	bool Find(string s); // search s in the list. Return true if s is found; otherwise, return false.
	string Traverse1();
	void Print();
private:
	// You need to add private functions to implement the recursive solutions. 

	void RBSTree(const BSTree &);
	string RTraverse(TreeNodeptr);
	bool RFind(string s, TreeNodeptr);
	void RDelete(string s, TreeNodeptr& ptr);
	int RHeight(TreeNode* &ptr);
	int RSize(TreeNodeptr&);
	void BSTtree(TreeNodeptr &);
	int RcountTwoChildren(TreeNodeptr ptr);
	int RcountOneChildren(TreeNodeptr ptr);
	int RcountLeaves(TreeNodeptr ptr);
	int RFindComparisons(string s, TreeNodeptr ptr);
	string RRTraverse(TreeNodeptr ptr);
	void Print(TreeNodeptr ptr, string indent);
};
#endif