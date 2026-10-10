#include <QCoreApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Declare a dynamic varible:
    int *num = new int(4);
    cout << *num << endl;

    // Declare a dynamic string:
    std::string *str = new std::string("Hello world");
    cout << (*str).length() << "\n";

    // Member access operator arrow ->
    int lengthOfMyString = str->length();
    cout << "The length of the string is : " << lengthOfMyString << endl;

    // Different ways of initialzing pointer variables:
    int *p1 = NULL;
    int *p2 = 0;

    // Different ways of declaring dynamic memory:
    int *p3 = new int;
    int *p4 = new int [2] ;

    // Delete these pointers:
    delete p3;
    delete [] p4;

    // Dealing with dangling pointers:
    p3 = NULL;






    return 0;
}
