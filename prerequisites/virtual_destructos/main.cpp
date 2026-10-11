#include <QCoreApplication>
#include <iostream>
#include <vector>
using namespace std;

// add destructor to animal. and explain its not virtual.
// adding = default; because I want the compiler to generate it, not me.


// Create an animal class to create an inheritance:
class Animal{ // abstract data type
public:
    virtual void speak() = 0; // default
    // virtual ~Animal() { // this is not virtual
    //     cout << "Animal is destoyed \n";
    // }
    virtual ~Animal() = default;
};

// inherit:
class Dog : public Animal{
public:

    void speak() override{
        cout << "WOOF \n";
    }

    ~Dog(){
        delete breedType;
        cout << "Dog has been destroyed \n";
    }
private:
    string *breedType = new string("German");
};


int main(int argc, char *argv[])
{

    // we can have a zoo of animals:
    vector<Animal*> zoo;
    zoo.push_back(new Dog());
    zoo.push_back(new Dog());
    zoo.push_back(new Dog());

    delete zoo[0];
    delete zoo[1];
    delete zoo[2];

    // loop through all the sounds of the animals:
    // for(auto a: zoo){
    //     a->speak();
    // }


    return 0;
}















