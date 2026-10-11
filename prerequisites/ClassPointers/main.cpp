#include <QCoreApplication>
#include <iostream>
#include <string>
using namespace std;

/*
    This is about class pointers- The basics
    This is not about virtual and pure virtual functions.
*/

// Class: linking:
class Player {
public:
    string name;
    Player * teammate = nullptr;
};

// Class with dynmaic owenership: new/delete:
// here, the class owns the memory, when the object dies, the destructor frees the memory:
class Inventory {
public:
    int * items;
    int size;

    // constructor:
    Inventory(int s){
        size = s;
        items = new int[size];
    }

    int getSize(){
        return this->size; // pointer that the compiler hands to us.
    }

    ~Inventory(){
        delete [] items;
    }
};

int main(int argc, char *argv[])
{

    Inventory I(3); // creted on the stack
    // no need to delete it, it will be done for us.

    // i.items[0] == 0x324398472934
    // i.items[1] == 0x324398472934

    Inventory *I2 = new Inventory(3); // created on the heap:
    delete I2; // deletes it to free memory


    // Player a;
    // a.name = "Daniel";

    // Player b;
    // b.name = "Frank";

    // a.teammate = &b;

    // cout << "Daniels teammate is :" << a.teammate->name << '\n';

    // return 0;
}
