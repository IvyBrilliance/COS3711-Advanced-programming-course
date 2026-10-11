#include <QCoreApplication>
#include <iostream>
using namespace std;

/*
    Strategy pattern is about separating what changes from what stays the same.
    We split the if/else statments because we don't want them to become too big to be manageable.

*/

class Payment {
public:
    void pay(string type, double amount) {
        if (type == "card") {
            cout << "Paying $" << amount << " with card\n";
        } else if (type == "paypal") {
            cout << "Paying $" << amount << " with PayPal\n";

            // adding a feature:
            // checking the currency:
            if(currency = "usd"){
                //
            }else if(currency = "yen"){
                //
            }
        } else if (type == "crypto") {
            cout << "Paying $" << amount << " with crypto\n";
        } else {
            cout << "Unknown payment\n";
        }
    }
};


int main(int argc, char *argv[])
{
    // Instantiate:
    Payment p;
    p.pay("Payypal", 344); // users cant pay because you made a typo...

    return 0;
}

// another pain point is : LACK OF DIRECT TESTING - cant test out just the 'Crypto'...

// another pain point: Payment logic is not just one line: YOu have to add : validation, api calls, retries, logging, error handling... etc.




