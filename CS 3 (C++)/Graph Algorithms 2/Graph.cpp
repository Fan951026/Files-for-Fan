//did by tutor center
#include"Graph.h"
#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <limits>
#include <algorithm>

using namespace std;

Graph::Graph(int n_input){
	adj = new Vertex*[n_input];
	n = n_input;
	pre = new int[n_input];
	dis = new int[n_input];
	flags = new bool[n_input];
}
void Graph::SetAdjLists(int * adjM){
	for (int i = 0; i < n; i++){
		adj[i] = NULL;
		for (int j = n - 1; j >= 0; j--){
			if (adjM[i * n + j] > 0) {
				Vertex *v = new Vertex(j, adjM[i * n + j]);
				v->next = adj[i];
				adj[i] = v;
		
			}
		}
	}
}

void Graph::PrintAdjLists(){
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

bool Graph::hasIncidentVertices(int id) {
	for (int i = 0; i < n; ++i) {
		if (nodeSearch(adj[i], id)) {
			return true;
		}
	}
	return false;
}

bool Graph::nodeSearch(Vertex * head, int id) {
	if (head) {
		if (head->id == id)
			return true;
		else return nodeSearch(head->next,id);
	}
	else {
		return false;
	}
}


void Graph::TopologicalSort(){
	stack<int> S;
	vector<int> L;
	for (int i = 0; i < n; i++){
		if (!hasIncidentVertices(i)){
			S.push(i);
		}
	}

	while (!S.empty()){
		int v = S.top();
		S.pop();
		L.push_back(v);
			vector <int> w;
			while (adj[v] != NULL){
				w.push_back(adj[v]->id);
				Vertex *ptr = adj[v];
				adj[v] = adj[v]->next;
				delete ptr;
			}
			/*delete adj[v];
			adj[v] = NULL;*/
			for (int i = 0; i < w.size(); i++){
				if (!hasIncidentVertices(w[i])){
					S.push(w[i]);
				}
			}
			w.clear();
		}
	for (int i = 0; i < L.size(); i++){
		cout << L[i] <<" ";
	}
}


void Graph::PrintAdjListsWeight(){
	Vertex * temp;
	for (int i = 0; i < n; i++){
		temp = adj[i];
		cout << i << ": ";
		while (temp != NULL){
			//cout << "Adjacency list of vertex: " << temp->id << endl;
			cout << temp->id <<"("<<temp->weight<<")"<< " -> ";
			temp = temp->next;
		}
		cout << endl;
	}
}

void Graph::Dijkstra(int s){
	for (int i = 0; i < n; ++i) {
		flags[i] = false;
		dis[i] = 100000;
		pre[i] = 10000000000;
	} 

	dis[s] = 0;

	//priority_queue<Vertex*> pq([](Vertex *a, Vertex*b){return a->weight < b->weight; });	
	
	priority_queue<Node, vector<Node>, NodeCompare> pq;
	//while (adj[s] != NULL){
	//	pq.push(Node(adj[s]->id, adj[s]->weight));
	////	adj[s] = adj[s]->next;
	////}
	pq.push(Node(s, dis[s]));
	
	while (!pq.empty()){
		Node u = pq.top();
		pq.pop();
		//dis[u.id]=u.weight;

		Vertex* v = adj[u.id];
		while (v!=NULL) {
			int weight = dis[u.id] + v->weight;
			if (weight < dis[v->id]) {
				dis[v->id] = weight;
			
				pre[v->id] = u.id; 
				pq.push(Node(v->id, dis[v->id]));
			}
			v = v->next;
		}

	}


}

void Graph::PrintShortestPath(int source, int v){
	Dijkstra(source);
	cout << "Shortest Path" << endl;
	while (v != source)
	{
		cout << v << " ";
		v = pre[v];
	}
	cout << source << endl;
}
int Graph::GetShortestPathDis(int v){
	/*Dijkstra(0);*/
	cout << "shortest distance to 5: " << endl;
	return dis[v];
	


}