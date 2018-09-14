//some code are find in the book
//Did by tutor center
#include"MaxHeap.h"
#include<string>
#include<iostream>
using namespace std;

int MaxHeap::Left(int i){
	return 2 * i;

}
int MaxHeap::Right(int i){
	return 2 * i + 1;
}
int MaxHeap::Parent(int i){
	return i / 2;
}
void MaxHeap::PercolateDown(int hole){
	int child;
	Element temp = H[hole];
	for (; hole * 2 < heapSize; hole = child){
		child = hole * 2;
		if (child != heapSize && H[child+1].weight > H[child].weight){
			child++;
		}
		if (H[child].weight > temp.weight){
			H[hole] = H[child];
		}
		else{
			break;
		}
	}
	H[hole] = temp;
}

MaxHeap::MaxHeap(int arraySize){
	this->arraySize = arraySize;
	this->heapSize = 0;
	H = new Element[arraySize];
}
MaxHeap::MaxHeap(Element *A, int heapSize, int arraySize){
	this->arraySize = arraySize;
	this->heapSize = heapSize;
	H = new Element[arraySize];
	for (int i = 1; i <= heapSize; i++){
		H[i] = A[i];
	}
	for (int i = heapSize / 2; i > 0; i--){
		PercolateDown(i);
	}

}
MaxHeap::~MaxHeap(){
	delete[] H;

}

void MaxHeap::Insert(const Element &a){
	heapSize++; 
	H[heapSize] = a; // Find the insertion node, whose index is determined by heap_size 
	int i = heapSize ; // UpHeap Operation using Swap Operations 
	while (i > 1 && H[i].weight > H[Parent(i)].weight) {
		// swap H[i] with H[Parent(i)] 
		Element temp = H[i];
		H[i] = H[Parent(i)];
		H[Parent(i)] = temp;
		i = Parent(i);
	}
}
Element MaxHeap::DeleteMax(){
	Element max = H[1];
	H[1] = H[heapSize--];
	PercolateDown(1);
	return max;
}
void MaxHeap::PrintHeap(int p, string a){
	int rightside = Right(p);
	if (rightside <= this->heapSize){
		PrintHeap(rightside, a +"    ");
	}
	cout <<a<< H[p].word << "[" << H[p].weight << "]" << endl;
	int Leftside = Left(p);
	if (Leftside <= this->heapSize){
		PrintHeap(Leftside, a+ "    ");
	}

}
void MaxHeap::PrintHeap(){
	PrintHeap(1, "");
}
bool MaxHeap::empty(){
	if (heapSize == 0){
		return true;
	}
	else {
		return false;
	}
}
void MaxHeap::Merge(const MaxHeap &newHeap){
	Element *B = new Element[this->arraySize];
	for (int i = 1; i <= this->heapSize; i++){
		B[i] = this->H[i];
	}
	delete[] this->H;
	H = new Element[this->arraySize + newHeap.arraySize];

	int oldsize = heapSize;
	this->heapSize = 0;

	for (int i = 1; i <= oldsize; i++){
		Insert(B[i]);
	}
	for (int j = 1; j <= newHeap.heapSize; j++){
		Insert(newHeap.H[j]);
	}

}

Element *MaxHeap::FindTopMatches(int count){
	Element* B = new Element[count];
	for (int i = 0; i < count; i++){
		B[i]=H[i + 1];
	}
	return B;
}
	
