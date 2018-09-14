#ifndef _Set_H 
#define _Set_H
// Create a data type for the linked list node 
class ListNode { 
public: ListNode(); // default constructor
		
		ListNode(int s); // constructor with one parameter
		int value; 
		ListNode *next;
};
class Set {
private: 
	ListNode *head; 
	int count; // the number of elements in the list 
public: 
	Set(); // Constructor: Create the initial linked list with two nodes 
	Set(Set &obj); // Copy constructor 
	~Set(); // Destructor
		 
	//Functions 
	void Insert(int v); // Insert a new value in order. Duplicated element will not be inserted 
	void Delete(int v); // Delete a value 
	void Print(); // Display list in order
	bool Find(int v); // Search v in the list. Return true if v is found; otherwise, return false
		
	// Overloaded operators
	bool operator<(const Set &obj); // proper subset 
	Set operator^(const Set &obj); // intersection 
	Set operator+(const Set &obj); // union 
	Set operator-(const Set &obj); // set difference 
	Set & operator=(const Set &obj); // assignment 
	int operator[](const int index); // index
};
#endif