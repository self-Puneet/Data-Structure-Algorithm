#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next_node;
        // it is a pointer of type Node
        Node (int value) {
            data = value;
            next_node = NULL;
        }
};

class LinkedList {
    private:
        Node *head;
    
    public: 

        void Menu () {
            cout << "1  Insert at Rear" << endl;
            cout << "2  Insert at Front" << endl;
        }

        LinkedList() {
            head = NULL; 
        }

        int count() {
            int count = 0;
            Node *temp = head;
            count = count + 1;
            while (temp->next_node != NULL){
                temp = temp->next_node;
                count = count + 1;
            }
            return count;
        }

        int rear() {
            int value = 0;
            Node *temp = head;
            do{
                temp = temp->next_node;
                value = temp->data;
            } while (temp -> next_node != NULL);
            return value;
        }

        int front() {
            return head->data;
        }

        void InsertRear(int d) {
            if (head == NULL) {    
                head = new Node(d);
                cout << "head node with value " << d << " is made" << endl;
            }
            else {
                Node *temp = head;
                while (temp->next_node != NULL) {
                    temp = temp->next_node;
                }
                temp->next_node = new Node(d);
                cout << "node with value " << d << " is made" << endl;
            }
        }

        void InsertFront(int d) {
            Node *front_node = new Node(1);
            front_node->next_node = head;
            head = front_node;
        }

        // void InsertIndex(Node *, int value) {

        // }

        void InserBefore(int value, int key) {
            Node *temp = head;
            if (temp == NULL) {
                cout << "Linked List is empty";
            }
            else {            
                while (temp->next_node != NULL) {
                    if (temp->data == key) {
                        temp = new Node(value);
                        break;
                    }
                    temp = temp->next_node;
                }
            } 
        }
        
};

int main() {
    LinkedList obj1;
    obj1.InsertRear(23);
    obj1.InsertRear(24);
    obj1.InsertRear(25);
    obj1.InsertFront(1);
    cout << "Total number of nodes : " << obj1.count() << endl;
    cout << "Value of Last Element : " << obj1.rear() << endl;
    cout << "Value of Front Element : " << obj1.front() << endl;

    return 0;
}