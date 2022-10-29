#include <iostream>

using namespace std;

//template <typename Node_type>

struct Node
{
    int data;
    Node* next;   
};

struct Stack
{
    Node* top = NULL;
    int len = 0;

    bool isEmpty(void) {
        return (top == NULL);
    }
    
    int size(void) {
        return len;
    }
    
    void push(int val)
    {
        //insert node at beginning
        Node* current = new Node;

        if (current == NULL) {
            return;             // memory not allocated successfully
        }
        current->data = val;
        current->next = top;
        top = current;
        len++;   
    }
    
    int pop(void)
    {
        // delete node at beginning
        if (isEmpty()) {
            return -1;
        }
     
            Node* current = top;
            top = current->next;
            int temp = current->data;
            delete(current);
            len--;
            return temp;
    }
    
    int peek(void)
    {
        if (!isEmpty()) {
            return (top->data);
        }
    }

    void print(void)
    {
        if (isEmpty()) {
            return;
        }
        Node* current = top;
        while (current != NULL) {
            cout << current->data << "\n";
            current = current->next;
        }
        cout << '\n';
    }
};


int main()
{
    
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "stack size: " << s.size() << '\n';
    s.print();

    cout << s.pop() << '\n';
    cout << "stack size: " << s.size() << '\n';
    s.print();

    cout << s.pop() << '\n';
    cout << "stack size: " << s.size() << '\n';
    s.print();

    s.push(40);
    cout << "stack size: " << s.size() << '\n';
    s.print();




    return 0;
}
