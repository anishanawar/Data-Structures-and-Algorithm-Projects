#include <iostream>
#include <string>
using namespace std;
#include "Playlist.h"

//default playlist constructor
Playlist::Playlist() : head(nullptr), tail(nullptr)
{
}

//default constructor
PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr)
{
}

//parameterized constructor
PlaylistNode::PlaylistNode(string uniID, string sngNm,  string artName, int sngLngth) : nextNodePtr(nullptr)
{
    uniqueID = uniID;
    songName = sngNm;
    artistName = artName;
    songLength = sngLngth;
 
}

//inserts currNode after
void PlaylistNode::InsertAfter(PlaylistNode *currNode)
{
    PlaylistNode *i = nullptr;
    i = this->nextNodePtr;
    this->nextNodePtr = currNode;
    currNode->nextNodePtr = i;
}

//sets next
void PlaylistNode::SetNext(PlaylistNode *currNode)
{
    nextNodePtr = currNode;
}

//returns the song id
string PlaylistNode::GetID()
{
    return uniqueID;
}

//returns song name
string PlaylistNode::GetSongName()
{
    return songName;
}

//returns artist name
string PlaylistNode::GetArtistName()
{
    return artistName;
}

//returns songlength
int PlaylistNode::GetSongLength()
{
    return songLength;
}

//returns the nextptr
PlaylistNode *PlaylistNode::GetNext()
{
    return nextNodePtr;
}

//outputs playlist information
void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}
