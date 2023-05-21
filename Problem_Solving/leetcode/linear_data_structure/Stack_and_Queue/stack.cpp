#include <iostream>

template <typename T>
class Node {
public:
    Node(T item, Node<T>* next) : item(item), next(next) {}
    ~Node() { 
        next = nullptr; 
        delete next;
    }

    Node<T>* next;
    T item;
};

template <typename T>
class Stack {
public:
    Stack() : last(nullptr) {}
    ~Stack() {
        delete last;
    }

    void push(T item)
    {
        last = new Node<T>(item, this->last);
    }

    T pop() 
    {
        item = this->last->item;
        last = this->last->next;
        return item;
    }

    Node<T>* last;
    T item;
};


int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    for (int i = 0; i < 5; i++)
    {
        std::cout << s.pop() << std::endl;
    }

    return 0;
}