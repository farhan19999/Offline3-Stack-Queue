#include "LinkedList.cpp"
template <typename T>
class Stack
{
private:
    LinkedList<T> l;
    int size;
public:
    Stack()
    {
        size = 0;
    }
    void push(T elem)
    {
        Node<T>* temp = new Node<T>(elem);
        l.insertFront(temp);
        ++size;
    }
    T top()
    {
        if(size == 0 )return 0;
        return l.getHead()->getValue();
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        T temp = top();
        l.removeFront();
        --size;
    }
    int getSize()
    {
        return this->size;
    }
    bool isEmpty()
    {
        return this->size == 0;
    }

};
