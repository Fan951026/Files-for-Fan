//Did by tutor center 
//xuecong fan 
#include "BFSGraph.h"
#include "DFSGraph.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	ifstream q;
	q.open("Assign8BFSInput.txt");
	int size;
	q >> size;
	cout << "size: "<<size << endl;
	cout << "BFSGraph:" << endl;
	int * M1;
	M1 = new int[size * size];
	for (int i = 0; i < size * size; i++){
		q >> M1[i];
	}
	BFSGraph graph1(size);
	graph1.SetAdjLists(M1);
	graph1.PrintAdjLists();
	cout << "path from 0 to 7: " << endl;
	graph1.PrintSP(0, 7);
	q.close();
	
	ifstream e;
	e.open("Assign8DFSInput.txt");
	int size1;
	e >> size1;
	cout << "DFSGraph-------------------" << endl;
	cout <<"size: "<< size1 << endl;
	int * M2;
	M2 = new int[size1 * size1];
	for (int i = 0; i < size1 * size1; i++){
	e >> M2[i];
	}
	
	DFSGraph graph(size1);
	graph.setAdjLists(M2);
	graph.printAdjLists();
	cout << "DFSGraph algorithm: " << endl;
	graph.PrintTraversal();
	cout << "--------" << endl;
	cout << "start from 0: " << endl;
	graph.PrintReachableNodes(0);
	e.close();




	return 0;
}