

#include <iostream>
using namespace std;


struct Queue
{
    int front = -1;
    int rear = -1;

    int MAX_SIZE = 0;

    int* arr = NULL;
    
    void createQueue(int size)
    {
        arr = new int[size];
        MAX_SIZE = size;
    }

    void deleteQueue(void)
    {
        free(arr);
        arr = NULL;
    }

    bool isEmpty(void)
    {
        return ((front == -1) || (front > rear));  //real empty or 
        
    }

    bool isFull(void)
    {
        return (rear == MAX_SIZE - 1);
    }
    
    void enqueue(int val)
    {
        
        if(!isFull()){
            if (isEmpty()){
                front++;
            }
            rear++;
            arr[rear] = val;
        }        
    }

    int dequeue(void)
    {
        if (!isEmpty()) {
            int temp = arr[front];
            front++;
            return temp;
        }
        
    }

    int peek(void)
    {
        if (!isEmpty()) {
            return arr[front];
        }
        return -1;
        
    }

    void print(void)
    {
        if (!isEmpty()) {
            for (int i = front; i <= rear; ++i)
            {
                cout << arr[i] << "\t";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Queue foodQ;
    foodQ.createQueue(5);

    foodQ.enqueue(10);
    foodQ.enqueue(5);
    foodQ.enqueue(15);

    foodQ.print();

    foodQ.dequeue();

    foodQ.print();


    return 0;
}


