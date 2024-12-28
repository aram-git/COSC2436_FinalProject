/* *************************************************
*  Name: Aaron Ramirez
*  Assignment: Final Project
*  Purpose: A properly constructed and commented
*           Node class implementation file.
************************************************* */

#include "node.h"

Node::Node(int id, const std::string &data)
/* **************************
 * Constructor initializes a node with a unique identifier
 * and associated data.
 * 
 * @param id : unique identifier for the node
 * @param data : associated data with the node
 * @exception none
 * @return none
 ****************************/
: id(id), data(data) {}

Node::~Node()
/* **************************
 * Destructor for Node. Cleans up resources.
 *
 * @param none
 * @exception none
 * @return none
 ****************************/
{}

void Node::getId(int &id_ref)
/* **************************
 * Assigns the node ID to the provided reference.
 *
 * @param id_ref : reference to store node ID
 * @exception none
 * @return void
 ****************************/
{
    id_ref = id;
}

void Node::getData(std::string &data_ref)
/* **************************
 * Assigns the node data to the provided reference.
 *
 * @param data_ref : reference to store node data
 * @exception none
 * @return void
 ****************************/
{
    data_ref = data;
}

void Node::setData(const std::string &data)
/* **************************
 * Sets the node's data field.
 *
 * @param data : new data for the node
 * @exception none
 * @return void
 ****************************/
{
    this->data = data;
}
