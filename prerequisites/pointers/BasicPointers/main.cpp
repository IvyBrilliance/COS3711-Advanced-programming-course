#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Declaring basic pointers:
    int x = 25;
    int *p; // creates a pointer
    p = &x;

    cout << p << endl;
    cout << *p << endl; // derefernce the pointer
    cout << "Hello world"<< endl;

    // other ways of string pointers:
    int *q ;
    int y = 200;
    q = &y;
    cout << *q << '\n';
    cout << *(&y) << '\n';



    return 0;
}
