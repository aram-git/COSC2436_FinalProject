/* *************************************************
*  Name: Aaron Ramirez
*  Assignment: Final Project
*  Purpose: A properly constructed and commented
*           application driver for the Graph class.
************************************************* */

#include "graph.h"

int main() {
/* *************************************************
* The entry point of the program to test
* various functionalities of the Graph class.
*
* Parameters: none
* Return: int - Returns 0 upon successful execution.
* ************************************************ */
    int testId = 0; // Counter to label each test case

    Graph graph;

    /* **********************************
     * Test 1: Adding Nodes
     ********************************** */
    std::cout << "Test " << ++testId << ": Adding nodes" << std::endl;
    graph.addNode(1, "Node 1");
    graph.addNode(2, "Node 2");
    graph.addNode(3, "Node 3");
    graph.addNode(4, "Node 4");
    graph.printGraph(); // Should display 4 nodes with no edges

    /* **********************************
     * Test 2: Adding Edges
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Adding edges" << std::endl;
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.printGraph(); // Should display connections based on edges added

    /* **********************************
     * Test 3: Checking Edge Existence
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Checking edge existence" << std::endl;
    std::cout << "Edge exists between 1 and 2: " << (graph.hasEdge(1, 2) ? "Yes" : "No") << std::endl;
    std::cout << "Edge exists between 1 and 4: " << (graph.hasEdge(1, 4) ? "Yes" : "No") << std::endl;
    std::cout << "Edge exists between 2 and 4: " << (graph.hasEdge(2, 4) ? "Yes" : "No") << std::endl;

    /* **********************************
     * Test 4: Removing Edges
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Removing edges" << std::endl;
    graph.removeEdge(1, 2);
    std::cout << "Edge between 1 and 2 after removal: " << (graph.hasEdge(1, 2) ? "Yes" : "No") << std::endl;
    graph.printGraph(); // Should no longer show edge between 1 and 2

    /* **********************************
     * Test 5: Removing Nodes
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Removing nodes" << std::endl;
    graph.removeNode(3);
    graph.printGraph(); // Node 3 should no longer exist
    std::cout << "Edge between 1 and 3 after node 3 removal: " << (graph.hasEdge(1, 3) ? "Yes" : "No") << std::endl;

    /* **********************************
     * Test 6: Underflow Conditions
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Underflow conditions" << std::endl;
    graph.removeNode(10); // Node 10 does not exist
    graph.removeEdge(1, 10); // Edge between 1 and non-existent node 10
    graph.printGraph(); // Graph should remain unchanged

    /* **********************************
     * Test 7: Adding and Removing Multiple Nodes
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Adding and removing multiple nodes" << std::endl;
    for (int i = 5; i <= 10; ++i) {
        graph.addNode(i, "Node " + std::to_string(i));
    }
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);
    graph.addEdge(7, 8);
    graph.addEdge(9, 10);
    graph.printGraph(); // Should include nodes 1, 2, 4, and 5-10

    graph.removeNode(6);
    graph.removeNode(8);
    graph.printGraph(); // Nodes 6 and 8 should no longer exist

    /* **********************************
     * Test 8: Redundant Edges (Overflow Test)
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Redundant edges (overflow test)" << std::endl;
    graph.addEdge(5, 6); // Node 6 does not exist anymore; no edge should be added
    graph.addEdge(9, 10); // Already exists, should not add duplicate
    graph.printGraph(); // Check for no invalid edges or duplicates

    /* **********************************
     * Test 9: Stress Test
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Stress test - Adding many nodes and edges" << std::endl;
    graph.clearGraph();
    const int largeSize = 1000;
    for (int i = 1; i <= largeSize; ++i) {
        graph.addNode(i, "Node " + std::to_string(i));
    }
    for (int i = 1; i < largeSize; ++i) {
        graph.addEdge(i, i + 1);
    }
    std::cout << "Stress test complete: 1000 nodes added and connected in a chain.\n";

    /* **********************************
     * Test 10: Edge Existence in Stress Test
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Checking edges in large graph" << std::endl;
    std::cout << "Edge exists between 1 and 2: " << (graph.hasEdge(1, 2) ? "Yes" : "No") << std::endl;
    std::cout << "Edge exists between 500 and 501: " << (graph.hasEdge(500, 501) ? "Yes" : "No") << std::endl;
    std::cout << "Edge exists between 999 and 1000: " << (graph.hasEdge(999, 1000) ? "Yes" : "No") << std::endl;
    std::cout << "Edge exists between 1 and 1000: " << (graph.hasEdge(1, 1000) ? "Yes" : "No") << std::endl;

    /* **********************************
     * Test 11: Clearing the Graph
     ********************************** */
    std::cout << "\nTest " << ++testId << ": Clearing the graph" << std::endl;
    graph.clearGraph();
    graph.printGraph(); // Should display an empty graph

    return 0;
}
