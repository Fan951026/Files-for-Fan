//Did by tutor center
//xuecong fan
#include "BFSGraph.h"
#include <iostream>
#include <queue>

using namespace std;

BFSGraph::BFSGraph(int n_input){
	adj = new Vertex*[n_input];
	n = n_input;
	color = new colorType[n_input];
	pre = new int [n_input];
	dis = new int [n_input];

}

void BFSGraph::AddVertex(Vertex * &head, int id) {
	if (!head) {
		head = new Vertex(id);
		return;
	}
	Vertex * temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new Vertex(id);
}

void BFSGraph::SetAdjLists(int *adjM){
	for (int i = 0; i < n; i++) 
	{
		adj[i] = NULL;
		for (int j = 0; j <n; j++)
		{
			if (adjM[i*n + j] == 1) // adjMatrix[i][j] is equivalent to adjMatrix[i*n+j]
			{ 
				// create a new node and add it to the front of adjList[i]
				AddVertex(adj[i], j);
		}
	}
}
}
void BFSGraph::PrintAdjLists(){
	Vertex * temp;
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
void BFSGraph::BFS(int id ){
	for (int i = 0; i <= n - 1; i++){
		color[i] = WHITE;
		dis[i] = n;
		pre[i] = n;
	}
	BFSVisit(id);
	//for (int j = 0; j <= n - 1; j++){
	//	if (color[j] == WHITE){
	//		BFSVisit(id);
	//	}
	//	


	//	

	//}

}

void BFSGraph::BFSVisit(int id){
	
	color[id] = GRAY; dis[id] = 0; std::queue<int> a;
	a.push(id);

	while (!a.empty()){
		int u = a.front();
		a.pop();

		Vertex * v = adj[u];
		while (v != NULL){
			if (color[v->id] == WHITE){
				color[v->id] = GRAY;
				dis[v->id] = dis[u] + 1;
				pre[v->id] = u;
				a.push(v->id);
			 }
			 v = v->next;
		}
		color[u] = BLACK;
	}
}

void BFSGraph::PrintSP(int source, int v){


	BFS(source);
	int w = v;
	while (w != n){
		
		cout << w << endl;
		w = pre[w];

	}
	cout << "distance: "<<dis[v] << endl;
}