//
// Created by aknk0 on 10/29/2019.
//

#include "Song.h"
using namespace std;
Song::Song()= default;

Song::Song(string a, string t, int s){
    title = t;
    artist = a;
    size = s;
}

const string Song::getArtist() const{
    return artist;
}

const string Song::getTitle() const {
    return title;
}

const int Song::getSize() const{
    return size;
}
bool Song::operator >(Song const &rs){
    if(artist != rs.getArtist()){
        return(artist > rs.getArtist());
    }
    else if(title != rs.getTitle()){
        return(title > rs.getTitle());
    }
    else if(size != rs.getSize()){
        return(size > rs.getSize());
    }
    else
        return false;
}
bool Song::operator ==(Song const &rs){
    return(artist == rs.getArtist() && title == rs.getTitle() && size == rs.getSize());
}
bool Song::operator <(Song const &rs){
    if(artist != rs.getArtist()){
        return(artist < rs.getArtist());
    }
    else if(title != rs.getTitle()){
        return(title < rs.getTitle());
    }
    else if(size != rs.getSize()){
        return(size < rs.getSize());
    }
    else
        return false;
}

    void Song::setTitle(string t) {
    this->title = t;
}

    void Song::setArtist(string a) {
    this->artist = a;
}

    void Song::setSize(int s)  {
    this->size = s;
}


Song::~Song() = default;
