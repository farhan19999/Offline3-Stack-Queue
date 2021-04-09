#include "Node.cpp"

template <typename T>
class CircularLL
{
private:
    Node<T>* cur;
public :
    CircularLL()
    {
        cur = NULL;
    }

    bool isEmpty()
    {
        return cur == NULL;
    }

    Node<T>* getHead()
    {
        return cur->getNext();
    }

    Node<T>* getTail()
    {
        return cur;
    }

    void add(Node<T>* elem)
    {
        if(isEmpty())
        {
            elem->setNext(elem);
            cur = elem;
            return;
        }
        elem->setNext(cur->getNext());
        cur->setNext(elem);
        cur = elem;
    }

    void removeFront()
    {
        if(isEmpty())return;
        if(cur->getNext() == cur)
        {
            cur = NULL;
            return;
        }
        Node<T>* old = cur->getNext();
        cur->setNext(old->getNext());
        delete old;
    }

    ~CircularLL()
    {
        while(!isEmpty())
        {
            removeFront();
        }
    }
};
