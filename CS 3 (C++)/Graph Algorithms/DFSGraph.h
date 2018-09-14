#ifndef DFSGRAGH_H
#define DFSGRAGH_H

enum colorType1 { WHITE1, GRAY1, BLACK1 };
class Vertex1 {
public: int id;   // id for the vertex 
		Vertex1 * next;   // the next vertex in the adj list 
		Vertex1(int input_id, Vertex1 *input_next = nullptr)
		{
			id = input_id;
			next = input_next;
		}
};
class DFSGraph 
{
private: colorType1 * color; // record the colors of the vertices during DFS
		 int * pre ; // record the predecessors during DFS
		 void AddVertex(Vertex1 * &head, int id);
public: 
	int n; // the number of vertices, the ids of the vertices are from 0 to n-1 
	Vertex1 ** adj ; // adj[i] points the head of the adjacency list of vertex i
	DFSGraph(int n_input); // constructor 
	void setAdjLists(int * adjM); // build the adjacency lists from the adjacency matrix adjM 
	void printAdjLists(); // print the adjacency lists of the graph
		// the following two functions are for the DFS traversal as we discussed in class 
	void DFS(int id = 0) ; // DFS traversal, id is the source vertex, with default 0 
	void DFSVisit(int id ); // actually does DFS, search a connected component from id
	void PrintReachableNodes(int source); // Print all nodes that can be reached by source
	void PrintTraversal();
};

#endif