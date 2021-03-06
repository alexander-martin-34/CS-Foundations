/****************************************************
Name: Alexander Martin
Date: April 16, 2020
Problem Number: 5
Hours spent working on problem: 76
Instructor: Komogortsev, TSU
*****************************************************/
#ifndef TSUPOD_H_
#define TSUPOD_H_

#include "Song.h"
#include <string>
#include <fstream>

using namespace std;

class TsuPod
{
private:
    Song song;
    int numSongs;
    int maxSize;
    fstream fio;
public:
    TsuPod();
    TsuPod(int, int);
    int initTsuPod();
    int addSong(string, string, int, int, int&, int&);
    int removeSong(string, string, int, int, int&, int&);
    int clearSongList();
    int showSongList();
    int sortSongList(int);
    int getTotalMemory() const;
    int getRemainingMemory(int) const;
    int getNumSongs() const;
    int closeFile();
    void setSong(Song);
};

#endif /* TSUPOD_H_ */
