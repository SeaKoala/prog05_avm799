//
// Created by aknk0 on 10/29/2019.
//

#ifndef SONG_H
#define SONG_H
#include <string>
using namespace std;
class Song {
private:
    string title;
    string artist;
    int size;

public:
    Song();
    Song(string a, string t, int s); //takes artist, title, and size
    const string getTitle() const;
    const string getArtist() const;
    const int getSize() const;
    void setTitle(string t);
    void setArtist(string a);
    void setSize(int a);
    bool operator >(Song const &rs);
    bool operator ==(Song const &rs);
    bool operator <(Song const &rs);
    ~Song();
};
#endif
