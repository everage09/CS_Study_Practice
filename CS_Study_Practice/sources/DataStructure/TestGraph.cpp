#include "../headers/DataStructure/Graph/myMatrixGraph.h"
#include "../headers/DataStructure/Tree/myPriorityQueue.h"
#include "../headers/DataStructure/myQueue.h"
#include "../headers/DataStructure/myStack.h"
#include "../headers/DataStructure/Graph/GraphDistType.h"
#include "../headers/DataStructure/Graph/myGraphBFS.h"
#include "../headers/DataStructure/Graph/myGraphDFS.h"
#include <iostream>
#include <unordered_map>

using namespace std;

template<typename T>
void ShortestPath(myMatrixGraph<T>& g, T start)
{
	unordered_map<T, T> parent;
	myPTQ<GraphDistType<T>> pq(g.GetNumVertices() * g.GetNumVertices(), false);
	myQueue<T> q;
	GraphDistType<T> dist;
	dist.fromVertex = start;
	dist.toVertex = start;
	dist.distance = 0;
	T vertex;
	int minDist;

	pq.Enqueue(dist);
	g.ClearMarks();
	cout << "Start Vertex  |  Destination  |  Distance\n";
	cout << "-----------------------------------------\n";
	while (!pq.IsEmpty())
	{
		pq.Dequeue(dist);
		if (!g.IsMarked(dist.toVertex))
		{
			g.MarkVertex(dist.toVertex);
			parent[dist.toVertex] = dist.fromVertex;
			myStack<T> route;
			T cur = dist.toVertex;
			while (cur != start)
			{
				route.push(cur);
				cur = parent[cur];
			}
			route.push(start);
			while (!route.empty())
			{
				cout << route.top() << " ";
				route.pop();
			}
			cout << " ";
			cout << dist.distance << '\n';
			dist.fromVertex = dist.toVertex;
			minDist = dist.distance;
			g.GetAdjVertices(dist.fromVertex, q);
			while (!q.empty())
			{
				vertex = q.front();
				q.pop();
				if (!g.IsMarked(vertex))
				{
					dist.toVertex = vertex;
					dist.distance = minDist + g.GetWeight(dist.fromVertex, dist.toVertex);
					pq.Enqueue(dist);
				}
			}
		}
	}
}

int main()
{
	myMatrixGraph<string> g;
	// 7 Nodes
	g.AddVertex("Austin");
	g.AddVertex("Atlanta");
	g.AddVertex("Dallas");
	g.AddVertex("Chicago");
	g.AddVertex("Denver");
	g.AddVertex("Houston");
	g.AddVertex("Washington");
	// 13 Dists
	g.AddDist("Austin", "Dallas", 200);
	g.AddDist("Dallas", "Austin", 200);
	g.AddDist("Dallas", "Denver", 780);
	g.AddDist("Austin", "Houston", 160);
	g.AddDist("Dallas", "Chicago", 900);
	g.AddDist("Chicago", "Denver", 1000);
	g.AddDist("Denver", "Chicago", 1000);
	g.AddDist("Denver", "Atlanta", 1400);
	g.AddDist("Atlanta", "Houston", 800);
	g.AddDist("Atlanta", "Washington", 600);
	g.AddDist("Washington", "Dallas", 1300);
	g.AddDist("Washington", "Atlanta", 600);
	g.AddDist("Houston", "Atlanta", 800);
	//g.PrintDists();
	// Test BFS & DFS
	BFSgraph<string>(g, "Austin", "Washington");
	DFSgraph<string>(g, "Austin", "Washington");
	// Test Shortest Path Algorithm
	ShortestPath<string>(g, "Austin");
	
	return 0;
}