#include <cstdlib>
#include <iostream>

#define MAX_RESISTORS_PER_NODE 5

#include "Rparser.hpp"
#include "Node.hpp"

using namespace std;

Node ** nodes;

Node::Node(){
    //&nodes = new Node * MAX_RESISTORS_PER_NODE;
}

Node::~Node(){
    
    delete [] nodes;
}

// Checks to see if the resistor can be added to position rIndex
// in the resistor array. Returns true if yes, otherwise false.
bool Node::canAddResistor(int rIndex){
    if (rIndex == MAX_RESISTORS_PER_NODE)
        return false;
    else
        return true;
}

// Updates resIDArray to make the resistor in position rIndex in
// the resistor array connected to this node.
void Node::addResistor (int rIndex){
    resIDArray[numRes++] = rIndex;
}

// prints the whole node
// nodeIndex is the position of this node in the node array.
void Node::print (int nodeIndex){
    for (int i = 0; i < numRes; i++){
        
    }
}

int Node::getNumRes(){
    return numRes;
}

