/*
 * File:   main.cpp
 * Author: wutingyi
 *
 * Created on October 13, 2016, 3:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Rparser.hpp"
#include "Node.hpp"
#include "Resistor.hpp"

using namespace std;

#define MAX_RESISTORS_PER_NODE 5

int main() {
    string input, command, name, node;
    double resistance;
    int nodeID1, nodeID2, inputMaxNodeNumber, inputMaxResistors;
    
    int rIndex = 0;
    
    //get input
    cout << "> ";
    getline (cin, input);
    
    //continue asking for input until EOF
    while(!cin.eof()){
        
        //convert input into string stream
        stringstream inputStringStream(input);
        
        //get command from input
        inputStringStream >> command;
        
        //clear string input
        name.clear();
        node.clear();
        
        if (command == "maxVal")
        {
            inputStringStream >> inputMaxNodeNumber >> inputMaxResistors;
            maxVal(inputMaxNodeNumber, inputMaxResistors);
        }
        else if (command == "insertR")
        {
            //parser input into different variables
            inputStringStream >> name >> resistance >> nodeID1 >> nodeID2;
            
            //call insertR function
            insertR(name, resistance, nodeID1, nodeID2, rIndex);
            
        }
        else if (command == "modifyR")
        {
            //get name of resistor and its resistance
            inputStringStream >> name >> resistance;
            
            //call modifyR function
            modifyR(name, resistance);
            
        }
        else if (command == "printR")
        {
            //get name from input
            inputStringStream >> name;
            
            //call printR function
            printR(name);
        }
        else if (command == "printNode")
        {
            //get nodeID from input
            inputStringStream >> nodeID1;
            
            //call printNode function
            printNode(nodeID1);
            
        }
        else if (command == "deleteR")
        {
            //call deleteR function
            deleteR();
        }
        else
        {
            //if input command is not one of the valid commands
            cout << "Error: invalid command" << endl;
        }
        
        //continue getting user input if not EOF
        cout << "> ";
        getline (cin, input);
    }
    
    return 0;
}

