#include<iostream>
#include<fstream>
#include<string>
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

// Other function prototypes go here


int main()
{
	int *A ;
	int n ; // the number of elements stored in A
	string inputFileName1 = "Assign7Data.txt" ; // the name of the input file 
		
	n = FindNumberofElements1(inputFileName1) ;
	cout << "the number of data in the input file is " << n << endl ;

	// dynamically allocate n spaces in A to hold the n numbers
	// Add your code here ... ... 
	

	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1) ; 

    // call the heap sort procedure
	HeapSort(A, n) ; 

    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 

	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1) ; 

    // call the merge sort procedure
	MergeSort(A, 0, n-1) ; 

    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 


	// read the numbers from the input file to array A 
	GetInputfromFile1(A, inputFileName1) ; 

    // call the quick sort procedure
	QuickSort(A, 0, n-1) ; 

    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 

	delete [] A ;
	A = NULL ;

	cout << "*******************************************************************************************" << endl ;
	cout << "*******************************************************************************************" << endl ;


	string inputFileName2 = "dictionary.txt" ; // the name of the input file

	n = FindNumberofElements2(inputFileName2) ;
	cout << "the number of data in the input file is " << n << endl ;

	// dynamically allocate n spaces in A to hold the n numbers
	// Add your code here ... ... 
	

	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2) ; 

    // call the heap sort procedure
	HeapSort(A, n) ; 

    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 

	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2) ; 

    // call the merge sort procedure
	MergeSort(A, 0, n-1) ; 

    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 


	// read the numbers from the input file to array A 
	GetInputfromFile2(A, inputFileName2) ; 

    // call the quick sort procedure
	QuickSort(A, 0, n-1) ; 

    // print the numbers of A out on the screen/console 
	for (int i = 0 ; i < n ; i++)
		cout << A[i] << "  " ; 

	cout << endl ; 

	delete [] A ;
	A = NULL ;
	
	system("pause") ;

	return 0;
}

// Add your code for each function

// Read the file and return the number of elements in the file containing integers
int FindNumberofElements1(const string & fileName) 
{
	
}


// Sequnetially read the data in the file and load them one-by-one in arrayPtr
void GetInputfromFile1(int *arrayPtr, const string & fileName) 
{
	

	
}

// Read the file and return the number of elements in the file containing words
int FindNumberofElements2(const string & fileName) 
{
	
}


// Sequnetially read the data in the file, convert them to integers, and load integers one-by-one in arrayPtr
void GetInputfromFile2(int *arrayPtr, const string & fileName) 
{
	

	
}

// Perform heap sort and sort the data in ascending order
void HeapSort(int *arrayPtr, int size)
{
	

}

// Perform merge sort and sort the data in ascending order
void MergeSort(int *arrayPtr, int low, int high)
{
	

}

// Perform quick sort and sort the data in ascending order
void QuickSort(int *arrayPtr, int low, int high)
{
	

}


// Implementation of other functions