//xuecong fna
//Did by tutor center


#include<iostream> 
#include<fstream> 
#include<string> 
#include<sstream>
using namespace std;

// Function protototypes
// Read the file and return the number of elements in the file 
int FindNumberofElements(const string & fileName);
// Sequnetially read the data in the file and load them one-by-one in arrayPtr 
void GetInputfromFile(int *arrayPtr, const string & fileName);
// Perform selection sort and sort the data in ascending order
void SelectionSort(int *arrayPtr, int size) ;
// Output the sorted data to a file 
void OutputResulttoFile(int *arrayPtr, const int size, const string & fileName) ;
int main() {
	int *A; int n; // the number of elements stored in A 
	string inputFileName = "hw1_Q5_input.txt" ; 
	// the name of the input file 
	string outputFileName = "hw1_Q5_output.txt" ; 
	// the name of the output file
		n = FindNumberofElements(inputFileName); 
	cout << "the number of data in the input file is " << n << endl;
	// dynamically allocate n spaces in A to hold the n numbers // Add your code here ... ...
	A = new int[n];
	// read the numbers from the input file to array A 
	GetInputfromFile(A, inputFileName) ;
	// call the selection sort procedure
	SelectionSort(A, n);
	// print the numbers of A out on the screen/console
	for (int i = 0; i < n; i++) 
		cout << A[i] << "  ";
	cout << endl;
	// output the sorted numbers in A to output file 
	OutputResulttoFile(A, n, outputFileName) ;
	system("pause"); return 0;
} // Add your code for each function // Read the file and return the number of elements in the file
int FindNumberofElements(const string & fileName) {
	ifstream in;
	int cout = 0;
	in.open(fileName);
	string app, nums;
	//if (!in)
		//cout << "file read problem" << endl;
		while (getline(in, app)){
			stringstream ha(app);
			while (getline(ha, nums, ' ')){
				cout++;
			}
			

		}


		return cout;

}
// Sequnetially read the data in the file and load them one-by-one in arrayPtr 
void GetInputfromFile(int *arrayPtr, const string & fileName) {
	ifstream in;
	int cout = 0;
	in.open(fileName);
	string app;
    int nums=0;
	
	while (getline(in, app)){
	stringstream ha(app);
		while (ha>>nums){
			arrayPtr[cout++] = nums;
		}


	}



	




}
// Perform selection sort and sort the data in ascending order 
void SelectionSort(int *arrayPtr, int size) {
	int min, temp;
	for (int i = 0; i < size; i++){
		min = i;
		for (int j = i; j < size; j++){
			if (arrayPtr[j] < arrayPtr[min]){
				min = j;
			}
		}
		    if (min != i){
				temp = arrayPtr[i];
				arrayPtr[i] = arrayPtr[min];
				arrayPtr[min] = temp;
			}
		
	}
}
// Output the sorted data to a file
void OutputResulttoFile(int *arrayPtr, const int size, const string & fileName){
	ofstream out(fileName);
	for (int i = 0; i < size; i++){
		out << arrayPtr[i] << ' ';
	}
}