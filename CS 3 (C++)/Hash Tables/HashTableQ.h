#ifndef HASHTABLEQ_H
#define HASHTABLEQ_H
#include <string>
#include <iostream>
using namespace std;
enum EntryType{EMPTY,ACTIVE,DELETED};
struct Element1
{

	string zipcode;
	double latitude;
	double longitude;
	int flag;

};
class HashTableQ // quadratic probing
{ 
private: int m; // the size of the table 
		 Element1 * T; // the hash table 
		 int Hash(string x); // the hash function
		 int QuadraticProbe(string x, int i); // the quadratic probing function
public: 
	HashTableQ(int size); // set the size of the table 
	void Insert(string x, double y, double z); // insert a new element with key x 
	void Remove(string x); // remove an element whose key is x 
	bool Search(string x); // search an element whose key is x and return true if found
	double ComputeDistance(string x1, string x2); // return the distance between two zip codes. 
	                                              // assume both zip codes are valid ones. 
	void PrintTableEntry(); // print the elements in the hash table 
	double rdegree(double degree);
	Element1 findele(string a);
};
#endif