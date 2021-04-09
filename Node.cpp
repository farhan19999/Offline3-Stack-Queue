#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node
{
private:
    Node<T>* next;
    T value;
public:
    Node(T value)
    {
        this->value = value;
        next = NULL;
    }
    Node<T>* getNext()
    {
        return next;
    }
    void setNext(Node<T>* next)
    {
        this->next = next;
    }

    T getValue()
    {
        return value;
    }
};
