#include <iostream>

using namespace std;
#include "Playlist.h"

void PrintMenu(string playlistTitle);
int main()

{

    string playlistTitle;
    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);

    cout << endl;
    PrintMenu(playlistTitle);
}

//menu for playlist:
void PrintMenu(string playlistTitle)
{
    PlaylistNode *head = nullptr;
    PlaylistNode *tail = nullptr;

    char userInput;
    bool quit = false;

    while (!quit)
    {
        cout << playlistTitle << " PLAYLIST MENU" << endl;
        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << endl;
        cout << "Choose an option:" << endl;

        cin >> userInput;
        if (userInput == 'q') // quits the menu
        {
            quit = true;
        }
        //adds song nodes to the playlist
        if (userInput == 'a')
        {
            string myID, mySongName, mySongArtist;
            int mySongLength;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> myID;
            cin.ignore();
            cout << "Enter song's name:" << endl;
            getline(cin, mySongName);
            cout << "Enter artist's name:" << endl;
            getline(cin, mySongArtist);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> mySongLength;
            //

            PlaylistNode *curr = new PlaylistNode(myID, mySongName, mySongArtist, mySongLength);
            //if empty, adds playlistnode curr
            if (!head)
            {

                head = tail = curr;
            }
            //sets next to curr if only one song.
            else if (head == tail)
            {

                tail->SetNext(curr);
                tail = curr;
            }
            //else curr is set to tail
            else
            {

                tail->SetNext(curr);
                tail = curr;
            }
            cout << endl;
        }
        if (userInput == 'd')
        {
            string myID;
            PlaylistNode *i = head;
            PlaylistNode *curr = i->GetNext();

            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;

            cin >> myID;

            if (!head) // if empty
            {
                return;
            }
            // if one song, remove the head and set to nullptr
            else if (head == tail) 
            {
                if (i->GetID() == myID)
                {
                    cout << "\"" << i->GetSongName() << "\""
                         << " removed" << endl;
                    delete head;
                    head = tail = nullptr;
                }
            }

            else
            {// else traverse through to find matching ID to delete.
                while (curr)
                {

                    if (curr->GetID() == myID)
                    {//if two songs, then delete node and set head to nullptr
                        if (curr == head->GetNext() && head->GetNext() == tail)
                        {
                            delete curr;
                            tail = head = nullptr;
                        }
                        else
                        {
                            cout << "\"" << curr->GetSongName() << "\""
                                 << " removed." << endl;
                            i->SetNext(curr->GetNext());
                            delete curr;
                            if (!i->GetNext())
                            {
                                i = tail;
                            }
                        }
                    }
                    i = curr;
                    curr = curr->GetNext();
                }
            }
            cout << endl;
        }

        if (userInput == 'c')
        {
            PlaylistNode *i = head;
            PlaylistNode *changeSong;
            PlaylistNode *newSongPos;
            PlaylistNode *curr = head;
            PlaylistNode *prev = head;            
            
            PlaylistNode *prevChange = nullptr;
            
            
            int numSongs = 0;
            int myPos, newPos;
            int currPos = 1;
            int newPosCounter = 1;

            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> myPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;

            while (i) //counts total number of songs in the playlist.
            {
                numSongs++;
                i = i->GetNext();
            }

            if(newPos <= 1)
            {
                newPos = 1;
            }
           if (newPos >= numSongs)
            {
                newPos = numSongs;
            }

            //traverse to find the node at old position.
            while (currPos != myPos)
            {
                //set node previous to tail to be the tail, if song to change position is tail.
                if (curr->GetNext() == tail) 
                {
                    tail = curr;
                     
                }
                //sets the prevChange to tail
                if (currPos == myPos - 1)
                {
                    prevChange = curr;
                   
                }
                curr = curr->GetNext();
                currPos++;
            }
            
            //traverse to find the node at new position
            changeSong = curr;
            curr = head;
            while (newPosCounter != newPos)
            {
                 // find node previous to newPosition, when nodes change position towards tail.
                if (newPosCounter >= 3 && myPos > newPos) 
                {
                    prev = prev->GetNext();
                }
                curr = curr->GetNext();
                newPosCounter++;
               
            }
        
            //Moving the head node (1 pt)
             newSongPos = curr;
            if (changeSong == head)
            {
                head = head->GetNext();
                newSongPos->InsertAfter(changeSong);
            }
             //Moving the tail node (1 pt)
           else if (changeSong == tail)
            { 
                if (newSongPos != head) 
                {
                    prev->InsertAfter(changeSong);
                }
                else
                 //Moving a node to the head (1 pt)
                {
                    changeSong->SetNext(head);
                    head = changeSong;
                }
            }
            else 
            {
                //Moving a node down the list (1 pt)
                if (myPos > newPos) 
                {//
                     if (newPos <= 1) 
                    {
                        prevChange->SetNext(changeSong->GetNext());
                        changeSong->SetNext(head);
                        head = changeSong;
                    }
                     //inserts song at position after prev
                    else
                    {
                        prevChange->SetNext(changeSong->GetNext());
                        prev->InsertAfter(changeSong);
                    }
                }
                //Moving a node up the list (1 pt)
                else 
                {//Insert new position after previous changeSong
                     prevChange->SetNext(changeSong->GetNext());
                    newSongPos->InsertAfter(changeSong);
                }
                
            }
             

            cout << '"' << changeSong->GetSongName() << '"' << " moved to position " << newPos << endl;
            cout << endl;
        }
// outputs the songs by a specific artist
        if (userInput == 's')
        {
            string mySongArtist;
            int count = 1;
            PlaylistNode *i = head;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cout << endl;

            cin.ignore();
            getline(cin, mySongArtist);
            //traverse to find songartist and prints their song information
            while (i)
            {

                if (mySongArtist == i->GetArtistName())
                {
                    cout << count << "." << endl;
                    i->PrintPlaylistNode();

                    cout << endl;
                }
                count++;
                i = i->GetNext();
            }
        }
        //outputs the total seconds in a playlist
        if (userInput == 't')
        {
            int count = 0;
            PlaylistNode *i = head;
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
           //traverses each song and adds up their seconds
            while (i)
            {
                count += i->GetSongLength();

                i = i->GetNext();
            }
            cout << "Total time: " << count << " seconds" << endl;
            cout << endl;
        }
        //outputs playlist information.
        if (userInput == 'o')
        {
            int count = 1;
            PlaylistNode *i = head;
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
           //playlist is empty
            if (!head)
            {
                cout << "Playlist is empty" << endl;
                cout << endl;
            }
            else
            {
                
                //traverses playlist and increases the count. prints information of each node.
                while (i)
                {

                    cout << count << "." << endl;
                    i->PrintPlaylistNode();
                    cout << endl;

                    i = i->GetNext();
                    count++;
                }
            }
        }

    }
}