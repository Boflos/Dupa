#include <iostream>

class Node
{

    int data;
    Node * next;
public:
    Node(int i = 0)
    {
        next = NULL;
        data = i;
    }

    const int getValue()
    {
        return data;
    }
friend class Stack;
};

class Stack
{

    Node* head;

public:

    Stack()
    {
        head = NULL;
    }

    void push(int i = 0)
    {
        Node * n = new Node(i);
        if(!n) return;
        n -> next = head;
        head = n;
    }

    void pop()
    {

        std::cout << "dupa1";
        Node * temp;
        temp = head -> next;
        std::cout << "dupa2";
        delete head;
        head = temp;
        /*
        Node * oldHead = head;
        //head = head -> next;
        //delete oldHead;
        */

    }

    void show()
    {
        while(head)
        {
            std::cout << head -> data << std::endl; 
            head = head -> next;                   // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }
    }
};



int main()
{
    Stack * stack = new Stack();

    stack -> push();
    stack -> push(1);
    stack -> push(2);
    stack -> push(3);
    stack -> show();
    stack -> pop();
}
