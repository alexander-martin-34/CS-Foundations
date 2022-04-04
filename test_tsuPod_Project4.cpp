/****************************************************
Name: Alexander Martin
Date: 3/20/2020
Problem Number: 4
Hours spent solving the problem: 21
Instructor: Komogortsev, TSU
*****************************************************/


#include <iostream>
#include <fstream>

#include "tsuPod.h"

using namespace std;

int main()
{

    cout << "Displaying testing of all functions: " << endl << endl;

    cout << "Successful initialization of TsuPod: "<< endl;
    initTsuPod();

    showSongList();
    cout << endl;

    cout << "Successful addition of songs: " << endl;

    int retCode;

    retCode = addSong("Waves", "Electric Guest", 1);
    retCode = addSong("Leave In My Dreams", "The Voidz", 2);
    retCode = addSong("Bad Decisions", "The Strokes", 3);
    retCode = addSong("Carrion Crawler", "Thee Oh Sees", 4);
    retCode = addSong("Didnt I", "The Delfonics", 1);
    retCode = addSong("Agnes", "Glass Animals", 6);
    retCode = addSong("New Orleans", "BrockHampton", 1);
    retCode = addSong("Ready To Let Go", "Cage The Elephant", 1);

    cout << retCode << endl;

    showSongList();
    cout << endl;

    cout << "Unsuccessful addition of song without title: " << endl;
    retCode = addSong(" ", "Blue October", 3);
    cout << retCode << endl; // Should return -2
    cout << endl;

    cout << "Unsuccessful addition of song without artist: " << endl;
    retCode = addSong("Into the Ocean", " ", 4);
    cout << retCode << endl; // Should return -2
    cout << endl;

    cout << "Unsuccessful addition of song of no size: " << endl;
    retCode = addSong("Supersize Me", "Toothpick", 0);
    cout << retCode << endl; // Should return -2
    cout << endl;

    cout << "Unsuccessful addition of song when there is no memory: " << endl;
    retCode = addSong("The Notorious B.I.G", "Big Poppa", 20);
    cout << retCode << endl; // Should return -2
    cout << endl;

    cout << "Unsuccessful addition of nineth song: " << endl;
    retCode = addSong("Mo Bamba", "Sheck Wes", 1);
    cout << retCode << endl; // Should return -2
    cout << endl;

    cout << "Successful shuffle: " << endl;
    shuffle();

    showSongList();
    cout << endl;

    cout << "Successful removal of song: " << endl;
    retCode = removeSong("Waves");
    cout << retCode << endl;

    showSongList();
    cout << endl;

    cout << "Unsuccessful removal of song. Song with wrong title: " << endl;

    retCode = removeSong("I couldnt think of a song name");
    cout << retCode << endl;

    showSongList();
    cout << endl;

    cout << "Testing clearing of memory: " << endl;
    clearMemory();

    showSongList();
    cout << endl;

    return 0;
}
