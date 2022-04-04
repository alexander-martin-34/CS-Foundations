/****************************************************
Name: Alexander Martin
Date: April 16, 2020
Problem Number: 5
Hours spent working on problem: 76
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cstring>

#include "Song.h"

using namespace std;

Song::Song()																// Default constructor
{
    strcpy(artist, "<< empty >>");
    strcpy(title, "<< empty >>");
    size = 0;
    position = 0;
}

Song::Song(char *cArtist, char *cTitle, int cSize, int cPosition)			// Constructor with parameters
{
    strcpy(artist, cArtist);
    strcpy(title, cTitle);
    size = cSize;
    position = cPosition;
}

void Song::setArtist(char *songArtist)										// Sets artist private member within Song object
{
    strcpy(artist, songArtist);
}

void Song::setTitle(char *songTitle)										// Sets title private member within Song object
{
    strcpy(title, songTitle);
}

void Song::setSize(int songSize)											// Sets size private member within Song object
{
    size = songSize;
}

void Song::setPosition(int songNum)											// Sets position private member within Song object
{
    position = songNum;
}

const char* Song::getArtist() const											// Retrieves artist from Song
{
    return artist;
}

const char* Song::getTitle() const											// Retrieves title from Song
{
    return title;
}

int Song::getSize() const													// Retrieves size from Song
{
    return size;
}

bool Song::operator > (const Song &s1)
{
    bool status;

    if(strcmp (title, s1.title) > 0)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

bool Song::operator < (const Song &s1)
{
    bool status;

    if(strcmp(title, s1.title) < 0)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

bool Song::operator == (const Song &s1)
{
    bool status;

    if(strcmp (title, s1.title) == 0)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

bool Song::operator != (const Song &s1)
{
    bool status;

    if(strcmp (title, s1.title) != 0)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}