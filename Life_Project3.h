/****************************************************
Name:Alexander Martin
Date:03/05/2020
Problem Number:3
Hours spent solving the problem: 30
Instructor: Komogortsev, TSU
*****************************************************/

//This header file provides the prototypes of the function definitions
//for the project.

#ifndef life_h
#define life_h

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void populateWorld(const char * file);
void showWorld();
void iterateGeneration();

#endif