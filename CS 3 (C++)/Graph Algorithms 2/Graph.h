#ifndef GRAPH_H
#define GRAPH_H

struct Node {
	int id;
	int weight;
	Node(int id, int weight) : id(id), weight(weight) {}
};

struct NodeCompare{
	bool operator()(Node &a, Node &b){
		return a.weight > b.weight;
	}
};

class Vertex {
public: int id; // the id of the vertex 
		int weight ; // the weight of an edge (u,v), where v is the current node and is in the adj list of vertex u 
		Vertex * next; 
		Vertex(int id_input, int weight_input, Vertex * input_next = nullptr) 
		{ 
			id = id_input ;
			weight = weight_input ; 
			next = input_next ;
		} 
} ;
		
class Graph {
		private: // The first two data members are only used in the shortest path algorithm 
			int * pre ; // record the predecessor for each vertex
			int * dis ; // record the shortest path distance from each vertex to the source vertex 
			bool * flags;
			int n ; // the number of vertices, the ids of the vertices are from 0 to n-1 
			Vertex ** adj ; // adj[i] points the head of the adjacency list of vertex i, for i from 0 to n-1

			bool hasIncidentVertices(int id);
			bool nodeSearch(Vertex * head, int id);
		public: 
			Graph(int n_input); // constructor 
			void SetAdjLists(int * adjM) ; // build the adjacency lists from the adjacency matrix adjM 
			void PrintAdjLists() ; // print the adjacency lists of the graph without the edge weights
			void TopologicalSort(); // perform the topological sort using the stack data structure 
			void PrintAdjListsWeight() ; // print the adjacency lists of the graph with the edge weights 
			void Dijkstra(int s); // compute a shortest path tree from the source vertex s in a general graph 
			void PrintShortestPath(int source, int v) ; // print the shortest path from the source to v 
			int GetShortestPathDis(int v) ; // return the shortest path distance from the source vertex to v 
			
			
} ;
#endif