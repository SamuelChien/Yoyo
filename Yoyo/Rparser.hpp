/*
 * File:   Rparser.h
 * Author: wutingyi
 *
 * Created on October 13, 2016, 3:30 PM
 */

#ifndef RPARSER_H
#define	RPARSER_H
#include "Resistor.hpp"
#include "Node.hpp"

extern class Resistor ** resistors;
extern class Node ** nodes;

void maxVal(int, int);
void insertR(string, double, int, int, int);
void modifyR(string, double);
void printR(string);
void printNode(int);
void deleteR();

#endif	/* RPARSER_H */

