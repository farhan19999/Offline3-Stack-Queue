#include "Node.cpp"

template <typename T>
class LinkedList
{
private:
    Node<T>* head;

public:
    LinkedList()
    {
        head = NULL;
    }
    Node<T>* getHead()
    {
        return head;
    }
    void insertFront(Node<T>* elem)
    {
        if(isEmpty())
        {
            head = elem;
            return;
        }
        elem->setNext(head);
        head = elem;
    }
    void removeFront()
    {
        if(isEmpty())
        {
            return;
        }
        Node<T>* temp = head;
        head = temp->getNext();
        delete temp;
    }
    bool isEmpty()
    {
        return head == NULL;
    }

    ~LinkedList()
    {
        while(!isEmpty())
        {
            removeFront();
        }
    }
};
