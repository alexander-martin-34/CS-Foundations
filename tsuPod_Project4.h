/****************************************************
Name: Alexander Martin
Date: 3/20/2020
Problem Number: 4
Hours spent solving the problem: 21
Instructor: Komogortsev, TSU
*****************************************************/


#ifndef tsuPod_h
#define tsuPod_h


#include <string>

using namespace std;


/* FUNCTION - void initTsuPod
 Initialize all the slots to blank and 0 size memory
*/

void initTsuPod ();


/* FUNCTION - int addSong
 * attempts to add a new song to the tsuPod
          returns a 0 if successful
          returns -1 if not enough memory to add the song
          returns -2 for blank titles or artists
*/

int addSong (string newTitle, string newArtist, int size);



/* FUNCTION - int removeSong
    tries to remove a song from the tsuPod
          returns 0 if successful
          returns -1 if nothing is removed
*/

int removeSong (string title);



/*
Function - void clearMemory
it clears all the songs from the memory
*/
void clearMemory();



/*
Function - void showSongList
    * prints the current list of songs in order from first to last to standard output
    * format - slot #, Title, Artist, size in MB (one song per line)
    * print "Empty" for any slots that do not contain a song
input parms -
output parms -
*/

void showSongList ();



/* FUNCTION - void shuffle
    *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list
input parms -
output parms -
*/

void shuffle ();


#endif