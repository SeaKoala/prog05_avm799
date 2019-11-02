/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

void check(int i){
    cout<< "Check: " << i << endl;
}

int main(int argc, char *argv[]) {
    //SONGS
    Song s1("M", "M", 257);
    Song s2("A", "A", 1);
    Song s3("B", "B", 1);
    Song s4("C", "C", 2);
    Song s5("D", "D", 1);
    Song s6("I", "I", 1);
    Song s7("J", "J", 1);
    Song s8("K", "K", 2);
    Song s9("L", "L", 2);
    Song s10("E", "E", 1);
    Song s11("F", "F", 1);
    Song s12("G", "G", 1);
    Song s13("H", "H", 1);
    Song s14("M", "M", 100);
    Song s15("X", "M", 100);
    Song s16("B", "B", 1);
    Song s17("X", "X", 12);

    {
        UtPod x(256);
        cout << "remaining Memory: " << x.getRemainingMemory()<<endl;
        cout << "add song: "<< x.addSong(s2) << endl;
        cout << "--------------------------------\n";
        x.showSongList();
        cout << "add song: "<< x.addSong(s1) << endl;
        cout << "--------------------------------\n";
        x.showSongList();
    }


    UtPod t;
    cout << "adding songs...\n";
    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    t.addSong(s5);
    t.addSong(s6);
    t.addSong(s7);
    t.addSong(s8);
    t.addSong(s9);
    t.addSong(s10);
    t.addSong(s11);
    t.addSong(s12);
    t.addSong(s13);
    t.addSong(s14);
    t.addSong(s15);
    t.addSong(s16);
    cout<< "num Songs: "<<t.getNumSongs()<<endl;
    cout<< "remaining Memory: "<<t.getRemainingMemory()<<endl;
    cout << "--------------------------------\n";
    t.showSongList();

    cout << "--------------------------------\n";
    cout << "sorting...\n";
    t.sortSongList();
    t.showSongList();

    cout << "--------------------------------\n";
    cout << "shuffling...\n";
    t.shuffle();
    t.showSongList();

    cout << "--------------------------------\n";
    cout << "shuffling...\n";
    t.shuffle();
    t.showSongList();

    cout << "--------------------------------\n";
    cout << "sorting...\n";
    t.sortSongList();
    t.showSongList();

    cout << "--------------------------------\n";
    cout << "removing songs...\n";
    cout << "remove song: "<< t.removeSong(s17) << endl;
    cout << "remove song: "<< t.removeSong(s16) << endl;
    t.showSongList();
    cout<< "num Songs: "<<t.getNumSongs()<<endl;
    cout<< "remaining Memory: "<<t.getRemainingMemory()<<endl;

    cout << "--------------------------------\n";
    cout << "clearing Memory...\n";
    t.clearMemory();
    t.showSongList();
    cout << "--------------------------------\n";
    cout<<"end test...\n";
}