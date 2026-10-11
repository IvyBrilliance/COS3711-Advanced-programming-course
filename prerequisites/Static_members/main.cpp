#include <QCoreApplication>
#include <iostream>
using namespace std;

// What is static? and why do we use it?
// We use it whenever we want multiple objects to share the same variable.

// say we wanted to store how many players exist in the game:

// static function...

class Player{
public:
    static int playerCount;
    int hp; // every player has thier own hp

    Player(){
        playerCount++;
    }

    // static member function:
    static int getCount(){
        return playerCount;
    }
};
// define outside of the class:
int Player::playerCount = 0;

int main(int argc, char *argv[])
{
    Player p1;
    Player p2;
    Player p3;

    // 2 ways of accessing:
    cout << Player::getCount() << '\n';
    // cout << p1.playerCount << '\n';

    return 0;
}

// Use cases:
// constants used across all objects - static double PI = 3.14;
// a shared logger
// counting instances of a class.
