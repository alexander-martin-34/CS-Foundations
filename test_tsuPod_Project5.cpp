/****************************************************
Name: Alexander Martin
Date: April 16, 2020
Problem Number: 5
Hours spent working on problem: 76
Instructor: Komogortsev, TSU
*****************************************************/
#include <iostream>
#include <fstream>

#include "tsuPod.h"
#include "Song.h"

using namespace std;

int main()
{
    TsuPod tsuPod(25, 100);									// Constructor of TsuPod with 25 songs, 100 max memory
    int totalSongs = 0;										// Starting number of songs of blank TsuPod
    int totalMemory = 0;									// Starting memory of blank TsuPod


    int retCode;											// Return code for error coding

    retCode = tsuPod.initTsuPod();                          // Calls tsuPod member function initTsuPod, initiates tsuPod to all blank songs
    if(retCode == -1)
    {
        cout << "Unable to open file. Closing...";
        return -1;
    }

    cout << "Total Memory: " << tsuPod.getRemainingMemory(totalMemory) << endl;

    retCode = tsuPod.showSongList();                        // Calls tsuPod member function showSongList, shows list of songs in tsuPod



    cout << endl;

    // Following lines tests tsuPod input functionality by adding songs through tsuPod member function addSong

    retCode = tsuPod.addSong("Waves", "Electric Guest", 3, 1, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Leave In My Dreams", "The Voidz", 7, 2, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Bad Decisions", "The Strokes", 5, 3, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Carrion Crawler", "Thee Oh Sees", 1, 4, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Didnt I", "The Delfonics", 4, 5, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Agnes", "Glass Animals", 3, 6, totalMemory, totalSongs);
    retCode = tsuPod.addSong("New Orleans", "BrockHampton", 1, 7, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Ready To Let Go", "Cage The Elephant", 3, 8, totalMemory, totalSongs);
    retCode = tsuPod.addSong("All Your Love", "Jacob Ogawa", 5, 9, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Green Eyes", "Wavves", 7, 10, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Calling It", "Automatic", 3, 11, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Heybb!", "binki", 1, 12, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Alien Blues", "Vundabar", 5, 13, totalMemory, totalSongs);
    retCode = tsuPod.addSong("L.S.D", "Skegss", 7, 14, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Some", "Steve Lacy", 4, 15, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Golden Sun", "Hotel Eden", 1, 16, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Looking Out for You", "Joy Again", 5, 17, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Chicago", "Flipturn", 3, 18, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Gutter Girl", "Hot Flash Heat Wave", 1, 19, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Gotta Get Away", "Vista Kicks", 3, 20, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Crust Bucket", "The Frights", 5, 21, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Only in the West", "Yeek", 7, 22, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Every Single Thing", "HOMESHAKE", 5, 23, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Sweet FA", "Peach Pit", 8, 24, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Think Of You", "Rodriguez", 3, 25, totalMemory, totalSongs);
    retCode = tsuPod.addSong("I Wonder", "Rodriguez", 3, 25, totalMemory, totalSongs);
    retCode = tsuPod.addSong("Think Of You", "Rodriguez", 3, 25, totalMemory, totalSongs);          //SUCCESSFUL song addition

    cout << "Error Code: " << retCode << endl << endl;

    tsuPod.showSongList();

    // Shows remaining memory in tsuPod
    cout << "Remaining memory: " << tsuPod.getRemainingMemory(totalMemory) << " MB"  << endl;

    // UNSUCCESSFUL song addition
    retCode = tsuPod.addSong("Think Of You", "Rodriguez", 3, 25, totalMemory, totalSongs);

    // Calls tsuPod member function sortSongList, sorts songs in alphabetical order by title
    tsuPod.sortSongList(totalSongs);


    // Shows sorted song list
    tsuPod.showSongList();

    // Shows remaining memory in tsuPod
    cout << "Remaining memory: " << tsuPod.getRemainingMemory(totalMemory) << " MB"  << endl;

    // SUCCESSFUL song removal from tsuPod
    retCode = tsuPod.removeSong("Ready To Let Go", "Cage The Elephant", 3, 8, totalMemory, totalSongs);

    // Shows song list after removal of song
    tsuPod.showSongList();

    // Shows remaining memory in tsuPod after removing a song
    cout << "Remaining memory: " << tsuPod.getRemainingMemory(totalMemory) << " MB" << endl << endl;

    // Calls tsuPod member function clearSongList, clears all songs within tsuPod
    tsuPod.clearSongList();

    tsuPod.showSongList();


    // Closes binary file
    tsuPod.closeFile();

    return 0;
}
