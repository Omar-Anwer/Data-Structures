#include <iostream>

#define SINGLY              (0)
#define DOUBLY              (1)
#define CIRCULAR            (2)
#define CIRCULAR_DOUBLY     (3)

#define LIST_TYPE SINGLY


using namespace std;

//template <typename item_type>

typedef struct Node Node;
struct Node
{
    int item;
    Node* next;
};

struct List
{
    Node* head = NULL;
    Node* tail = NULL;
    size_t len = 0;

    bool isEmpty(void) {
        return (len == 0); //  or head == NULL or tail == NULL
    }

    int length(void) {
        return len;
    }

    void push_back(int val)
    {
        //insert node at the end
        Node* n = new Node;
        n->item = val;

        n->next = NULL;

        if (isEmpty()) {
            head = n;
        }
        else {
            tail->next = n;
        }
        tail = n;
        tail->next = head;   // CIRCULAR    
        len++;
    }

    void push_front(int val)
    {
        //insert node at beginning
        Node* n = new Node;
        n->item = val;

        if (isEmpty()) {
            tail = n;
        }
        else {
            n->next = head;
        }

        head = n;
        tail->next = head;// CIRCULAR
        len++;
    }

    void insert_at(int pos, int val)
    {
        if (pos > len || pos < 1) {
            cout << "\"out of range\"" << "\n";
            return;
        }

        if (pos == 1) {
            push_front(val);
        }
        else if (pos == len) {
            push_back(val);
        }
        else {
            Node* n = head;
            while (--pos) {
                n = n->next;
            }

            Node* currentNode = new Node;
            currentNode->item = val;

            currentNode->next = n->next;
            n->next = currentNode;

            len++;
        }
    }

    void pop_back(void)
    {// delete node at the end
        if (isEmpty()) {
            return;
        }

        if (len == 1) //only 1 node
        {
            delete(head);
            head = NULL;
        }
        else
        {
            Node* n = head;
            while (n->next->next != head) {  // in SINGLY n->next->next != NULL
                n = n->next;
            }
            tail = n;
            delete(tail->next);
        }
        tail->next = head; // CIRCULAR
        len--;
    }

    void pop_front(void)
    {// delete node at beginning
        if (isEmpty()) {
            return;
        }

        Node* n = head->next;
        delete(head);
        head = n;

        tail->next = head; // CIRCULAR
        len--;
        
    }

    void remove(int val)
    {
        if (isEmpty()) {
            return;
        }

        if (head->item == val) {  //if the value exists in the first node
            pop_front();
            return;
        }

        Node* current = head;
        Node* previous = head;
        while (current != NULL) {
            if (current->item == val)
            {
                previous->next = current->next;
                free(current);
                len--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void remove_at(int pos)
    {
        if (pos > len || pos < 1) {
            cout << "\"out of range\"" << "\n";
            return;
        }

        if (pos == 1) {
            pop_front();
        }
        else if (pos == len) {
            pop_back();
        }
        else {
            Node* n = head;
            while (--pos)
            {
                n = n->next;
            }
            Node* temp = n->next;
            n->next = temp->next;
            delete(temp);
            len--;
        }
    }

    void print(void)
    {
        Node* n = head;
        for (int i = 2*len; i != 0; --i)
        {
            if (i == len) cout << "   |   ";
            cout << n->item << "  ";
            n = n->next;   
        }

        /*
        if (isEmpty()) {
            return;
        }
        Node* currentNode = head;
        while (currentNode != NULL) {
            cout << currentNode->item << "\t";
            currentNode = currentNode->next;
        }
        */
        cout << '\n';
    }
};


int main()
{
    List first, second, third;

    first.push_back(5);
    first.push_back(33);
    cout << "size first: " << first.length() << endl;
    first.print();

    first.push_front(69);
    cout << "size first: " << first.length() << endl;
    first.print();

    first.push_front(99);
    cout << "size first: " << first.length() << endl;
    first.print();
    
    first.pop_back();
    cout << "size first: " << first.length() << endl;
    first.print();

    first.pop_front();
    cout << "size first: " << first.length() << endl;
    first.print();
   /* 
    first.remove_at(1);
    cout << "size first: " << first.length() << endl;
    first.print();

    first.pop_front();
    cout << "size first: " << first.length() << endl;
    first.print();

    first.push_front(69);
    cout << "size first: " << first.length() << endl;
    first.print();

    first.push_back(60);
    cout << "size first: " << first.length() << endl;
    first.print();


    first.insert_at(1, 20);
    cout << "size first: " << first.length() << endl;
    first.print();
    */




    return 0;
}
