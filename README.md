## Assignment: Final Project
## Author: Aaron Ramirez
## Purpose:
This project builds on concepts from the entire course, implementing a C++ data structure that supports adding, removing, clearing, and displaying elements, similar to the stack and BST assignments. It demonstrates advanced knowledge of graph theory, algorithms, and object-oriented programming (OOP) best practices while prioritizing modularity, loose coupling, and efficiency. The program is tested comprehensively under scenarios such as underflow, overflow, midpoint, and stress cases. Dynamic memory management enables the graph to scale efficiently, supporting optimal operations on nodes and edges through a structured, step-by-step algorithm for performing and managing graph operations.

## Undirected Graph Implementation
This program represents an undirected graph, which means every edge connects two nodes in both directions. In the code, the addEdge() method inserts the edge in both adjacency lists:

- adjacency[id1].push_back(id2);
- adjacency[id2].push_back(id1);

By adding each new connection to both nodes’ adjacency lists, the graph ensures that traversal can occur in either direction along any edge. Similarly, when removeEdge() is called, it removes the connection from both nodes, maintaining the undirected property.

## Modularity
The program fulfills the "separation of interface from implementation" requirement by defining class interfaces in header files (graph.h and node.h) and implementing their functionality in separate source files (graph.cpp and node.cpp). This structure ensures modularity and maintainability, with headers providing clear interfaces while .cpp files encapsulate implementation details. The separation of concerns between the Graph and Node classes further reinforces loose coupling: the Node class manages individual attributes and methods, while the Graph class handles the overall structure and relationships using an adjacency list. This design allows independent modifications to either class, promoting flexibility and maintainability.

## Node Processing
An adjacency list is the program's core data structure, efficiently representing the graph by associating each node with a list of its neighboring nodes. Instead of relying on a fixed-size matrix, the adjacency list uses a hash map, where each key represents a node's unique identifier (id), and the value is a dynamically managed list of neighboring node IDs. This structure minimizes memory usage and allows the graph to grow dynamically to any size or configuration without predefined limits. Nodes are allocated memory as needed, and edges are stored in the adjacency list, enabling efficient addition and removal of graph elements while maintaining performance.

Each node is uniquely identified by an id and associated with a descriptive data string, which provides additional information about the node. The id serves as a key for efficient lookup and management in both the nodes map and adjacency list. When a node is added via the addNode() method, its id is registered in the adjacency list, and memory for the node object is dynamically allocated. The data string can be accessed or updated through the getData() and setData() methods, ensuring that nodes remain functional and meaningful while maintaining data integrity. By enabling efficient neighbor access and scaling memory usage with the number of edges, the adjacency list optimizes graph operations such as traversal, exploration, and manipulation, making it ideal for algorithms like breadth-first search, depth-first search, and pathfinding, while ensuring scalable performance.

## Features and Methods
Below is a list of implemented methods, their functionality, and how they fulfill the assignment requirements:

1. Node Management: 
- addNode(int id, const std::string &data)

//Adds a new node with a unique identifier and associated data. Ensures nodes are dynamically created and managed.

- removeNode(int id)

//Removes a node and all edges connected to it. Utilizes helper methods to clear associated edges.

2. Edge Management
- addEdge(int id1, int id2)

//Adds an undirected edge between two existing nodes. Prevents duplicate edges.

- removeEdge(int id1, int id2)

//Removes an undirected edge between two nodes. Updates the adjacency list dynamically.

3. Graph Utilities
- printGraph()

//Displays the graph as an adjacency list, showing connections between nodes.

- hasEdge(int id1, int id2)

//Checks if an edge exists between two nodes and returns a boolean result.

- clearGraph()

//Deletes all nodes and edges, resetting the graph to an empty state.

## Detailed Test Descriptions
This section describes the logic and purpose of each test case in the program.

1. Adding Nodes
- Purpose: Verifies the functionality of addNode() by adding nodes with unique IDs and associated data.
- Logic: Calls addNode() multiple times to add nodes. Ensures the adjacency list initializes correctly.
- Outcome: Displays all added nodes without edges.

2. Adding Edges
- Purpose: Tests addEdge() by connecting nodes with undirected edges.
- Logic: Adds edges between pairs of nodes and prints the graph.
- Outcome: Displays connections between nodes in the adjacency list.

3. Checking Edge Existence
- Purpose: Confirms hasEdge() correctly identifies if an edge exists.
- Logic: Calls hasEdge() for valid and invalid edges.
- Outcome: Accurately reports edge existence.

4. Removing Edges
- Purpose: Verifies removeEdge() by removing specific edges and re-checking the graph.
- Logic: Removes an edge, then prints the graph.
- Outcome: The adjacency list no longer contains the removed edge.

5. Removing Nodes
- Purpose: Tests removeNode() by deleting a node and all its associated edges.
- Logic: Removes a node, prints the graph, and checks edge existence.
- Outcome: The node and its edges are successfully deleted.

6. Underflow Conditions
- Purpose: Ensures robustness when removing non-existent nodes or edges.
- Logic: Calls removeNode() and removeEdge() on absent nodes/edges.
- Outcome: Graph remains unchanged; no errors occur.

7. Adding and Removing Multiple Nodes
- Purpose: Verifies handling multiple additions and removals.
- Logic: Adds several nodes/edges, then removes a subset to test dynamic updates.
- Outcome: Maintains proper connections and structure after changes.

8. Redundant Edges (Overflow Test)
- Purpose: Ensures no duplicate edges are added.
- Logic: Attempts to add redundant edges and checks adjacency.
- Outcome: The graph prevents duplicate edges.

9. Stress Test
- Purpose: Evaluates performance and scalability with a large number of nodes and edges.
- Logic: Adds 1,000 nodes and connects them in a linear chain.
- Outcome: Efficiently handles the large dataset.

10. Checking Edges in a Large Graph
- Purpose: Ensures hasEdge() works correctly in large graphs.
- Logic: Calls hasEdge() for specific edges in the 1,000-node graph.
- Outcome: Accurately identifies edge existence in the large graph.

## Program Logic
1. Dynamic Memory Management:
Uses pointers for node objects.
clearGraph() frees all memory, preventing leaks.

2. Adjacency List:
Uses an adjacency list for efficient edge operations.
Each node has a list of neighbors.

3. Helper Methods:
removeEdgesForNode(int id) removes all edges for a given node, improving readability and modularity.

4. Error Checking:
Validates inputs to avoid operations on non-existent nodes or edges.
Maintains data integrity by preventing duplicate edges or nodes.

## Assignment Requirements Mapping
- Add nodes dynamically: addNode(int id, const std::string &data)
- Add edges dynamically: addEdge(int id1, int id2)
- Remove nodes and associated edges: removeNode(int id) with removeEdgesForNode(int id)
- Remove edges: removeEdge(int id1, int id2)
- Display graph structure: printGraph()
- Check if an edge exists: hasEdge(int id1, int id2)
- Clear the graph: clearGraph()
- Support for large graphs: Stress tested with 1,000+ nodes and edges
- Efficient dynamic memory management: Dynamic allocation for nodes, adjacency list
- Underflow and boundary testing: Comprehensive tests in main.cpp

## Real-World Applications and Potential Modifications of the Graph Program
This graph program has numerous real-world applications, as graphs are integral to modeling and solving a wide range of problems. For example, undirected graphs can represent social networks, where nodes represent individuals and edges represent relationships. They can also be used in network design, memory management, and various communication or transportation systems.

Making the Graph Directed:

To modify the code for a directed graph, change the addEdge() method so it inserts the edge only in one direction. For example:

- adjacency[id1].push_back(id2);
- // Do not add adjacency[id2].push_back(id1];

This ensures that edges have a direction, representing one-way relationships or dependencies.

Making the Graph Weighted:

To introduce weights, replace the lists of node IDs with a list of pairs (or a custom struct) containing both the node ID and the edge weight. For example:

- std::unordered_map<int, std::list<std::pair<int, int>>> adjacency;

Then modify addEdge() to include the weight and adjust any algorithms (like pathfinding) to consider these weights during computations.

By implementing such changes, the program could model workflows, dependency trees, traffic flow, or shortest path calculations, demonstrating its flexibility and utility in real-world computing scenarios.

## Compilation and Execution
To compile the program, run:

- g++ main.h main.cpp graph.h graph.cpp node.h node.cpp -o graph_app

This will generate an executable file named graph_app.

Run the program using:

- ./graph_app

This README provides an overview of the program's structure, logic, and functionality, along with instructions for compilation, execution, and potential real-world modifications.