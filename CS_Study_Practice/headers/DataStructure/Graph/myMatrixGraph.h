#pragma once
#include "../myQueue.h"
#include "../myStack.h"
#include "../headers/DataStructure/Tree/myPriorityQueue.h"
#include <iostream>

const int NULL_Dist = 0;

template <typename T>
class myMatrixGraph {
public:
	myMatrixGraph();
	myMatrixGraph(int maxV);
	~myMatrixGraph();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void AddVertex(T vertex);
	void AddDist(T vertex1, T vertex2, int weight);
	int GetWeight(T vertex1, T vertex2);
	void GetAdjVertices(T v, myQueue<T>& queue); // Return Adjacent Vertices
	void PrintDists();
	inline int GetNumVertices() const { return numVertices; }

	void ClearMarks();
	void MarkVertex(T v);
	bool IsMarked(T v) const;

private:
	int GetIndex(T vertex) const;

	int numVertices;
	int maxVertices;
	T* vertices;
	int** Dists;
	bool* marks; // for dfs and bfs
};

template<typename T>
inline myMatrixGraph<T>::myMatrixGraph() : myMatrixGraph<T>(50) {}

template<typename T>
inline myMatrixGraph<T>::myMatrixGraph(int maxV)
{
	numVertices = 0;
	maxVertices = maxV;
	vertices = new T[maxV];
	Dists = new int*[maxV];
	for (int i = 0; i < maxV; i++)
	{
		Dists[i] = new int[maxV];
		for (int j = 0; j < maxV; j++)
		{
			Dists[i][j] = NULL_Dist;
		}
	}
	marks = new bool[maxV] {false};
}

template<typename T>
inline myMatrixGraph<T>::~myMatrixGraph()
{
	delete[] vertices;
	for (int i = 0; i < maxVertices; i++)
	{
		delete[] Dists[i];
	}
	delete[] Dists;
	delete[] marks;
}

template<typename T>
inline void myMatrixGraph<T>::MakeEmpty()
{
	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			Dists[i][j] = NULL_Dist;
		}
	}
	numVertices = 0;
}

template<typename T>
inline bool myMatrixGraph<T>::IsEmpty() const
{
	return numVertices == 0;
}

template<typename T>
inline bool myMatrixGraph<T>::IsFull() const
{
	return numVertices == maxVertices;
}

template<typename T>
inline void myMatrixGraph<T>::AddVertex(T vertex)
{
	vertices[numVertices] = vertex;
	for (int i = 0; i <= numVertices; i++)
	{
		Dists[i][numVertices] = NULL_Dist;
		Dists[numVertices][i] = NULL_Dist;
	}
	marks[numVertices] = false;
	numVertices++;
}

template<typename T>
inline void myMatrixGraph<T>::AddDist(T vertex1, T vertex2, int weight)
{
	int row;
	int col;
	row = GetIndex(vertex1);
	col = GetIndex(vertex2);
	Dists[row][col] = weight;
}

template<typename T>
inline int myMatrixGraph<T>::GetIndex(T vertex) const
{
	for (int i = 0; i < numVertices; i++)
	{
		if (vertices[i] == vertex) return i;
	}
	return -1;
}

template<typename T>
inline int myMatrixGraph<T>::GetWeight(T vertex1, T vertex2)
{
	int row;
	int col;
	row = GetIndex(vertex1);
	col = GetIndex(vertex2);
	return Dists[row][col];
}

template<typename T>
inline void myMatrixGraph<T>::GetAdjVertices(T v, myQueue<T>& queue)
{
	int fromIndex = GetIndex(v);
	for (int toIndex = 0; toIndex < numVertices; toIndex++)
	{
		if (Dists[fromIndex][toIndex] != NULL_Dist)
		{
			queue.push(vertices[toIndex]);
		}
	}
}

template<typename T>
inline void myMatrixGraph<T>::PrintDists()
{
	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < numVertices; j++)
		{
			std::cout << Dists[i][j] << " ";
		}
		std::cout << '\n';
	}
}

template<typename T>
inline void myMatrixGraph<T>::ClearMarks()
{
	for (int i = 0; i < numVertices; i++)
	{
		marks[i] = false;
	}
}

template<typename T>
inline void myMatrixGraph<T>::MarkVertex(T v)
{
	int idx = GetIndex(v);
	marks[idx] = true;
}

template<typename T>
inline bool myMatrixGraph<T>::IsMarked(T v) const
{
	int idx = GetIndex(v);
	return marks[idx];
}
