#include <QCoreApplication>
#include <iostream>
using namespace std;

// The problem: we have 2 systems however they have incompatible interfaces.
// The mess: wrapping everything.
// Solution: one adpapter- everthing works.

// imagine we have a class- standard interface that everything else expects:
class MediaPlayer{
public:
    virtual void play(string filename) = 0;
    virtual ~MediaPlayer() = default;
};


// Here we have legacy software:
class VLCPlayer{
public:
    void playVLC(string file){
        cout << "VLC playing : " << file << "\n";
    }
};

// Adapter class:
class VLCAdapter : public MediaPlayer{
    VLCPlayer vlc;

public:
    void play(string filename) override{
        vlc.playVLC(filename);
    }
};


int main(int argc, char *argv[])
{
    VLCAdapter adapter;
    adapter.play("Gospel");

    return 0;
}













