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
    /*
    #if (LIST_TYPE == DOUBLY)
    Node* prev;
    #endif
    */
};

typedef struct List List;
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
        ++len;
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
        ++len;
    }

    void pop_back(void)
    {// delete node at the end
        if (isEmpty()) {
            return;
        }

        if (len == 1) {
            delete(head);
            head = NULL;
        }
        else{
            Node* n = head->next;
            while (n->next != NULL) {
                n = n->next;
            }
            delete(n->next);
            n->next = NULL;
            tail = n;      
        }
		--len;
    }

    void pop_front(void)
    {// delete node at beginning
        if (isEmpty()) {
            return;
        }
        Node* n = head->next;
        delete(head);
        head = n;
        --len;
        if (isEmpty()) {
            tail = NULL;
        }
		
    }

    void insert_at(int pos, int val)
    {
        if (pos > len + 1 || pos < 1) {
            cout << "\"out of range\"" << "\n";
            return;
        }

        if (pos == 1) {
            push_front(val);
        }
        else if (pos == len + 1) {
            push_back(val);
        }
        else {
            Node* n = head;
            pos--;
            while (--pos) {
                n = n->next;
            }

            Node* currentNode = new Node;
            currentNode->item = val;

            currentNode->next = n->next;
            n->next = currentNode;

            ++len;
        }
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
        for (int i = len; i != 0; --i)
        {
            cout << n->item << "\t";
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
    first.push_back(10);
    first.push_back(99);
    first.push_back(246);
    cout << "size first: " << first.length() << endl;
    first.print();

   
    first.remove_at(1);
    cout << "size first: " << first.length() << endl;
    first.print();

    first.pop_back();
    cout << "size first: " << first.length() << endl;
    first.print();
    
    first.pop_front();
    cout << "size first: " << first.length() << endl;
    first.print();

    first.push_front(10);
    cout << "size first: " << first.length() << endl;
    first.print();

    first.push_back(60);
    cout << "size first: " << first.length() << endl;
    first.print();


    first.insert_at(3, 20);
    cout << "size first: " << first.length() << endl;
    first.print();
    




    return 0;
}
