/****************************************************
Name: Alexander Martin
Date: 3/20/2020
Problem Number: 4
Hours spent solving the problem: 21
Instructor: Komogortsev, TSU
*****************************************************/


#include <iostream>
#include <cstdlib>
#include <time.h>

#include "tsuPod.h"

using namespace std;

const int NUM_SONGS = 8;
const int MEMORY_SIZE = 25;

struct Song
{
    string title;
    string artist;
    int memorySize;
};

int songsAdded = 0;

Song songs[NUM_SONGS];

int memorySpace();
int EmptySpotfinder();


void initTsuPod()
{
    Song s;
    s.title = " ";
    s.artist = " ";
    s.memorySize = 0;

    for (int i = 0; i < NUM_SONGS; i++)
        songs[i] = s;
}

/**************************************************
Function will go through array of songs and
find an empty spot
It will return int index of where the empty spot is.
**************************************************/

int EmptySpotfinder()
{
    int emptySpot = 0;

    for (int i = 0; i < NUM_SONGS; i++)
        if (songs[i].artist == " ")
            emptySpot = i;

    return emptySpot;

}

int addSong(string newTitle, string newArtist, int size)
{
    int index = EmptySpotfinder();

    if (newTitle == " ") {
        cout << "Error: Title of song is blank." << endl;
        return -2; }
    else

    if (newArtist == " "){
        cout << "Error: Artist name is blank." << endl;
        return -2; }

    else

    if (size == 0) {
        cout << "Error: the size must be greater than 0." << endl;
        return -2; }
    else

    if (memorySpace() < size) { //There is not enough memory to store song
        cout << "Error: There is not enough memory in TsuPod for this song." << endl;
        return -1; }
    else

    if (songsAdded == NUM_SONGS) {
        cout << "Error: Limit is 8 songs. " << endl;
        return -2; }

    else

        songs[index].title = newTitle;
    songs[index].artist = newArtist;
    songs[index].memorySize = size;

    songsAdded++;

    return 0;
}

int removeSong(string title)
{
    for (int i = 0; i < NUM_SONGS; i++)
    {
        if (songs[i].title==title)
        {
            songs[i].title = " ";
            songs[i].artist = " ";
            songs[i].memorySize = 0;

            songsAdded--;

            return 0;
        }
    }

    cout << "Error: there is no song with that title. " << endl;
    return -1;

}

void clearMemory()
{
    initTsuPod();
}
/********************************************
Function shows the list of available songs
********************************************/
void showSongList()
{
    Song s;
    int numberSong = 1;

    for (int i = 0; i < NUM_SONGS; i++)
    {
        cout << numberSong << ". ";
        cout << "Title: " << songs[i].title << " - ";
        cout << "Artist: " << songs[i].artist << " - ";
        cout << "Size: " << songs[i].memorySize << "MB" << endl;
        numberSong++;
    }
}
/******************************************
Function shuffles the list of songs
******************************************/
void shuffle()
{
    int currentTime =  time(0);
    srand(currentTime);

    int rand1;
    int rand2;
    Song test;

    for (int i = 0; i < NUM_SONGS * 2; i++)
    {
        rand1 = rand() % NUM_SONGS;
        rand2 = rand() % NUM_SONGS;

        test = songs[rand1];
        songs[rand1] = songs[rand2];
        songs[rand2] = test;
    }

}

/***************************************************
Function: memorySpace
Goes through array of songs and figures out how much
memory is left.
Returns int memory left in MG.
****************************************************/

int memorySpace()
{
    int SumMemory = 0;
    int remainingMemory = 0;

    for (int i = 0; i < NUM_SONGS; i++)
    {
        SumMemory = SumMemory + songs[i].memorySize;
    }

    remainingMemory = MEMORY_SIZE - SumMemory;

    return remainingMemory;
}