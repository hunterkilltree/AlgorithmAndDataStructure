#include <iostream>


using namespace std;

//ok
//list1.push_back(x) : insert the element x at the end of the list
//list1.size : show the size of the list
//list1.empty()
//list1.delete_at(pos): delete at poistion


//not yet
//back() : return a reference to last element in the list
//font() : retrun a reference to the first element in the list
//insert(pos, val) : insert at position with a specific value
//list1.merge(list2) : list 1 and list 2 already sorted => then merge to a sorted list1
//list1.pop_back() : remove the last element, return value
//list1.pop_front(): remove the first element, return value
//list1.push_front(x): add inserts an element with value x at the beginning
//list1.reverse(): reverse the order
//list1.swap(list2): swap 2 list . note: they can have different size.
//list1.unique(): remove any the element that has the same value as the element before it.



class Numberlist {

protected:
    // Create a Node with its own value and address
    struct Node{
        int value;
        Node* next;

        // Initial Node
        // when we create new node => this node  have value
        // then immediately point to NUll
        Node (int value) {
            this->value = value;
            this->next = NULL;
        }
    };

    int count; // optional
    // store the address of the start
    Node* head;

public:
    // Initial Object
    Numberlist() {
        this->head = NULL;
        this->count = 0;
    }

    // Release memory
    ~Numberlist() {

        //take the pos of
        //first node
        Node* p = this->head;

        // loop if p not at the end of the list
        while(p) {

            // create pointer has address of node
            Node* garbage = p;

            //point to the address of the next node
            p = p->next;

            // when delete this point
            // also delete the previous node
            delete garbage;
        }
        this->count = 0;
    }

    bool is_empty() {
        return !(this->head); // 1: yes ; 0 : no
    }

    void push_back(int value) {
        if (this->head == NULL) {
            this->head = new Node(value);
        }
        else {
            Node *p = this->head;

            //xem lai
            while(p->next) {
                p = p->next;
            }
            // when p reach the final Node
            // create new Node
            // piont the final address to the new one
            p->next = new Node(value);
        }
        count++;
    }

    bool range_check(int pos) {
        return (pos < 0 || pos >= this->size());
    }

    int size() {
        return this->count;
    }

    void print() const{
        Node* p = head;

        while(p) {
            cout << p->value << " ";
            p = p -> next;
        }

        cout << '\n';
    }

    void print_detail() const{
        Node* p = head;
        cout << "head" << head << "---->>>>";
        while(p) {
            cout << p->value << "|" << p << "---->" << "|";
            p = p -> next;
        }
        cout << "NULL" << "|" << endl;
    }

    ///test quiz

    //get reference of node at position
    Node* getNode(int pos) {
        if (pos < 0  || pos > this->size())
        throw "Out of Bound\n";
        Node *p = head;
        int i = 0;
        while(p) {
            if (i == pos) {
                return p;
            }

            p = p->next;
            i++;
        }
        return NULL;
    }

    bool isCircular() {
        if (this->is_empty())
        return 0;

        Node* tail = head->next;

        while(tail) {
            if (tail == head)
            return true;
            tail = tail->next;
        }
    }

    void addAtHead(int val) {
        if( head == NULL) {
            head =  new Node(val);
            count++;
        }
        else {
            Node *node = new Node(val);
            node->next = head;
            head = node;
            count++;
        }
    }

    int get(int index) {
        if (index < 0 || index >= this->count)
        return -1;

        Node *p = head;
        int i = 0;
        while(p) {
            if (i == index)
            return p->value;
            p = p->next;
            i++;
        }
        return -1;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > count)
            return;
        Node *node = new Node(val);
        Node *p = head;
        if (index == count) {
            addAtTail(val);
            return;
        }
        if (index == 0) {
            head = node;
            return;
        }

        Node *pPre = NULL;
        int i = 0;

        while(p) {
            if (index == i) {
                node->next = p;
                pPre->next = node;
                return;
            }
            i++;
            pPre = p;
            p = p->next;
        }

    }

    void delete_at(int index) {
        if (range_check(index)) {
            cout << "Out of range\n";
            return;
        }

        Node *p = head;
        Node *pPre = NULL;
        if (index == 0) {
            head = head->next;
            count--;
            delete p;
        }
        else {
            int i = 0;
            while(p != NULL && index != i) {
                pPre = p;
                p = p->next;
                i++;
            }
            if (p != NULL) {
                pPre->next = p->next;
                count--;
                delete p;
            }
        }
    }

    void addAtTail(int val) {
        if(head == NULL) {
            head = new Node(val);
            count++;
        }
        else {
            Node *p = this->head;
            while(p->next) {
                p = p->next;
            }


            p->next = new Node(val);
            count++;
        }
    }

};

int main() {

    Numberlist a;

    for (int i = 0; i < 10; i++) {
        a.push_back(i);
    }
    cout << "The size: " << a.size() <<  endl;
    cout << "List: "; a.print();
    cout << "Delete at index 0: ";
    a.delete_at(0);
    a.print();



    return 0;
}
