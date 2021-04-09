#include "CircularLinkedList.cpp"

template < typename T>
class Queue
{
private:
    CircularLL<T> cll;
    int size;

public:
    Queue()
    {
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(T elem)
    {
        Node<T>* new_Elem = new Node<T>(elem);
        cll.add(new_Elem);
        ++size;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return ;
        }
        cll.removeFront();
        --size;
    }

    T front()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return cll.getHead()->getValue();
    }

    int getSize()
    {
        return this->size;
    }

};
