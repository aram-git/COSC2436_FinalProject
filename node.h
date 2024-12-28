/* *************************************************
*  Name: Aaron Ramirez
*  Assignment: Final Project
*  Purpose: A properly constructed and commented
*           Node class declaration file. Represents 
*           a node in the graph with a unique
*           identifier and associated data.
************************************************* */

#ifndef NODE_H
#define NODE_H

// Standard
#include <string>

/**********************
* Class Definitions
***********************/

class Node {
public:
    /**********************
    Constructors/Destructor
    **********************/
    Node(int, const std::string&);
    ~Node();

    /**********************
    Getters/Accessors
    **********************/
    void getId(int&);
    void getData(std::string&);

    /**********************
    Setters/Mutators
    **********************/
    void setData(const std::string&);

private:
    /**********************
    Attributes
    **********************/
    int id;             // Unique identifier for the node
    std::string data;   // Data associated with the node
};

#endif // NODE_H
