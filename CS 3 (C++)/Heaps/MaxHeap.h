#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <string>
#include <iostream>
using namespace std;
struct Element{
	string word;
	int weight;


};
class MaxHeap {
private: int arraySize; // the size of the array, index from 0 to array_size-1 
		 int heapSize ; // number of elements in the heap; heapSize is smaller than arraySize 
		 Element * H ; // elements of heap are in H[1]…H[heapSize], cell at index 0 is not used
		 
		 int Left(int i) ; // return the index of the left child of node i 
		 int Right(int i) ; // return the index of the right child of node i 
		 int Parent(int i) ; // return the index of the parent of node i
		 void PrintHeap(int, string);
		 void PercolateDown(int) ; // DownHeap method. It will be called in MaxHeap and DeleteMax
public: MaxHeap(int arraySize=30); // Generate an empty heap with the default array size of 30. 
		MaxHeap(Element *A, int heapSize, int arraySize) ; // A contains a sequence of elements
		~MaxHeap(); 
		bool empty();
		void Insert(const Element &a) ; // Insert a new element containing word and its weight
		Element DeleteMax(); // Find, return, and remove the element with the maximum weight
		void PrintHeap(); // Print the heap in tree structure; each node containing word and weight 
		void Merge(const MaxHeap &newHeap) ; // Merge with another heap to form a larger heap 
		Element * FindTopMatches(int count) ; // return top “count” matching words based on weights 
		

};
#endif