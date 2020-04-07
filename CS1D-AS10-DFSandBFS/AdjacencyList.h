/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Assignment #10	: DFS and BFS
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 04 / 06 / 20
 *****************************************************************************/
#ifndef _ADJACENCYLIST_H_
#define _ADJACENCYLIST_H_

#include <string>
#include <iostream>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>

enum EdgeType
{
	DISCOVERY,
	BACK
};

template <typename vertexType>
struct Edge
{

	void Set(EdgeType newType, vertexType newSource, vertexType newDestination)
	{
		type = newType;
		source = newSource;
		destination = newDestination;
	}

	EdgeType type;
	vertexType source;
	vertexType destination;
};

template <typename vertexType>
struct Vertex
{
	Vertex(vertexType setData = vertexType(), double dist = 0) : data{ setData }, distance{ dist } {}

	vertexType data;
	double weight;
};

template <typename vertexType>
class AdjacencyList
{
private:

	std::vector<std::vector<double>> adjList;
	std::vector<vertexType> verticeskey;
	std::vector<bool> visited;



	int FindKeyIndex(vertexType key)
	{
		for (unsigned int i = 0; i < verticesKey.size(); i++)
		{
			if (key == verticesKey[i])
			{
				return i;
			}
		}
		return -1;
	}


	bool visitedAll() const
	{
		for (unsigned int i = 0; i < visited.size(); i++)
		{
			if (!visited[i])
			{
				return true;
			}
		}

		return false;
	}


	int DistanceColumn(int row, double weight)
	{
		for (int col = 0; col < matrix[row].size(); col++)
		{
			if (matrix[row][col] == d)
			{
				return col;
			}
		}

		return -1;
	}

protected:

public:

	AdjacencyList(std::vector<vertexType> newVector = std::vector<vertexType>())
	{

		int vectorSize = newVector.size();

		matrix.resize(vectorSize)

			for (unsigned int i = 0; i < vectorSize; i++)
			{
				matrix[i].resize(vectorSize)
			}

		for (unsigned int i = 0; i < vectorSize; i++)
		{
			for (unsigned int j = 0; i < vectorSize; i++)
			{
				matrix[i][j] = 0;
			}
		}

		for (unsigned int i = 0; i < vectorSize; i++)
		{
			verticesKey.push_back(v[i]);
		}
	}


	~AdjacencyList()
	{
	}

	void AddNeighbors(vertexType vertex, std::vector<Vertex<vertexType>> neighbors)
	{
		if (FindKeyIndex(vertex) == -1)
		{
			verticesKey.push_back(vertex);
		}

		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			if (FindKeyIndex(neighbors[i].data) == -1)
			{
				verticesKey.push_back(neighbors[i].data);
				matrix.resize(verticesKey.size());

				for (unsigned int j = 0; j < verticesKey.size(); j++)
				{
					matrix[j].resize(verticesKey.size());
				}
			}
		}

		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			matrix[FindKeyIndex(vertex)][FindKeyIndex(neighbors[i].data)] = neighbors[i].distance;
		}
	}


	void BreadthFirstSearch(vertexType start)
	{
		// Mark all the vertices as not visited 
		std::vector<Edge<T>> edges;
		Edge<string> push;
		std::vector<double> closest;
		std::list<T> queue;
		visited.resize(verticesKey.size());
		int key = 0;
		int column = 0;
		double distanceTraveled = 0;
		for (unsigned int i = 0; i < visited.size(); i++) //set visited 
		{
			visited[i] = false;
		}

		cout << "Breadth First Search: \n";

		// Mark the current node as visited and enqueue it 
		visited[FindKeyIndex(start)] = true;
		queue.push_back(start);

		while (!queue.empty() && !VisitedAll()) //while queue is not empty and everything has not been visited 
		{
			start = queue.front();  //"set" current vertex 
			key = FindKeyIndex(start); //find row of current vertex 

			for (unsigned int i = 0; i < matrix[key].size(); i++)
			{
				if (matrix[key][i] > 0)
				{
					closest.push_back(matrix[key][i]);
				}
			}

			sort(closest.begin(), closest.end());


			for (unsigned int i = 0; i < closest.size(); i++)
			{
				column = DistanceColumn(key, closest[i]);
				if (column != -1)
				{
					if (!visited[column] && matrix[key][column] > 0) //if vertex is not visited, mark as discovery 
					{
						visited[column] = true;
						queue.push_back(verticesKey[column]);


						push.Set(DISCOVERY, start, verticesKey[column]);
						edges.push_back(push);

					}
					else if (visited[column] && matrix[key][column] > 0) //if it is visited, mark as back 
					{
						push.Set(BACK, start, verticesKey[column]);
						edges.push_back(push);
					}
				}
			}
			queue.pop_front(); //remove front of queue to move on to next vertex of traversal 
		}

		for (unsigned int i = 0; i < edges.size(); i++) //output 
		{
			switch (edges[i].type)
			{
				case DISCOVERY: cout << "Discovery Edge: " << edges[i].first << "->" << edges[i].second << endl;
					distanceTraveled += matrix[FindKeyIndex(edges[i].first)][FindKeyIndex(edges[i].second)];
					break;
				case BACK: cout << "Back Edge: " << edges[i].first << "->" << edges[i].second << endl;
					break;
			}
		}

		cout << "Total distance traveled: " << distanceTraveled << " miles\n\n";
	}


	void DisplayMatrix() const
	{
		cout << "Adjacency Matrix:\n";
		cout << setw(15) << " ";
		for (unsigned int i = 0; i < verticesKey.size(); i++)
		{
			cout << verticesKey[i] << "|";
		}
		cout << endl;

		for (unsigned int row = 0; row < matrix.size(); row++)
		{
			cout << setw(13) << verticesKey[row] << " |";
			for (unsigned int col = 0; col < matrix[row].size(); col++)
			{
				cout << setw(verticesKey[col].length()) << matrix[row][col] << "|";
			}
			cout << endl;
		}
		cout << endl;
	}


	bool IsStronglyConnected(vertexType start)
	{
		std::vector<std::vector<double>> reverse;
		std::vector<std::vector<double>> restore;
		reverse.resize(matrix.size());
		restore.resize(matrix.size());
		for (unsigned int i = 0; i < reverse.size(); i++)
		{
			reverse[i].resize(matrix[i].size());
			restore[i].resize(matrix[i].size());
		}

		cout << "Checking graph connection...\n";

		for (unsigned int row = 0; row < matrix.size(); row++)
		{
			for (unsigned int col = 0; col < matrix[row].size(); col++)
			{
				if (matrix[row][col] > 0)
				{
					reverse[col][row] = matrix[row][col];
					restore[row][col] = matrix[row][col];
				}
			}
		}

		for (unsigned int row = 0; row < matrix.size(); row++)
		{
			for (unsigned int col = 0; col < matrix[row].size(); col++)
			{
				matrix[row][col] = reverse[row][col];
			}
		}

		BreadthFirstSearch(start);

		for (unsigned int row = 0; row < matrix.size(); row++)
		{
			for (unsigned int col = 0; col < matrix[row].size(); col++)
			{
				matrix[row][col] = restore[row][col];
			}
		}

		return VisitedAll();

	}

};

#endif _ADJACENCYLIST_H_