#include <QCoreApplication>
#include <iostream>
using namespace std;

// Dont change these:
// const (for member functions, parameters,

// For preventing accidents:
// explicit.
// override
// final

// Compiler does these for you:
// defalut,
// delete
// virtual destructor...

class Player{
    int hp = 100;
public:
    int getHp() const { // use const on getters
        return hp ;
    }
    virtual void setHp(int h) {
        this->hp = h;
    }
};

// add final to the farm player
class FarmPlayer  : public Player{
    int hp = 100;
public:
    void setHp(int h) override final { // overriding
        this->hp = h;
    }
};

class FarmPlayerDivD : public FarmPlayer{
    int hp = 100;
public:
    // The below code will develop an error because of the above 'final' keyword
    // void setHp(int h) override { // overriding
    //     this->hp = h;
    // }
};

class NonCopyable {
public:
    NonCopyable(const NonCopyable&) = delete;   // no copying allowed
    NonCopyable& operator=(const NonCopyable&) = delete;
    NonCopyable() = default;
};


// preventing accidents:
// explicit: ensures no silent implicit conversions:
class Vec{
public:
    // explicit in front of the constructor
    Vec(int size){

    };
};

int main(int argc, char *argv[])
{

    Player p1;
    cout << p1.getHp() << endl;

    //
    Vec v(10);
    Vec v2 = 20; // there is something wrong with this..

    return 0;
}












