#include <QCoreApplication>
#include <iostream>
using namespace std;

// Easiest.
// Facade pattern gives a simple intefrac to a complex subsystem.

// Imagine we have 4 subsystems:

class Amplifier {
public:
    void on(){
        cout << "amp is on \n";
    }
    void setVolume(int v){
        cout << "amp volume i s: =" << v << "\n";
    }
    void off(){
        cout << "amp is off \n";
    }
};


class CDPlayer {
public:
    void on()   { cout << "CD Player ON\n"; }
    void play() { cout << "Playing CD\n"; }
    void stop() { cout << "CD stopped\n"; }
    void off()  { cout << "CD Player OFF\n"; }
};

class Projector {
public:
    void on()               { cout << "Projector ON\n"; }
    void setInput(string i) { cout << "Projector input = " << i << "\n"; }
    void off()              { cout << "Projector OFF\n"; }
};

class Lights {
public:
    void dim() { cout << "Lights dimmed\n"; }
    void on()  { cout << "Lights ON\n"; }
};


// create a facade class:
class HomeTheaterFacade{
    Amplifier& amp;
    CDPlayer& cd;
    Projector& projector;
    Lights& lights;
public:
    HomeTheaterFacade(  Amplifier& a,
                      CDPlayer& c,
                      Projector& p,
                      Lights& l) : amp(a), cd(c), projector(p), lights(l) {};
    void watchMovie(){
        lights.dim();
        amp.on();
        amp.setVolume(7);
        projector.on();
        projector.setInput("HDMI");
        cd.on();
        cd.play();
    }
    void endMovie() {
        cd.stop();
        cd.off();
        projector.off();
        amp.off();
        lights.on();
    }

    void playMusic() {
        lights.dim();
        amp.on();
        amp.setVolume(5);
        cd.on();
        cd.play();
    }
};

int main(int argc, char *argv[])
{

    // Imagine we want to watch a movie:

    Amplifier amp;
    CDPlayer cd;
    Projector projector;
    Lights lights;

    HomeTheaterFacade home(amp, cd, projector, lights);
    home.watchMovie();
    home.endMovie();
    home.playMusic();




    return 0;
}


















