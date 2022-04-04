/****************************************************
Name:Alexander Martin
Date:03/05/2020
Problem Number:3
Hours spent solving the problem: 30
Instructor: Komogortsev, TSU
*****************************************************/

//This file provides the implementation of the life.h header file.

#include <iostream>
#include <fstream>
#include "life.h"

using namespace std;

//GLOBAL VARIABLES

int ROWS;         //stores the number of rows in the grid
int COLUMNS;      //stores the number of rows in the grid
char ** world;	  //store values of world
int ** nb;	  //store value of neighbor counts for world

//This function reads input file for subsequent prosessing
void getGrid(const char * file)
{
    ifstream fin;
    fin.open(file);
    char ch;

    //Check file opens
    if(fin.fail())
        cout << "Could not open the input file" << endl;

    //this is going to read in the grid
    while(fin.get(ch))
    {
        if(ch == 48 || ch-1 == 48)
            COLUMNS++;
        if(ch == '\n')
            ROWS++;
    }

    //here were gonna get the column #
    COLUMNS = COLUMNS/ROWS;
    cout << "ROWS: " << ROWS << " COLUMNS: " << COLUMNS << endl;

    //Close file
    fin.close();
}

//here were going to get the count per neighbor
int Count(int row, int col)
{
    //find nighbor count
    int count = 0;

    //ipper ledt neighbor count
    if(*(* (world + (row - 1)) + (col - 1)) == 49)
        count++;

    //The left neighbor
    if(*(* (world + row) + (col - 1)) == 49)
        count++;

    //the bottom left neighbor
    if(*(* (world + (row + 1)) + (col - 1)) == 49)
        count++;

    //Neighbor beneath
    if(*(* (world + (row + 1)) + col) == 49)
        count++;

    //Bottom right diagonal neighbor
    if(*(* (world + (row + 1)) + (col + 1)) == 49)
        count++;

    //Right neighbor
    if(*(* (world + row) + (col + 1)) == 49)
        count++;

    //Right upper diagonal neighbor
    if(*(* (world + (row - 1)) + (col + 1)) == 49)
        count++;

    //Neighbor above
    if(*(* (world + (row - 1)) + col) == 49)
        count++;

    //return total neighbor count
    return count;
}

void countNeighbors()
{
    cout << "Number of Neighbors" << endl;

    //For every row and column with an organism, count neighbors
    for(int j = 1; j < (ROWS + 1); j++)
    {
        for(int k = 1; k < (COLUMNS + 1); k++)
        {
            //get neighbor count
            *(* (nb + j) + k) = Count(j, k);

            cout << *(* (nb + j) + k);
        }
        cout << endl;
    }

}

//Populate the world with data on live/dead cells
void populateWorld (const char * file)
{
    //Initialize variables
    ROWS = 0;
    COLUMNS = 0;
    char go;
    ifstream fin;//make file object

    //Read in grid
    getGrid(file);

    //Open file
    fin.open(file);

    //If file doesn't open give error
    if(fin.fail())
        cout << "Could not open the input file" << endl;


    //Make memory for my world
    world = new char * [ROWS + 2];
    for(int row = 0; row < ROWS + 2; row++)
        world[row] = new char [COLUMNS + 2];

    //Initialize memory for my world
    for(int row = 0; row < ROWS + 2; row++)
        for(int col = 0; col < COLUMNS + 2; col++)
            *(* (world + row) + col) = 48;

    //Make memory for nb
    nb = new int * [ROWS + 2];
    for(int row = 0; row < ROWS + 2; row++)
        nb[row] = new int [COLUMNS + 2];

    //Initialize nb to zero
    for(int row = 0; row < ROWS + 2; row++)
        for(int col = 0; col < COLUMNS + 2; col++)
            *(* (world + row) + col) = 0;

    //Read in world values
    for(int row = 1; row < ROWS + 1; row++)
    {
        for(int col = 1; col < COLUMNS + 1; col++)
        {
            fin.get(go);

            //If 1 or 0 read in value
            if(go == 48 || go - 1 == 48)
                *(* (world + row) + col) = go;
        }
        fin.ignore();
    }
    fin.close();
}

//This function outputs the grid for current generation
void showWorld ()
{
    cout << endl << "Next Generation: " << endl;

    //show content for every row and column
    //keep in mind buffer of zeros around world
    for(int r = 1; r < ROWS + 1; r++)
    {
        for(int c = 1; c < COLUMNS + 1; c++)
        {
            cout << *(* (world + r) + c);
        }
        cout << endl;
    }

}

//This function creats new geneneration grid from the old generation grid
void iterateGeneration ()
{
    //Count neighbors
    countNeighbors();

    //Create and allocate memory for next generation
    char ** Genx;
    Genx = new char * [ROWS + 2];
    for(int row = 0; row < ROWS + 2; row++)
        Genx[row] = new char [COLUMNS + 2];

    //Initialize next generation
    for(int row = 0; row < ROWS + 2; row++)
        for(int col = 0; col < COLUMNS + 2; col++)
            *(* (Genx + row) + col) = 48;

    //Check if next generation organism becomes alive/dead
    for(int row = 1; row < ROWS + 1; row++)
    {
        for(int col = 1; col < COLUMNS + 1; col++)
        {
            //Rule one: alive if world was dead with nb is 3
            if( (*(* (world + row) + col) == 48) &&
                (*(* (nb + row) + col) == 3))
                *(* (Genx + row) + col) = 49;

            //Rule two: dead if nb is 4 or more
            if( (*(* (world + row) + col) == 49) &&
                (*(* (nb + row) + col) >= 4))
                *(* (Genx + row) + col) = 48;

            //Rule three: dead if nb is one or fewer
            if( (*(* (world + row) + col) == 49) &&
                (*(* (nb + row) + col) < 2))
                *(* (Genx + row) + col) = 48;

            //Rule four: alive if nb is 2 or more
            if( (*(* (world + row) + col) == 49) &&
                (*(* (nb + row) + col) == 2) ||
                (*(* (nb + row) + col) == 3))
                *(* (Genx + row) + col) = 49;

        }
    }

    //Output next generation world
    cout << "Next Generation" << endl;
    for(int row = 1; row < ROWS + 1; row++)
    {
        for(int col = 1; col < COLUMNS + 1; col++)
        {
            cout << *(* (Genx + row) + col);
        }
        cout << endl;
    }

    //Clear memory for next iteration
    delete world;
    world = Genx;
}