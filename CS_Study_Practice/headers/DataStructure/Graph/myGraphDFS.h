#pragma once
#include "myMatrixGraph.h"
#include "../myStack.h"
#include "../myQueue.h"
#include <iostream>

template <typename T>
void DFSgraph(myMatrixGraph<T>& graph, const T& start, const T& end)
{
	using namespace std;
	bool IsFound = false;
	myStack<T> st;
	myQueue<T> q;
	graph.ClearMarks();
	st.push(start);
	graph.MarkVertex(start);
	while (!st.empty() && !IsFound)
	{
		T vertex = st.top();
		st.pop();
		cout << vertex << " ";
		if (vertex == end)
		{
			IsFound = true;
			break;
		}
		graph.GetAdjVertices(vertex, q);
		while (!q.empty())
		{
			T nextVertex = q.front();
			q.pop();
			if (!graph.IsMarked(nextVertex))
			{
				st.push(nextVertex);
				graph.MarkVertex(nextVertex);
			}
		}
	}
	cout << '\n';
	if (!IsFound)
	{
		cout << "Path not found.\n";
	}
}