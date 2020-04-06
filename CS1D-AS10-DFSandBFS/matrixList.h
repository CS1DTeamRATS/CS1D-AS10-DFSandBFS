
#ifndef MATRIXLIST_H_
#define MATRIXLIST_H_


#include <vector>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

struct Vertex
{
	string name; //Vertex name
	int number; //Vertex number
};

class matrixList
{
	static const int MAX_VERTEX = 12;
	static const int INFINITY = 10000;


public:
	/************************************************************************
	 * matrixList()
	 * This constructor will initialize the variables
	 ***********************************************************************/
	matrixList();

	/************************************************************************
	 * matrixList()
	 * This destructor will destroy all the variables
	 ***********************************************************************/
	~matrixList();

	/************************************************************************
	 * insertEdge()
	 * This method will insert an edge between origin vertex and destination
	 * vertex with the given weight
	 * -> RETURN nothing
	 * POST: put the edge's weight into the adjacencyMatrix
	 * **If undirected -> add to 2 spots
	 * If difrected -> add to 1 spot
	 ***********************************************************************/
	void insertEdge(int originNumber, //IN - The number of origin vertex
			int destinationNumber, //IN - The number of dest vertex
			double weight); //IN - The weight of the edge

	/************************************************************************
	 * insertVertex()
	 * This method will insert a vertex name vName
	 * -> RETURN nothing
	 * POST: create new vertex and add that new vertex to vertex list
	 ***********************************************************************/
	void insertVertex(string vName); //IN - The Vertex name

	/************************************************************************
	 * * depthFirstTraversal()
	 * This method will perform a depth first traversal and print the list in
	 * order
	 * -> RETURN nothing
	 ***********************************************************************/
	void depthFirstTraversal(int startVertex); //IN - Start vertex number

	/************************************************************************
	 * printMatrix()
	 * This method will print the graph adjacencyList
 	 * -> RETURN nothing
 	 ***********************************************************************/
	void printMatrix();

	void DistDFS();

private:
	vector <Vertex> vertexList; //The Vertex list
	vector <double> totDistance; //Total DFS distance
	double adjacencyMatrix[MAX_VERTEX][MAX_VERTEX]; //Adjacency Matrix for edge
	int totalVertex; //Total num of vertices
	// int count = 0;

protected:
	/************************************************************************
	 * printMatrix()
	 * This method will print the matrix in the parameter
	 * -> RETURN nothing
	 ***********************************************************************/
	void depthFirst(int startVertex, //IN - Start Vertex Num
			double matrix[][MAX_VERTEX], //IN & OUT - weight Matrix
			vector<int>& visitedVertices); //OUT - visited vertex list

	/************************************************************************
	 * printMatrix()
	 * This method will print the matrix in the parameter
	 * -> RETURN nothing
	 ***********************************************************************/
	void printMatrix(double matrix[][MAX_VERTEX]); //IN - weight Matrix
};

matrixList::matrixList()
{
	totalVertex = 0;
	int row, col;
	// vertexList.reserve(10);

	for(row = 0; row < MAX_VERTEX; row++)
	{
		for(col = 0; col < MAX_VERTEX; col++)
		{
			adjacencyMatrix[row][col] = INFINITY;
		}
	}
}

matrixList::~matrixList(){}
void matrixList::insertEdge(int originNumber, int destinationNumber, double weight)
{
	adjacencyMatrix[originNumber][destinationNumber] = weight;
	// adjacencyMatrix[destinationNumber][originNumber] = weight;
}

void matrixList::insertVertex(string vName)
{
	Vertex newVertex;
	newVertex.name = vName;
	newVertex.number = totalVertex;
	// adjacencyMatrix[totalVertex][totalVertex] = 0;
	totalVertex++;
	vertexList.push_back(newVertex);
}

void matrixList::depthFirstTraversal(int startVertex)
 {
	int col, row;

	double matrix[MAX_VERTEX][MAX_VERTEX];

	for(row = 0; row < MAX_VERTEX; row++)
	{
		for(col = 0; col < MAX_VERTEX; col++)
		{
			matrix[row][col] = adjacencyMatrix[row][col];
		}
	}

	vector<int> visitedVertices;
	visitedVertices.push_back(startVertex);

	depthFirst(startVertex, matrix, visitedVertices);

	// for(int index = 0; index < visitedVertices.size(); index++)
	// {
	// cout << visitedVertices[index];
	// cout << endl;
	// }

	cout << "Depth First Traversal\n";
	//Print out the visited node
	for(int index = 0; index < (int)visitedVertices.size(); index++)
	{
		cout << vertexList[visitedVertices[index]].name << endl;
	}
}

void matrixList::depthFirst(int startVertex, double matrix[][MAX_VERTEX], vector<int>&visitedVertices)
{
	// count++;
	// cout << "Start count: "<< count << endl;
	double lowestWeight;
	int lowestWeightIndex = startVertex;
	bool visitedAll = false;

	// cout << "Start Vertex is: " << startVertex << endl;
	// cout << "Print Matrix:\n";
	// printMatrix(matrix);
	// cin.ignore(1000, '\n');

	//Make visited vertex unavailable by blank out that column
	for(int index = 0; index < MAX_VERTEX; index++)
	{
		matrix[index][startVertex] = INFINITY;
	}



	//Keep checking adjacent edge until all adjacent edges is visited all
	while(!visitedAll)
	{
		lowestWeight = INFINITY;
		//Find the one that is the closest
		for(int index = 0; index < MAX_VERTEX; index++)
		{
			if(matrix[startVertex][index] < lowestWeight)
			{
				lowestWeight = matrix[startVertex][index];
				lowestWeightIndex = index;
				cout << "lowestWeight: " << lowestWeight << " vertex: " << lowestWeightIndex <<
						endl;
			}

		}

		//cout << matrix[startVertex][lowestWeightIndex] << endl << endl;
		if(matrix[startVertex][lowestWeightIndex] != INFINITY)
		{
			totDistance.push_back(matrix[startVertex][lowestWeightIndex]);
		}

		// cout << "End finding the closest\n";



		//If found a closest adjacent vertex -> call on itself, otherwise ->stop
		if(lowestWeight != INFINITY)
		{

			//Clear the path that we will take
			matrix[startVertex][lowestWeightIndex] = INFINITY;

			visitedVertices.push_back(lowestWeightIndex);

			// cout << "Lowest weight is: "<< lowestWeight << endl;
			depthFirst(lowestWeightIndex, matrix, visitedVertices);
			// cout << "Return to count: " << count << endl;
		}
		else
		{// cout << "In else\n";
			// cout << "Start vertex is: " << startVertex << endl;
			// cout << "Visited All\n";
			visitedAll = true;
		}
	   	   }//End while

	   	   // cout << "Return the stack\n";
}


	   // get the discovery edges
vector<string> matrixList::getDiscoveryEdges(vector<string> &dfsGraph)
{
	vector<nodeEdge> discEdges; // vector of discovery edges

	for(int i = 0; i < graph.size(); i++)
	{ // gets all the disc edges
		int dfsIndex = findVertex(dfsGraph.at(i));

		for(int j = 0; j < graph.at(dfsIndex).edgeList.size(); j++) {
			if(graph.at(dfsIndex).edgeList.at(j).discEdge)
			{
				discEdges.push_back(graph.at(dfsIndex).edgeList.at(j));
			}
		}
	}

	deleteDuplicates(discEdges); // delete duplicates

	vector<nodeEdge>::iterator edgeIt = discEdges.begin(); // goes to the beginning disc


	vector<string> discoveryEdges; // disc edge pairs

	while(edgeIt != discEdges.end())
	{
		discoveryEdges.push_back("(" + edgeIt->startCity + ", " + edgeIt->endCity + ")");

		edgeIt++;
	}

	return discoveryEdges;
	}

vector<string> matrixList::getBackEdges(vector<string> &dfsGraph)
{
	vector<nodeEdge> backEdges; // vector - back edges

	for(int i = 0; i < graph.size(); i++) { // adds back edges
		int dfsIndex = findVertex(dfsGraph.at(i));

		for(unsigned int j = 0; j < graph.at(dfsIndex).edgeList.size(); j++)
		{
			if(!(graph.at(dfsIndex).edgeList.at(j).discEdge))
			{ // adds only
				if its a back edge
				backEdges.push_back(graph.at(dfsIndex).edgeList.at(j));
			}
		}
	}

	deleteDuplicates(backEdges); // delete duplicates

	vector<nodeEdge>::iterator edgeIt = backEdges.begin(); // starts at begin of vector

	vector<string> backEdgeList; // back edge pairs

	while(edgeIt != backEdges.end())
	{ // (startCity, endCity)
		backEdgeList.push_back("(" + edgeIt->startCity + ", " + edgeIt->endCity + ")");

		edgeIt++;
	}

return backEdgeList;
}

	   // goes to the smallest edge for DFS search
int matrixList::smallestEdgeDFS(int currVertex, vector<string> &dfsGraph)
{
	if(edgesDiscovered(currVertex) != graph.at(currVertex).edgeList.size())
	{
		int smallestIndex = 0;
		int compIndex = smallestIndex + 1;

		int size = graph.at(currVertex).edgeList.size(); // get current size

		while(compIndex < size) {
			int smallestVertex =
					findVertex(graph.at(currVertex).edgeList.at(smallestIndex).endCity);
			int compVertex = findVertex(graph.at(currVertex).edgeList.at(compIndex).endCity);

			if(graph.at(smallestVertex).visited)
			{
				smallestIndex++;
			}
			else
			{
				if(!(graph.at(compVertex).visited)) {
					if(graph.at(currVertex).edgeList.at(smallestIndex).weight >=
							graph.at(currVertex).edgeList.at(compIndex).weight) {
						smallestIndex = compIndex;
					}
				}
			}
			compIndex++;
		}
		graph.at(currVertex).edgeList.at(smallestIndex).discEdge = true;
		dfsDistance += graph.at(currVertex).edgeList.at(smallestIndex).weight;
		string nextCity = graph.at(currVertex).edgeList.at(smallestIndex).endCity;
		smallestIndex = findVertex(nextCity);

		for(int i = 0; i < graph.at(smallestIndex).edgeList.size(); i++) {
			if(graph.at(currVertex).city == graph.at(smallestIndex).edgeList.at(i).endCity) {
				graph.at(smallestIndex).edgeList.at(i).discEdge = true;
			}
		}
		return smallestIndex;
	}
	else
	{
		vector<string>::iterator dfsIt = find(dfsGraph.begin(), dfsGraph.end(),
				                              graph.at(currVertex).city);
		dfsIt--;

		int backIndex = findVertex(*dfsIt);

		return smallestEdgeDFS(backIndex, dfsGraph);
	}
}


void matrixList::printMatrix()
{
	int col, row;

	for(row = 0; row < MAX_VERTEX; row++)
	{
		for(col = 0; col < MAX_VERTEX; col++)
		{
			cout << setw(6) << adjacencyMatrix[row][col];
		}

		cout << endl;
	}
}

void matrixList::printMatrix(double matrix[][MAX_VERTEX])
{
	int col, row;

	cout << setw(6) << "";

	for(col = 0; col < MAX_VERTEX; col++)
	{
		cout << setw(6) << col;
	}
	cout << endl;



	for(row = 0; row < MAX_VERTEX; row++)
	{
		cout << setw(6) << row;

		for(col = 0; col < MAX_VERTEX; col++)
		{
			cout << setw(6) << matrix[row][col];
		}

		cout << endl;
	}
}

void matrixList::DistDFS()
{
	double sum = 0;
	while(!totDistance.empty())
	{
		sum += totDistance.back();
		totDistance.pop_back();
	}


	cout << "Discovery Distance for DFS: " << sum << endl << endl;
}







#endif /* MATRIXLIST_H_ */
