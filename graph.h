/* *************************************************
*  Name: Aaron Ramirez
*  Assignment: Final Project
*  Purpose: A properly constructed and commented
*           Graph class declaration file. Represents 
*           an undirected, unweighted graph.
************************************************* */

#ifndef GRAPH_H
#define GRAPH_H

// Standard
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>

// Local Headers
#include "node.h"

/**********************
* Class Definitions
***********************/

class Graph {
public:
    /**********************
    Constructors/Destructor
    **********************/
    Graph();
    ~Graph();

    /**********************
    Methods
    **********************/
    void addNode(int, const std::string&);
    void addEdge(int, int);
    void removeEdge(int, int);
    void removeNode(int);
    void printGraph();
    bool hasEdge(int, int);
    void clearGraph();

private:
    /**********************
    Attributes
    **********************/
    std::unordered_map<int, Node*> nodes;               // Map of node IDs to Node pointers
    std::unordered_map<int, std::list<int>> adjacency;  // Adjacency list representing edges

    /**********************
    Helper Methods
    **********************/
    void removeEdgesForNode(int id); // Remove all edges associated with a specific node
};

#endif // GRAPH_H
