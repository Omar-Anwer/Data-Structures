#include <iostream>


using namespace std;

struct Node
{
    int item;
    Node* next;
    Node* prev; 
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
            head = n;            // if its the first node in list
            n->prev = NULL;
        }
        else {
            n->prev = tail;        // if its not the first node in list
            tail->next = n;
        }
        tail = n;
        len++;
    }

    void push_front(int val)
    {
        //insert node at beginning
        Node* n = new Node;
        n->item = val;
        n->prev = NULL;

        if (isEmpty()) {
            tail = n;
            n->next = NULL; 
        }
        else {
            n->next = head;
            head->prev = n;
        }
        head = n;
        len++;
    }

    /*TODO fix bugs in insert_at fn*/
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
            bool start = (2 * pos <= len);
            Node* n = start ? head : tail;
            Node* dir = start ? n->next : n->prev;
            while (--pos) {
                n = dir;
            }

            Node* currentNode = new Node;
            currentNode->item = val;

            currentNode->next = n->next;
            currentNode->prev = n;

            n->next = currentNode;
            (n->next)->prev = currentNode;

            len++;
        }
    }

    void pop_back(void)
    {// delete node at the end
        if (isEmpty()) {
            return;
        }

        tail = tail->prev;
        delete(tail->next);
        tail->next = NULL;
        len--;
        if (isEmpty()) {
            head = NULL;
        }
    }

    void pop_front(void)
    {// delete node at beginning
        if (isEmpty()) {
            return;
        }

        head = head->next;
        delete(head->prev);
        head->prev = NULL;
        len--;
        if (isEmpty()) {
            tail = NULL;
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

        if (tail->item == val) {  //if the value exists in the last node
            pop_back();
            return;
        }

        Node* l = head;
        Node* r = tail;
        while (l != NULL && r != NULL)    // searching  O(n/2)
        {
            if (l->item == val || r->item == val)
            {
                l = (l->item == val) ? l : r;
                (l->prev)->next = l->next;
                (l->next)->prev = l->prev;
                delete(l);
                len--;
                return;
            }
            l = l->next;
            r = r->prev;
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
            bool start = (2 * pos <= len);
            Node* n = start ? head : tail;
            Node* dir = start ? n->next : n->prev;

            while (--pos) {
                n = dir;
            }

            (n->prev)->next = n->next;
            (n->next)->prev = n->prev;
            delete(n);
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
    first.push_back(69);
    first.push_back(100);
    cout << "size first: " << first.length() << endl;
    first.print();

   
    first.push_front(246);
    cout << "size first: " << first.length() << endl;
    first.print();



    first.pop_back();
    cout << "size first: " << first.length() << endl;
    first.print();

    first.pop_front();
    cout << "size first: " << first.length() << endl;
    first.print();

    
    first.insert_at(3, 5000);
    cout << "size first: " << first.length() << endl;
    first.print(); 

    first.remove_at(1);
    cout << "size first: " << first.length() << endl;
    first.print();
    
    first.remove(100);
    cout << "size first: " << first.length() << endl;
    first.print();

    /*
    */




    return 0;
}
