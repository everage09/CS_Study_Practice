#pragma once
#include "myMatrixGraph.h"
#include "../myQueue.h"
#include <iostream>

template <typename T>
void BFSgraph(myMatrixGraph<T>& graph, const T& start, const T& end)
{
	using namespace std;
	bool IsFound = false;
	myQueue<T> q;
	myQueue<T> adj;
	graph.ClearMarks();
	q.push(start);
	graph.MarkVertex(start);
	while (!q.empty() && !IsFound)
	{
		T vertex = q.front();
		q.pop();
		cout << vertex << " ";
		if (vertex == end)
		{
			
			IsFound = true;
			break;
		}
		graph.GetAdjVertices(vertex, adj);
		while (!adj.empty())
		{
			T next = adj.front();
			adj.pop();
			if (!graph.IsMarked(next))
			{
				q.push(next);
				graph.MarkVertex(next);
			}
		}
	}
	cout << '\n';
	if (!IsFound)
	{
		cout << "Path not found.\n";
	}
}
