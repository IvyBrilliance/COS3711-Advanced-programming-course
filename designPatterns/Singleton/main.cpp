#include <QCoreApplication>
#include <iostream>
using namespace std;

/* A singleton pattern guarantees that a class has only one instance
 * and then it creates a way for the entire program to reach it.
 *
 */

// Imagine you're building a game:
// You want volume, language, fullscreen(boolean) to be controlled from one place.
// Controlled by a single class.

class GameConfig2{
private:
    int volume;
    string language;
    bool fullscreen;
public:
    GameConfig2(){
        volume = 50;
        language = "EN";
        fullscreen = false;
    }
};


// The solution: Singleton pattern:
// private constructor - nobody else can 'new' it
// static instances - they are held within the class
// public static method called getInstance() - which will be the only way to create an instance.

class GameConfig{
private:
    int volume = 50;
    string language = "EN";
    bool fullscreen = false;

    GameConfig(){} // constructor is private

    // prevent all forms of copying and moving:
    GameConfig(const GameConfig&) = delete;
    GameConfig& operator=(const GameConfig&) = delete;

public:
    static GameConfig& getInstance(){
        static GameConfig instance;
        return instance;
    }

    int getVolume() const {
        return volume;
    }
    void setVolume(int v){
        volume = v;
    }



};

int main(int argc, char *argv[])
{

    GameConfig::getInstance().setVolume(99);
    cout << GameConfig::getInstance().getVolume() << endl;


    // bypassing singleton if defaults arent set
    //GameConfig a = GameConfig::getInstance();
    //GameConfig b = GameConfig::getInstance();
    //GameConfig x(b);

    // bypass: copy constuctor:
    //GameConfig c = a;

    return 0;
}














