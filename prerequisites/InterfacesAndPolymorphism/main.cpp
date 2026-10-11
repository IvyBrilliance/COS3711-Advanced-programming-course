#include <QCoreApplication>
#include <iostream>
using namespace std;

// When should another class contain another object insted of inheriting from it?
// and how do we then use different objects interchangeably?s

// Answer: Inherit when you ARE something, Compose when you HAVE something.

// Imagine you have a class car:
// A car HAS an engine,
// A dog IS an Animal,

// Car engine is composition:
class Engine{
public:
    void start(){
        cout << "Engine started... \n";
    }
};

class Car{
private:
    Engine engine;
public:
    void start(){
        engine.start();
    }
};

// Interfaces:
// this is the transition to polymorphism:

// Usually Interface classes look like this - no data members
// all pure virtual,
// derived classes implement the contract

class IShape{
public:
    virtual double area() const = 0;
    // virtual void draw() const = 0;
    virtual ~IShape() = default;
};

class Circle : public IShape{
private:
    double r;
public:
    Circle(double r) :r(r){}
    double area() const override {
        return 3.14 * r * r;
    }
};

int main(int argc, char *argv[])
{
    // use the class Circle here...
    vector<IShape*> shapes;
    shapes.push_back(new Circle(40));

    return 0;
}












