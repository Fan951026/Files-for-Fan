//did by tutor center
//xuecong fan
#include"Graph.h"
#include<iostream>
#include<fstream>
#include<queue>

using namespace std;

int main(){
	ifstream q;
	q.open("Assign9TopologicalInput.txt");
	int size;
	q >> size;
	cout << "size: " << size << endl;
	cout << "Topological Graph:" << endl;
	int * M1;
	M1 = new int[size * size];
	for (int i = 0; i < size * size; i++){
		q >> M1[i];
	}
	Graph graph1(size);
	graph1.SetAdjLists(M1);
	graph1.PrintAdjLists();
	cout << "order:" << endl;
	graph1.TopologicalSort();
	q.close();
	cout << "" << endl;
	cout << "--------------------------------" << endl;

	ifstream y;
	y.open("Assign9ShortestPathInput.txt");
	int size1;
	y >> size1;
	cout << "size1: " << size1 << endl;
	cout << "ShortPath Graph:" << endl;
	int * M2;
	M2 = new int[size1 * size1];
	for (int i = 0; i < size1 * size1; i++){
		y >> M2[i];
	}
	Graph graph2(size1);
	graph2.SetAdjLists(M2);
	graph2.PrintAdjListsWeight();
	cout << "print shortest path form 0 to 5:" << endl;
	graph2.PrintShortestPath(0, 5);
	
	cout << graph2.GetShortestPathDis(5) << endl;	//cout << graph2.GetShortestPathDis(4) << endl;
	cout << "-------------" << endl;
	return 0;
}