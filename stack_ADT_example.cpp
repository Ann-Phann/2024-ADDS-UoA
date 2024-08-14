#include <iostream>
//first in last out

template <typename T >
class Stack {
public:
    //insert an element into the stack
    virtual void push(const T& element) = 0;

    //remove and return the top element from the stack
    virtual T pop() = 0;

    //return the top element without removing it
    virtual T top() const = 0;

    //check if the stack is empty
    virtual bool isEmpty() const = 0;

    //destructor for proper cleanup
    virtual ~Stack() {}
};

template <typename T>
class ArrayStack :public Stack<T> {
private:
    T* arr;
    int maxSize;
    int topIndex;

public: 
    ArrayStack(int size = 100) : maxSize(size), topIndex(-1) {
        arr = new T[maxSize];
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(const T& element) {
        if(topIndex >= maxSize - 1) {
            throw std::overflow_error("Stack overflow");
        }
        arr[++topIndex] = element;
        //The topIndex is incremented first, then the new value of topIndex is used to index into the array and store the element.
    }

    T pop() {
        if(this->isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[topIndex--]; //retrieve the element, then decreases topIndex by 1.
    //correct element is returned before moving the topIndex down to reflect the removal.
    }

    T top() const {
        if(this->isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }
};

int main() {
    ArrayStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << stack.top() << std::endl; //3

    std::cout << stack.pop() << std::endl; //3
    std::cout << stack.pop() << std::endl; //2
    std::cout << stack.pop() << std::endl; //1

    return 0;
}