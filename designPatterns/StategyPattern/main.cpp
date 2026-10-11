#include <QCoreApplication>
#include <iostream>
using namespace std;

/*
    Strategy pattern is about separating what changes from what stays the same.
    We split the if/else statments because we don't want them to become too big to be manageable.

*/

// Define our interface class:
class IPaymentStrategy{
public:
    virtual void pay(double amount) const = 0;
    virtual ~IPaymentStrategy() = default;
};

// strategies
class CardPayment : public IPaymentStrategy{
public:
    void pay(double amount) const override{
        cout << "Paying $ " << amount << " with a card \n";
    }
};
class PaypalPayment : public IPaymentStrategy{
public:
    void pay(double amount) const override{
        cout << "Paying $ " << amount << " with a a paypal \n";
    }
};
// all of these are easy to test and are isoloated.

// Context:
class Checkout{
    IPaymentStrategy * strategy; // checkout has a stategy...
public:
    Checkout(IPaymentStrategy * s){
        strategy = s;
    }
    void setStrategy(IPaymentStrategy *s){
        strategy = s;
    }
    void pay(double amount){
        strategy->pay(amount);
    }
};



int main(int argc, char *argv[])
{
    // Instantiate:

    CardPayment AbsaCard;

    Checkout checkout(&AbsaCard);
    checkout.pay(500);

    // change the strategy:
    // leaving it up to the reader...


    return 0;
}



