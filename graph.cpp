/* *************************************************
*  Name: Aaron Ramirez
*  Assignment: Final Project
*  Purpose: A properly constructed and commented
*           Graph class implementation file.
************************************************* */

#include "graph.h"

Graph::Graph()
/* **************************
 * Constructor initializes an empty graph.
 *
 * @param none
 * @exception none
 * @return none
 ****************************/
{}

Graph::~Graph()
/* **************************
 * Destructor clears the graph data structures and frees memory.
 *
 * @param none
 * @exception none
 * @return none
 ****************************/
{
    clearGraph();
}

void Graph::addNode(int id, const std::string &data)
/* **************************
 * Adds a node to the graph if the id is unique.
 *
 * @param id : unique identifier for the node
 * @param data : associated data with the node
 * @exception none
 * @return void
 ****************************/
{
    if (nodes.find(id) == nodes.end()) {
        nodes[id] = new Node(id, data);
        adjacency[id]; // Initialize adjacency list for the node
    }
}

void Graph::addEdge(int id1, int id2)
/* **************************
 * Creates an undirected edge between two nodes.
 *
 * @param id1 : first node ID
 * @param id2 : second node ID
 * @exception none
 * @return void
 ****************************/
{
    if (nodes.find(id1) != nodes.end() && nodes.find(id2) != nodes.end()) {
        adjacency[id1].push_back(id2);
        adjacency[id2].push_back(id1);
    }
}

void Graph::removeEdge(int id1, int id2)
/* **************************
 * Removes an undirected edge between two nodes.
 *
 * @param id1 : first node ID
 * @param id2 : second node ID
 * @exception none
 * @return void
 ****************************/
{
    adjacency[id1].remove(id2);
    adjacency[id2].remove(id1);
}

void Graph::removeNode(int id)
/* **************************
 * Removes the node and all edges associated with it.
 *
 * @param id : node ID to remove
 * @exception none
 * @return void
 ****************************/
{
    if (nodes.find(id) != nodes.end()) {
        removeEdgesForNode(id);
        delete nodes[id];
        nodes.erase(id);
    }
}

void Graph::removeEdgesForNode(int id)
/* **************************
 * Removes all edges connected to a specific node.
 *
 * @param id : node ID for which edges should be removed
 * @exception none
 * @return void
 ****************************/
{
    for (int neighbor : adjacency[id]) {
        adjacency[neighbor].remove(id);
    }
    adjacency.erase(id);
}

void Graph::printGraph()
/* **************************
 * Displays the graph's adjacency list.
 *
 * @param none
 * @exception none
 * @return void
 ****************************/
{
    for (const auto &pair : nodes) {
        int node_id = pair.first;
        std::string node_data;
        pair.second->getData(node_data);

        std::cout << "Node " << node_id << " (" << node_data << "): ";
        for (int neighbor : adjacency[node_id]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

bool Graph::hasEdge(int id1, int id2)
/* **************************
 * Checks if an undirected edge exists between two nodes.
 *
 * @param id1 : first node ID
 * @param id2 : second node ID
 * @exception none
 * @return bool : true if edge exists, false otherwise
 ****************************/
{
    bool edgeExists = false;

    // Check if both nodes exist in adjacency
    if (adjacency.find(id1) != adjacency.end() && adjacency.find(id2) != adjacency.end()) {
        // Check if id2 is in the adjacency list of id1
        for (const int &neighbor : adjacency[id1]) {
            if (neighbor == id2) {
                edgeExists = true;
                break;
            }
        }
    }

    return edgeExists; // Single return statement
}

void Graph::clearGraph()
/* **************************
 * Frees memory for all nodes and clears the adjacency list.
 *
 * @param none
 * @exception none
 * @return void
 ****************************/
{
    for (auto &pair : nodes) {
        delete pair.second;
    }
    nodes.clear();
    adjacency.clear();
}
