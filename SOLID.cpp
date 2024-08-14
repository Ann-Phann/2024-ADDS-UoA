#include <iostream>
using namespace std;
class Bird {
public:
    virtual void fly() {cout << "Flying" << endl;}
};

class Penguin : public Bird {
public:
    void fly() override {cout << "Can't fly" << endl;}
};

void makeBirdFly(Bird& b) {
    b.fly();
}

int main() {
    Penguin p;
    makeBirdFly(p);
    return 0;
}
//violate the Liskov Substitution Principle

/*
Which of the following demonstrates proper information hiding in an ADT?
a) A class with public data members.
b) A class with private data members and public member functions.
c) A class with all member functions marked as const.
d) A class with inline member functions.

Answer: b) A class with private data members and public member functions.


Which of the following scenarios does not illustrate a violation of the Single Responsibility Principle?
a) A class that handles both file I/O and data parsing.
b) A class that manages database connections and performs encryption.
c) A class that only handles user authentication.
d) A class that sends email notifications and logs errors.

Answer: c) A class that only handles user authentication.
*/