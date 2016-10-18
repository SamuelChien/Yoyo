#include <cstdlib>
#include <iostream>
#include <string>
#include <valarray>

#include "Rparser.hpp"
#include "Resistor.hpp"

Resistor ** resistors;

Resistor::Resistor(int rIndex_,string name_,double resistance_,int endpoints_[2])
: name(name_), resistance(resistance_){
    // rIndex_ is the index of this resistor in the resistor array
    // endpoints_ holds the node indices to which this resistor connects
    rIndex_ = rIndex_;
    endpoints_[0] = endpoints_[0];
    endpoints_[1] = endpoints_[1];
}

Resistor::~Resistor(){
    delete [] resistors;
}

string Resistor::getName() const{
    return name;
} // returns the name

double Resistor::getResistance() const{
    return resistance;
} // returns the resistance

void Resistor::setResistance (double resistance_){
    resistance = resistance_;
}

void Resistor::print(){
    //for (int i = 0; i < maxResistors; i++)
    // cout
}