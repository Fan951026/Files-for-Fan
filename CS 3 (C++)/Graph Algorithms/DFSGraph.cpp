//Did by tutor center 
//xuecong fan 
#include "DFSGraph.h"
#include<iostream>

using namespace std;

DFSGraph::DFSGraph(int n_input){
	adj = new Vertex1*[n_input];
	n = n_input;
	color = new colorType1[n_input];
	pre = new int[n_input];
}
void DFSGraph::AddVertex(Vertex1 * &head, int id) {
	if (!head) {
		head = new Vertex1(id);
		return;
	}
	Vertex1 * temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new Vertex1(id);
}

void DFSGraph::setAdjLists(int *adjM){
	for (int i = 0; i < n; i++)
	{
		adj[i] = NULL;
		for (int j = 0; j < n; j++)
		{
			if (adjM[i*n + j] == 1) // adjMatrix[i][j] is equivalent to adjMatrix[i*n+j]
			{
				// create a new node and add it to the front of adjList[i]
				AddVertex(adj[i], j);
			}
		}
	}
}
void DFSGraph::printAdjLists(){
	Vertex1 * temp;
	for (int i = 0; i < n; i++){
		temp = adj[i];
		cout << i << ": ";
		while (temp != NULL){
			//cout << "Adjacency list of vertex: " << temp->id << endl;
			cout << temp->id << " -> ";
			temp = temp->next;
		}

		cout << endl;
	}
}

void DFSGraph::DFS(int id){
	DFSVisit(id);
}

void DFSGraph::PrintTraversal() {
	for (int i = 0; i <= n - 1; i++){
		color[i] = WHITE1;
		pre[i] = n;
	}
	for (int i = 0; i <= n - 1; i++) {
		if (color[i] == WHITE1) {
			DFSVisit(i);
		}
	}
}

void DFSGraph::DFSVisit(int id){
	color[id] = GRAY1;  
	Vertex1 * v = adj[id];
	cout << id << endl;

	while (v != NULL){
		if (color[v->id] == WHITE1){
			pre[v->id] = id;
			DFSVisit(v->id);
		}
		v = v->next;
	}
	color[id] = BLACK1;
}
void DFSGraph::PrintReachableNodes(int source){
	for (int i = 0; i <= n - 1; i++){
		color[i] = WHITE1;
		pre[i] = n;
	}
	DFSVisit(source);
}
