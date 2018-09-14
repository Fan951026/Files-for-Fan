//xuecong fan
//use tutor lab,google and textbook
// 4/9/2016
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

// Function protototypes

// Read the file and return the number of elements in the file which contains all integers
// Make sure to close the file before return the number of elements in the file
int FindNumberofElements1(const string & fileName) ;

// Sequnetially read the data in the file and load them one-by-one in arrayPtr
// Make sure to close the file after reading the data
void GetInputfromFile1(int *arrayPtr, const string & fileName)  ;

// Read the file and return the number of elements in the file which contains all words
// Make sure to close the file before return the number of elements in the file
int FindNumberofElements2(const string & fileName) ;

// Sequnetially read the data in the file
// Convert the data into nonnegative integers using the strategy mentioned in assignment 5
// Load nonnegative integers one-by-one in arrayPtr
// Make sure to close the file after reading the data
void GetInputfromFile2(int *arrayPtr, const string & fileName)  ;

// Perform various sorting algorithms to sort the data in the ascending order
void HeapSort(int *arrayPtr, int size) ;
void MergeSort(int *arrayPtr, int low, int high) ;
void QuickSort(int *arrayPtr, int low, int high) ;
int  partition(int * arrayPtr, int, int);
void merge(int *arrayPtr, int, int, int);
void Heap(int *arrayPtr, int, int);

void PercolateDown(int hole, int *H, int heapSize);
// Other function prototypes go here


int main()
{
	int *A;
	int n ; // the number of elements stored in A
	string inputFileName1 = "Assign7Data.txt" ; // the name of the input file 
		
	n = FindNumberofElements1(inputFileName1);
	cout << "the number of data in the input file is " << n << endl ;

	// dynamically allocate n spaces in A to hold the n numbers
	// Add your code here ... ... 
	A = new int[n+1];

	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1) ; 


    // call the heap sort procedure
	int start = clock();
	HeapSort(A, n) ; 
	int end = clock();

    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 
	cout << "heapSort time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;

	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1) ; 
	int start2 = clock();
    // call the merge sort procedure
	MergeSort(A, 0, n-1) ; 
	int end2 = clock();
    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 
	cout << "MergeSort time: " << (end2 - start2) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;

	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1) ; 
	int start3 = clock();
    // call the quick sort procedure
	QuickSort(A, 0, n-1) ; 
	int end3 = clock();
    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 
	cout << "QuickSort time: " << (end3 - start3) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;

	delete [] A ;
	A = NULL ;

	cout << "*******************************************************************************************" << endl ;
	cout << "*******************************************************************************************" << endl ;


	string inputFileName2 = "dictionary.txt" ; // the name of the input file

	n = FindNumberofElements2(inputFileName2) ;
	cout << "the number of data in the input file is " << n << endl ;

	// dynamically allocate n spaces in A to hold the n numbers
	// Add your code here ... ... 
	A = new int[n + 1];
	
	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2) ; 
	int start1 = clock();
    // call the heap sort procedure
	HeapSort(A, n) ; 
	int end1 = clock();
    // print the numbers of A out on the screen/console 
	cout << "heapSort time: " << (end1 - start1) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	for (int i = 0; i < n; i++){
		cout << A[i] << "  ";
	}
	cout << endl ; 

	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2) ; 
	int start4 = clock();
    // call the merge sort procedure
	MergeSort(A, 0, n-1) ; 
	int end4 = clock();
    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 
	cout << "MergeSort time: " << (end4 - start4) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	
	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2) ; 
	int start5 = clock();
    // call the quick sort procedure
	QuickSort(A, 0, n-1) ; 
	int end5 = clock();
    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 
	cout << "QuickSort time: " << (end5 - start5) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	delete [] A ;
	A = NULL ;
	
	system("pause") ;

	return 0;
}

// Add your code for each function

// Read the file and return the number of elements in the file containing integers
int FindNumberofElements1(const string & fileName) 
{
	ifstream p;
	p.open(fileName);
	int num = 0;
	int temp1;
	while (p >> temp1){
		
			num++;
	}
	return num;

	p.close();

}


// Sequnetially read the data in the file and load them one-by-one in arrayPtr
void GetInputfromFile1(int *arrayPtr, const string & fileName) 
{
	ifstream q;
	q.open(fileName);
	int num = 0;
	while (q >> arrayPtr[num]){
		
		num++;
	}
	
	q.close();
	
}

// Read the file and return the number of elements in the file containing words
int FindNumberofElements2(const string & fileName) 
{
	ifstream w;
	w.open(fileName);
	int num = 0;
	string input;
	while (w >> input){
		num++;
	}
	return num;
	w.close();
}


// Sequnetially read the data in the file, convert them to integers, and load integers one-by-one in arrayPtr
void GetInputfromFile2(int *arrayPtr, const string & fileName) 
{
	ifstream fin;
	fin.open(fileName);

	int num = 0;
	string nextline;
	int linenum = 0;
	while (!fin.eof()){
		int num = 0;
		getline(fin, nextline);
		for (int i = 0; i < nextline.length(); i++){
			num += nextline[i];
		}
		
		arrayPtr[linenum] = num;
		linenum++;
	}
	fin.close();
	
}

// Perform heap sort and sort the data in ascending order
void HeapSort(int *arrayPtr, int arraySize)
{
	
	int heapSize=arraySize+1;

	int *H = new int [heapSize];
	for (int i = 1; i < heapSize; i++){
		H[i] = arrayPtr[i-1];
	}
	for (int i = heapSize / 2; i > 0; i--){
		PercolateDown(i,H,heapSize);
	}
	int temp;
	int heapSize2 = heapSize-1;
	while (heapSize2 > 0){
		temp = H[heapSize2];
		H[heapSize2] = H[1];
		H[1] = temp;
		heapSize2--;
		PercolateDown(1, H, heapSize2);
	}
	if (H[2] < H[1]){
		int temp1;
		temp1 = H[2];
		H[2] = H[1];
		H[1] = temp1;
	}
	for (int i = 1; i < heapSize; i++){
		arrayPtr[i-1] = H[i];
	}


}
int left(int i){
	return 2 * i;
}
int right(int i){
	return 2 * i + 1;
}

void PercolateDown(int hole,int *H,int heapSize){
	int child;
	int temp = H[hole];
	for (; hole * 2 < heapSize; hole = child){
		child = hole * 2;
		if (child != heapSize && H[child + 1] > H[child]){
			child++;
		}
		if (H[child] > temp){
			H[hole] = H[child];
		}
		else{
			break;
		}
	}
	H[hole] = temp;
}


// Perform merge sort and sort the data in ascending order
void MergeSort(int *arrayPtr, int low, int high)
{
	int mid;
	if (low<high){
		mid = (low + high) / 2;
		MergeSort(arrayPtr, low, mid); 
		MergeSort(arrayPtr, mid + 1, high);
		merge(arrayPtr, low, mid, high);
	}
	return;
}
void merge(int *arrayPtr, int low, int mid, int high){
	int num = 0;
	int num1 = 0;
	int num2 = low;
	
	int arr1 = mid - low + 1;
	int arr2 = high - mid;
	int *temp1 = new int[arr1];
	int *temp2 = new int[arr2];
	for (int i = 0; i < arr1; i++){
		temp1[i] = arrayPtr[low + i];
	}
	for (int j = 0; j < arr2; j++){
		temp2[j] = arrayPtr[mid +1+ j];
	}

	while (arr1 > num && arr2 > num1){
		if (temp1[num] <= temp2[num1]){
			 arrayPtr[num2]=temp1[num];
			num++;
		}
		else{
			arrayPtr[num2]=temp2[num1] ;
			num1++;

		}
		num2++;
	}
	while (num < arr1){
		arrayPtr[num2]= temp1[num];
		num++;
		num2++;
	}
	while (num1 < arr2){
		arrayPtr[num2] = temp2[num1];
		num1++;
		num2++;
}
}
	


// Perform quick sort and sort the data in ascending order
void QuickSort(int *arrayPtr, int low, int high)
{

	if (low < high){
		int p = partition(arrayPtr, low, high);
		QuickSort(arrayPtr, low, p - 1);
		QuickSort(arrayPtr, p + 1, high);
	}
	return;
}
int partition(int * arrayPtr, int start, int end){
	int temp;


	int p = start;


	int ns = start + 1;
	
	while (ns <= end){
	
		while (arrayPtr[ns] < arrayPtr[p]){
			ns++;
		}
		while (arrayPtr[end] > arrayPtr[p]){
			end--;
		} 
		if(ns <= end){
			temp = arrayPtr[ns];
			arrayPtr[ns] = arrayPtr[end];
			arrayPtr[end] = temp;
			ns++;
			end--;
		}
	}
	int temp1;
	temp1 = arrayPtr[p];
	arrayPtr[p] = arrayPtr[end];
	arrayPtr[end] = temp1;


	return end;

}

// Implementation of other functions