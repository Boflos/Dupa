#include <iostream>

class Stack;

class Node
{
public: // tu wpierdalam public bo inaczej sra się, że private jak przez wskaźnik. Przez ref normalnie śmiga.
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
    friend std::ostream& operator<<(std::ostream& stream, const Stack& sta);
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

        Node * oldHead = head;
        head = head -> next;
        delete oldHead;

    }

    void show()
    {
        Node * temp = head;
        while(temp)
        {
            std::cout << temp -> data << std::endl;
            temp = temp -> next;
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const Stack* sta)
    // w takiej postaci się sra i mogętylko jak dam public do pól noda
    //  friend std::ostream& operator<<(std::ostream& stream, const Stack& sta) - w takiej mogą być private
    // oczywiście zmieniam na sta.head i wywołanie std::cout << *stack
{
    Node *temp= sta->head;
    stream << "Stack data: \n";
    while(temp)
    {
        stream<<temp->data<<std::endl;
        temp=temp->next;
    }
    return stream;
}

};



int main()
{
    Stack * stack = new Stack();

    stack -> push();
    stack -> push(1);
    stack -> push(2);
    stack -> push(3);
    //stack -> show();
    std::cout << stack;
    stack -> pop();
    //stack -> show();
}
