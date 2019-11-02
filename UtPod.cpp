#include <iostream>
#include "UtPod.h"
#include <ctime>
#include <stdlib.h>

using namespace std;
    UtPod::UtPod(){
        songs = NULL;
        memSize = MAX_MEMORY;
        unsigned int currentTime =  (unsigned)time(0);
        cout << "current time " << currentTime << endl;
        srand(currentTime);  //seed the random number generator
    }

    UtPod::UtPod(int size) {
        songs = NULL;
        if (memSize > MAX_MEMORY && memSize < 0) {
            memSize = MAX_MEMORY;
        } else {
            memSize = size;
        }
        unsigned int currentTime =  (unsigned)time(0);
        cout << "current time " << currentTime << endl;
        srand(currentTime);  //seed the random number generator
    }

    int UtPod::addSong(Song const &s) {
        if(this->getRemainingMemory()< s.getSize()){
            return NO_MEMORY;
        }
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        return SUCCESS;
    }

    int UtPod::removeSong(Song const &s) {
        SongNode *nav = new SongNode;
        SongNode *prev = new SongNode;
        nav = songs;
        prev = nav;
        while(nav != NULL){
            if(nav->s.getTitle() == s.getTitle() && nav->s.getSize() == s.getSize() && nav->s.getArtist() == s.getArtist()){
                if(prev == nav){
                    songs = nav->next;
                }
                else {
                    prev->next=nav->next;
                }
                delete nav;
                return SUCCESS;
            }
            prev = nav;
            nav = nav->next;
        }
        return NOT_FOUND;
    }

    void UtPod::showSongList() {
        SongNode *nav = new SongNode;
        nav = songs;
        while(nav != NULL){
            cout<<nav->s.getTitle()<<", "<<nav->s.getArtist()<< ", "<< nav->s.getSize()<<endl;
            nav = nav->next;
        }
        delete nav;
    }

    void UtPod::clearMemory(){
        SongNode *nav = new SongNode;
        SongNode *del = new SongNode;
        nav = del = songs;
        while(songs != NULL) {
            songs = songs->next;
            delete nav;
            nav = songs;
        }
    }

    int UtPod::getRemainingMemory() {
        int remaining = memSize;
        SongNode *nav = new SongNode;
        nav = songs;
        while(nav != NULL){
            remaining = remaining - nav->s.getSize();
            nav = nav->next;
        }
        delete nav;
        return remaining;
    }

    int UtPod::getNumSongs() {
        int numSongs = 0;
        SongNode *nav = new SongNode;
        nav = songs;
        while(nav != NULL){
            numSongs++;
            nav = nav->next;
        }
        return numSongs;
    }

    void UtPod::shuffle() {
        SongNode *nav = new SongNode;
        nav =songs;
        Song temp;
        int numSongs = this->getNumSongs();
        if (numSongs < 2)
            return;
        for (int i = 0; i < numSongs*5; i++) {
            int c = (rand()%numSongs);
            for (int j = 0; j < c; j++) {
                nav = nav->next;
            }
            temp = nav->s;
            nav->s = songs->s;
            songs->s = temp;
            nav = songs;
        }
    }


    void UtPod::sortSongList() {
        SongNode *nav = new SongNode;
        SongNode *nav2 = new SongNode;
        int swaps =1;
        nav = songs;
        nav2 = nav->next;
        int numSongs=this->getNumSongs();
        if (numSongs <2)
            return;
        while(swaps != 0){
            swaps =0;
            nav = songs;
            nav2 = nav->next;
            while(nav2 != NULL){
                if(nav2->s < nav->s){
                    Song temp = nav->s;
                    nav->s = nav2->s;
                    nav2->s = temp;
                    swaps++;
                }
                nav = nav->next;
                nav2 = nav2->next;
            }
        }
    }




UtPod::~UtPod() {
        this->clearMemory();
    };
