#include <iostream>
class A {
    int x;
public:
    A(int x) : x(x) {}
    int getX() const { return x; }
    void setX(int x) { this->x = x; }
};

// int main() {
//     const A a(5); // const object of class A, only const member functions can be called
//     std::cout << a.getX();
//     //a.setX(10);
//     return 0;
// }
//The code will not compile because setX is not marked as const.

class Database {
public:
    static Database* getInstance() {
        if (!instance) {
            instance = new Database();
        }
        return instance;
    }
    void connect() { /* Connect to database */ }
private:
    Database() {}
    static Database* instance;
};

Database* Database::instance = nullptr;

int main() {
    Database* db1 = Database::getInstance();
    Database* db2 = Database::getInstance();
    return db1 == db2;
}