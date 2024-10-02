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

        void display_linked_list() {
            Node *temp = head;
            do {
                if (temp->next_node != NULL) {
                    cout << temp->data << " -> ";
                }
                else {
                    cout << temp->data << endl;
                }
                temp = temp->next_node;
            } while (temp != NULL);
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


        // Insertion
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

        void InsertAfter(int value, int key) {
            Node *temp = head;
            bool flag = false;
            if (temp == NULL) {
                cout << "Linked List is empty";
            }
            else {
                do {
                    if (temp->data == key) {
                        Node *new_node = new Node(value);
                        new_node->next_node = temp->next_node;
                        temp->next_node = new_node;
                        return;
                    }
                    temp = temp->next_node;
                } while (temp->next_node != NULL);
                cout << value << " is not a valid value in linked list." << endl;
            }
        }

        void InsertBefore(int value, int key) {
            Node *temp = head;
            int var = temp->next_node->data;
            
            bool flag = false;
            if (temp == NULL) {
                cout << "Linked List is empty";
            }
            else {
                               
                do {
                    if (var == key) {
                        Node *new_node = new Node (value);
                        new_node->next_node = temp->next_node;
                        temp->next_node = new_node;
                        return;
                    } 
                    temp = temp->next_node;
                    var = temp->next_node->data;
                } while (temp->next_node != NULL);
                cout << value << " is not a valid value in linked list." << endl;
            }
        }    

        void InsertAt(int value, int key) {
            Node *temp = head;
            do{
                if (temp->data == key) {
                    temp->data = value;
                    return;
                }
                temp = temp->next_node;
            } while (temp->next_node == NULL);
            cout << value << " is not a valid value in linked list." << endl;
        }

        // Deletion
        void DeleteRear() {
            if (head == NULL) {
                cout << "This operation is not supported with a empty linked list" << endl;
            }
            else {
                Node *temp = head;
                if (temp->next_node == NULL){
                    head = NULL;
                }
                else {
                    while (temp->next_node->next_node != NULL){
                        temp = temp->next_node;
                    }
                    temp->next_node = NULL;
                }
            }
        }

        void DeleteFront() {
            Node *temp = head;
            head = temp->next_node;
        }

        void DeleteAfter(int key) {}
        void DeleteBefore(int key) {}
        void DeleteAt(int key) {}

};

int main() {
    LinkedList obj1;
    obj1.InsertRear(23);
    obj1.InsertRear(24);
    obj1.InsertRear(25);
    obj1.InsertRear(27);    
    obj1.InsertAfter(26, 25);
    obj1.InsertBefore(26, 25);    
    cout << "Total number of nodes : " << obj1.count() << endl;
    cout << "Value of Last Element : " << obj1.rear() << endl;
    cout << "Value of Front Element : " << obj1.front() << endl;
    obj1.display_linked_list();
    obj1.DeleteRear();
    obj1.display_linked_list();
    return 0;
}