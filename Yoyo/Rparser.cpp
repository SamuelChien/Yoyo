/*
 * File:   parser.cpp
 * Author: wutingyi
 *
 * Created on September 27, 2016, 1:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "Rparser.hpp"
#include "Node.hpp"
#include "Resistor.hpp"

using namespace std;

#define MAX_NODE_NUMBER 5000
int maxNodeNumber, maxResistors;

void maxVal(int inputMaxNodeNumber, int inputMaxResistors){
    if (inputMaxNodeNumber <= 0 || inputMaxResistors <= 0)
    {
        cout << "Error: maxVal arguments must be greater than 0" << endl;
    }
    else
    {
        maxNodeNumber = inputMaxNodeNumber;
        maxResistors =inputMaxResistors;
        cout << "New network: max node number is " << maxNodeNumber
        << "; max resistors is " << maxResistors << endl;
        
        //TODO: loop through both pointer array and free the memeory
        
        nodes = new Node * [maxNodeNumber];
        for (int i = 0; i < MAX_RESISTORS_PER_NODE; i++){
            nodes[i] = new Node[MAX_RESISTORS_PER_NODE];
        }
        
        resistors = new Resistor * [maxResistors];
    }
}

void insertR(string name, double resistance, int nodeID1, int nodeID2, int rIndex){
    
    bool resExist = false;
    
    for (int i = 0;(resistors[i]) != NULL && i < maxResistors ; i++)
    {
        if(name == resistors[i]->getName())
        {
            resExist = true;
            i = maxResistors;
        }
    }
    
    if (nodeID1 < 0 || nodeID2 < 0 || nodeID1 > maxNodeNumber || nodeID2 > maxNodeNumber)
    {
        cout << "Error: node ";
        
        if (nodeID1 < 0 || nodeID1 > maxNodeNumber)
        {
            cout << nodeID1;
        }
        else
        {
            cout << nodeID2;
        }
        
        cout << " is out of permitted range 0-" << maxNodeNumber << endl;
    }
    
    //print if resistor array is full
    else if (rIndex == maxResistors){
        cout << "Error: resistor array is full" << endl;
    }
    
    //print if resistor array is full
    else if (!nodes[nodeID1]->canAddResistor(rIndex)|| !nodes[nodeID2]->canAddResistor(rIndex))
    {
        cout << "Error: node is full" << endl;
    }
    
    /*
     else if (resExist)
     {
     cout << "Error: resistor " << name << " already exists" << endl;
     }*/
    
    //print if both input NodeIDs are the same
    else if (nodeID1 == nodeID2)
    {
        cout << "Error: both terminals of resistor connect to node " << nodeID1 << endl;
    }
    
    //print regular output
    else
    {
        cout << "Inserted: resistor " << name << " ";
        cout << fixed << setprecision(2) << resistance;
        cout << " Ohms " << nodeID1 << " -> " << nodeID2 << endl;
        
        int endpoints_[2];
        endpoints_[0] = nodeID1;
        endpoints_[1] = nodeID2;
        
        //add 1 resistor to resistor array with 2 entries in node array
        
        resistors[rIndex] = new Resistor(rIndex, name, resistance, &endpoints_[2]);
        rIndex+=1;
    }
}

void modifyR(string name, double resistance){
    //print regular modifyR output
    cout << "Modified: resistor " << name << " to ";
    cout << fixed << setprecision(2) << resistance << " Ohms " << endl;
    
}

void printR(string name){
    //print if name of resistor typed is 'all'
    if (name == "all")
    {
        cout << "Print: all resistors" << endl;
    }
    
    //print regular output
    else
    {
        cout << "Print: resistor " << name << endl;
    }
}

void printNode(int nodeID){
    //print if the two nodeIDs are out of the correct range
    if (nodeID < 0 || nodeID > maxNodeNumber)
    {
        cout << "Error: node " << nodeID << " is out of permitted range 0-" << maxNodeNumber << endl;
    }
    
    //print regular output
    else
    {
        cout << "Connections at node " << nodeID << ": " << nodes[nodeID]->getNumRes() <<endl;
        
    }
}

void deleteR(){
    cout << "Deleted: all resistors" << endl;
}


