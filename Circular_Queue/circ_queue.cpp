

#include <iostream>
using namespace std;


struct Queue
{
    int front = -1;
    int rear = -1;

    int MAX_SIZE = 0;
    int SIZE = 0;

    int* queue = NULL;

    void createQueue(int size)
    {
        queue = new int[size];
        MAX_SIZE = size;
    }

    void deleteQueue(void)
    {
        free(queue);
        queue = NULL;
        int front = -1;
        int rear = -1;

        int MAX_SIZE = 0;
        int SIZE = 0;

    }

    bool isEmpty(void) const
    {
        return (!SIZE);
        //return ( (front == -1));     //circular queue condition
    }

    bool isFull(void) const
    {   
        return (SIZE == MAX_SIZE);
        /*
        if ( (front == 0) && (rear == MAX_SIZE - 1) ) { // simple queue condition
            return true;
        }
        return (front == rear + 1);                   // circular queue condition
        */
    }

    int size(void)
    {
        return SIZE;
    }

    void enqueue(const int val)
    {

        if (!isFull()) {
            
            if (isEmpty()) {
                front = 0;
            }
            rear++;                    // rear = (rear+1)%MAX_SIZE;
            if (rear == MAX_SIZE) {  
                rear = 0;
            }

            queue[rear] = val;
            SIZE++;
        }
    }

    int dequeue(void)
    {
        if (!isEmpty()) {
            int temp = queue[front];

            if (front == rear) {       //reset indexes if it's the last element
                front = -1;
                rear = -1;
            }
            else 
            {
                 front++;                 // any other case
                 if (front == MAX_SIZE) {
                    front = 0;
                 }
            }  
            SIZE--;
            return temp;
        }

    }

    int peek(void)
    {
        if (!isEmpty()) {
            return queue[front];
        }
        return -1;

    }

    void print(void)
    {
        if (!isEmpty()) 
        {
            int i;
            for (i = front; i!= rear; i = (i + 1) % MAX_SIZE)
            {
                cout << queue[i] << "\t";
            }

            cout << queue[i] << "\n";
        }
    }
};

int main()
{
    Queue foodQ;
    foodQ.createQueue(3);

    foodQ.enqueue(10);
    foodQ.enqueue(5);
    foodQ.enqueue(15);

    foodQ.print();

    foodQ.dequeue();

    foodQ.print();


    return 0;
}


