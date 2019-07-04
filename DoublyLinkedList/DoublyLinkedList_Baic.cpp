#include <iostream>

using namespace std;

class DoublyListNumber{

protected:
    struct Node {
        int value;
        struct Node* next;
        struct Node* prev;

        Node (int value) {
            this->value = value;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node*head;
public:
    DoublyListNumber() {
        this->head = NULL;
    }


    void insert(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            return;
        }

        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void print(){
        Node* p = head;
        Node* p2 = head;

        if (p == NULL) return;

        cout << "Print: ";// 8 7 6 5 4 3 2 1 0
        while(p2 != NULL) {
            cout << p2->value << " ";
            p2 = p2->next;
        }
        cout << '\n';

        while(p->next != NULL) {
            p = p->next;
        }

        cout << "Reverse: "; // 0 1 2 3 4 5 6 7 8
        while(p != NULL) {
            cout << p->value << " ";
            p = p->prev;
        }
        cout << '\n';
    }

    Node* search(int key) { // Time complexity: O(n)
       Node* x = this->head;
       while (x != NULL && x->value != key) {
           x = x->next;
       }
       return x;
   }

   void remove(int key) { // Time complexity: O(1)
      Node* x = search(key);
      if (x->prev != NULL) {
          x->prev->next = x->next;
      }
      else {
          // Special case: deleting head
          this->head = x->next;
      }
      if (x->next != NULL) {
          x->next->prev = x->prev;
      }
      delete x;
      x = NULL;
  }

};

int main() {

    DoublyListNumber a;

    for(int i = 0; i < 9; i++) {
        a.insert(i);
    }

    a.print();
    a.remove(5);
    a.print();

    return 0;
}
