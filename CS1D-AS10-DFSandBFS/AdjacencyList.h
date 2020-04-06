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


#endif _ADJACENCYLIST_H_