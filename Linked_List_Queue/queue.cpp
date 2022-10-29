// queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

struct Queue
{
    Node* front = NULL;   
    Node* rear = NULL;  
    int SIZE = 0;

    bool isEmpty(void) const
    {
        return (front == NULL);
    }
    
    int size(void) const
    {
        return SIZE;
    }
    
    void enqueue(const int val)
    {
        /* linked list insert at the end */
        Node* current = new Node;
        current->data = val;
        current->next = NULL;
        
        if (isEmpty())
        {         
            front  =  current;  // insert first node
        }
        else
        {
            rear->next = current; // insert any node
        }

        rear = current;
        SIZE++;
    }

    void dequeue(void)
    {
        /* linked list delete at the beginning func */
        if (isEmpty()){
            return;
        }
        Node* temp = front;         // Store previous front and move front one node ahead
        front = front->next;
        if (front == NULL) {
            rear = NULL;           // If there is a single node 
        }
        delete(temp);
        SIZE--;
    }

    int peek(void) const
    {
        if (!isEmpty()) {
            return (front->data);
        }
    }

    void print(void) const
    {
        if (isEmpty())
        {
            cout << "queue is empty \n";
            return;
        }
            Node* n = front;
            while (n != NULL){
                cout << n->data << " ";
                n = n->next;
            }
            cout << "\n";
        }

};

int main()
{
    Queue foodQ;


    foodQ.enqueue(100);
    foodQ.enqueue(20);
    foodQ.enqueue(30);
    foodQ.enqueue(10);
    foodQ.print();


    foodQ.dequeue();
    foodQ.dequeue();
    foodQ.print();


    foodQ.enqueue(40);
    foodQ.enqueue(60);
    foodQ.print();

    foodQ.dequeue();
    foodQ.dequeue();
    foodQ.dequeue();
    foodQ.print();

    foodQ.dequeue();
    foodQ.print();
    

    return 0;
}


