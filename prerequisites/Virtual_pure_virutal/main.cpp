#include <QCoreApplication>
#include <iostream>
#include <vector>
using namespace std;

// normal class without the virutal
// add virtual to show the dynamic linking
// add the override to show that - compiler wont allow typos
// pure virtual =0;  // what if the base class has no default? animal doenst have sound.



// Create an animal class to create an inheritance:
class Animal{ // abstract data type
public:
    virtual void speak() = 0; // default
};

// inherit:
class Dog : public Animal{
public:
    void speak() override{
        cout << "WOOF \n";
    }
};




int main(int argc, char *argv[])
{
    // are we getting Sound or Woof?
    Dog d;
    Animal* a = &d;
    a->speak();

    // because of static vs dynamic binding.
    // static binding- the compiler decides the call at compile time.
    // dynamic binding  - the compiler decides at runtime.


    // we can have a zoo of animals:
    vector<Animal*> zoo;
    zoo.push_back(new Dog());
    zoo.push_back(new Dog());
    zoo.push_back(new Dog());

    // loop through all the sounds of the animals:
    for(auto a: zoo){
        a->speak();
    }


    return 0;
}















