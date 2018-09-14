//xuecong fan
//Did by tutor center

#include<iostream> 
#include<fstream> 
#include<string> 
using namespace std ;
// Use function prototypes listed in the starter code for Q5 as a reference to write appropriate function prototypes for Q6
// Function protototypes
int FindNumberofElements(const string & fileName);
// Sequnetially read the data in the file and load them one-by-one in arrayPtr 
void GetInputfromFile(int *arrayPtr, const string & fileName);
// the following two function prototypes should be fixed 
int BinarySearch(const int *arrayPtr, int starts, int end, int numm);
void OutputResulttoFile(const int *array1, const int *array2, const int numss, const string & FileName) ;
int main() {
	int *A, *B, *C; // array C is used to hold the search results temporarily
	int n = 0; // the number of elements stored in A 
	int m = 0 ; // the number of elements stored in B 
	string dataFileName = "hw1_Q6_data.txt" ; // the name of the data file 
	string searchFileName = "hw1_Q6_search.txt" ; // the name of the search file
		string outputFileName = "hw1_Q6_output.txt"; // the name of the output file     // input all numbers from the data file to the array A
		// Add your code ... ...
		n = FindNumberofElements(dataFileName);
		A = new int[n];
		GetInputfromFile(A, dataFileName);
		m = FindNumberofElements(searchFileName);
		B = new int[m];
		GetInputfromFile(B, searchFileName);
		C = new int[m];

		// input all numbers from the search file to the array B // Add your code ... ...
		// For debugging purpose, print out the content in A 
		for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	cout << endl;
	// print the search results on the screen 
	for (int i = 0; i < m; i++) { 
		C[i] = BinarySearch(A, 0, n-1, B[i]) ;
	cout << "The position of " << B[i] << " is " << C[i] << endl;
}
// output the search results to the output file
	OutputResulttoFile(C, B, m, outputFileName) ;
cout << endl;
return 0;
}
// implementation of all the functions declared in the prototype
int FindNumberofElements(const string & fileName) {
	ifstream in;
	in.open(fileName);
	int plac;
	int count=0;
	while (in>>plac){
		count++;
		}
	in.close();
return count;


}
// Sequnetially read the data in the file and load them one-by-one in arrayPtr 
void GetInputfromFile(int *arrayPtr, const string & fileName) {
	ifstream in;
	int area;
	in.open(fileName);
	int nums = 0;

	while (in>>area){

			arrayPtr[nums] = area;
			nums++;
		}


	}
int BinarySearch(const int *arrayPtr, int starts, int end, int numm){
	
	int midel;
	midel = (starts + end) / 2;
	if (starts >  end){
		return -1;
	}

	if (arrayPtr[midel] == numm){
		return midel;
	}
	else if (arrayPtr[midel] < numm){
		BinarySearch(arrayPtr, midel + 1, end, numm);
	}
	else if (arrayPtr[midel] > numm){
		BinarySearch(arrayPtr, starts, midel - 1, numm);
	}
	



}
void OutputResulttoFile(const int *array1, const int *array2, const int numss, const string & FileName){
	ofstream out(FileName);
	for (int i = 0; i < numss; i++){
		out << "The position of " << array2[i] << " is " << array1[i] << endl;
	}
}