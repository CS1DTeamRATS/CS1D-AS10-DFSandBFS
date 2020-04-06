#include <iostream>
#include "DFS.h" // change
#include "BFS.h" // change

using namespace std;

string PrintHeader( string programmer, //IN - programmer(s)'s name
					char asType, //IN - assignment type
					string asName, //IN & OUT - assignment name
					int asNum); //IN & OUT - assignment number
int main()
{
	Graph graph;

	cout << PrintHeader("", 'A', "Directed Graph", 9);

	graph.insertVertex("Los Angeles"); //0
	graph.insertVertex("San Francisco"); //1
	graph.insertVertex("Seattle"); //2
	graph.insertVertex("Denver"); //3
	graph.insertVertex("Chicago"); //4
	graph.insertVertex("Kansas City"); //5
	graph.insertVertex("Dallas"); //6
	graph.insertVertex("Houston"); //7
	graph.insertVertex("Miami"); //8
	graph.insertVertex("Atlanta"); //9
	graph.insertVertex("New York"); //10
	graph.insertVertex("Boston"); //11

	//Los Angeles
	graph.insertEdge(1, 0, 381);
	graph.insertEdge(0, 3, 1015);
	graph.insertEdge(5, 0, 1663);
	graph.insertEdge(6, 0, 1435);


	//San Francisco
	graph.insertEdge(2, 1, 807);
	graph.insertEdge(3, 1, 1267);


	//Seattle
	graph.insertEdge(2, 3, 1331);
	graph.insertEdge(4, 2, 2097);

	//Denver
	graph.insertEdge(3, 4, 1003);
	graph.insertEdge(5, 3, 599);

	//Chicago
	graph.insertEdge(5, 4, 533);
	graph.insertEdge(10, 4, 787);
	graph.insertEdge(4, 11, 983);
	//Kansas
	graph.insertEdge(6, 5, 496);
	graph.insertEdge(5, 9, 864);
	graph.insertEdge(5, 10, 1260);

	//Dallas
	graph.insertEdge(7, 6, 239);
	graph.insertEdge(6, 9, 781);

	//Houston
	graph.insertEdge(8, 7, 1187);
	graph.insertEdge(7, 9, 810);

	//Miami
	graph.insertEdge(9, 8, 661);

	//Atlanta
	graph.insertEdge(10, 9, 888);

	//New York
	graph.insertEdge(11, 10, 214);

	graph.depthFirstTraversal(4);
	graph.DistDFS();

	vector<string> keys;
	vector<Vertex<string>> neighbors;
	keys.push_back("Seattle");
	keys.push_back("San Francisco");
	keys.push_back("Los Angeles");
	keys.push_back("Denver");
	keys.push_back("Chicago");
	keys.push_back("Kansas City");
	keys.push_back("Dallas");
	keys.push_back("Houston");
	keys.push_back("Boston");
	keys.push_back("New York");
	keys.push_back("Atlanta");
	keys.push_back("Miami");

	GraphBFS<string> BFSList(keys);
	Vertex<string> v1("San Francisco", 807);
	Vertex<string> v2("Denver", 1331);

	neighbors.push_back(v1);
	neighbors.push_back(v2);

	BFSList.AddNeighbors("Seattle", neighbors);

	neighbors.clear();

	Vertex<string> v3("Los Angeles", 381);

	neighbors.push_back(v3);

	BFSList.AddNeighbors("San Francisco", neighbors);

	neighbors.clear();

	Vertex<string> v4("Denver", 1015);
	neighbors.push_back(v4);

	BFSList.AddNeighbors("Los Angeles", neighbors);

	neighbors.clear();

	Vertex<string> v5("Chicago", 1003);
	Vertex<string> vtx6("San Francisco", 1267);

	neighbors.push_back(v5);
	neighbors.push_back(vtx6);

	BFSList.AddNeighbors("Denver", neighbors);

	neighbors.clear();

	Vertex<string> v6("Boston", 983);
	Vertex<string> v7("Seattle", 2097);

	neighbors.push_back(v6);
	neighbors.push_back(v7);

	BFSList.AddNeighbors("Chicago", neighbors);

	neighbors.clear();

	Vertex<string> v8("Los Angeles", 1663);
	Vertex<string> v9("Chicago", 533);
	Vertex<string> v10("Denver", 599);
	Vertex<string> v11("New York", 1260);
	Vertex<string> vtx12("Atlanta", 864);

	neighbors.push_back(v8);
	neighbors.push_back(v9);
	neighbors.push_back(v10);
	neighbors.push_back(v11);
	neighbors.push_back(vtx12);

	BFSList.AddNeighbors("Kansas City", neighbors);

	neighbors.clear();

	Vertex<string> v12("Atlanta", 781);
	Vertex<string> v13("Los Angeles", 1435);
	Vertex<string> v14("Kansas City", 496);

	neighbors.push_back(v12);
	neighbors.push_back(v13);
	neighbors.push_back(v14);

	BFSList.AddNeighbors("Dallas", neighbors);

	neighbors.clear();

	Vertex<string> v15("Atlanta", 810);
	Vertex<string> v16("Dallas", 239);
	neighbors.push_back(v15);
	neighbors.push_back(v16);

	BFSList.AddNeighbors("Houston", neighbors);

	neighbors.clear();

	Vertex<string> v17("New York", 214);

	neighbors.push_back(v17);

	BFSList.AddNeighbors("Boston", neighbors);

	neighbors.clear();

	Vertex<string> v18("Atlanta", 888);
	Vertex<string> v19("Chicago", 787);

	neighbors.push_back(v18);
	neighbors.push_back(v19);

	BFSList.AddNeighbors("New York", neighbors);

	neighbors.clear();

	Vertex<string> v20("Miami", 661);

	neighbors.push_back(v20);

	BFSList.AddNeighbors("Atlanta", neighbors);

	neighbors.clear();

	Vertex<string> v21("Houston", 1187);

	neighbors.push_back(v21);

	BFSList.AddNeighbors("Miami", neighbors);

	neighbors.clear();

	BFSList.BreadthFirstSearch("Chicago");

	if(BFSList.IsStronglyConnected("Chicago"))
	{
		cout << "This directed graph is strongly connected!\n";
	}
	else
	{
		cout << "This directed graph is NOT strongly connected!\n";
	}

	cout << endl << endl;
// graph.breathFirstTraversal(4);
}

