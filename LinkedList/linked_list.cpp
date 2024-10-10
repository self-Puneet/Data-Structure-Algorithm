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
        Node (int value, Node *head) {
            data = value;
            next_node = head;
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

        virtual void display_linked_list() {
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
        virtual void InsertRear(int d) {
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

        virtual void InsertFront(int d) {
            Node *front_node = new Node(d);
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
            while (temp->next_node != NULL) {
                if (temp->data == key) {
                    temp->data = value;
                    return;
                }
                temp = temp->next_node;
            }
            cout << value << " is not a valid value in linked list." << endl;
        }

        // Deletion
        virtual void DeleteRear() {
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

        virtual void DeleteFront() {
            Node *temp = head;
            head = temp->next_node;
        }

        void DeleteAfter(int key) {
            if (head == NULL) {
                cout << "This operation is not supported with a empty linked list" << endl;
            }
            else {
                Node *temp = head;
                while (temp != NULL) {
                    if (temp->data == key) {
                        temp->next_node = temp->next_node->next_node;
                        return;
                    }
                    temp = temp->next_node;
                }
                cout << key << "is not found in the Linked List." << endl;
            }            
        }

        void DeleteBefore(int key) {
            if (head == NULL) {
                cout << "This operation is not supported with a empty linked list" << endl;
            }
            else {
                Node *temp = head;
                while (temp != NULL) {
                    if (key == temp->next_node->next_node->data) {
                        temp->next_node = temp->next_node->next_node;
                        return;
                    }
                    temp = temp->next_node;
                }
                cout << "There is no element in Linked List with value" << key << endl;
            }
        }
        
        void DeleteAt(int key) {
            if (head == NULL) {
                cout << "This operation is not supported with a empty linked list" << endl;
            }
            else {
                Node * temp = head;
                while (temp != NULL) {
                    if (key == temp->next_node->data) {
                        temp->next_node = temp->next_node->next_node;
                        return;
                    }
                    temp = temp->next_node;
                }
                cout << "There is no element in Linked List with value" << key << endl;
            }
        }

        // Searching
        int Search(int key) {
            int count = 0;
            Node *temp = head;
            while (temp->next_node != NULL) {
                if (temp->data == key) {
                    return count;
                }
                count ++;
                temp = temp->next_node;
            }
            return -1;
        }
};

int main() {
    LinkedList obj1;
    obj1.InsertRear(22);
    obj1.InsertRear(23);
    obj1.InsertRear(25);
    obj1.InsertRear(27);


    cout << "Current Array : \t";
    obj1.display_linked_list();

    obj1.InsertAfter(26, 25);
    cout << "Insert 26 after 25 : \t";
    obj1.display_linked_list();

    obj1.InsertBefore(24, 25);
    cout << "Insert 24 before 25 : \t";
    obj1.display_linked_list();

    obj1.InsertAt(-25, 25);
    cout << "Insert -25 in place of 25 : \t";
    obj1.display_linked_list();
    
    obj1.InsertFront(-22);
    cout << "Insert -22 in front : \t";
    obj1.display_linked_list();

    obj1.DeleteRear();
    cout << "Delte Rear most element : \t";
    obj1.display_linked_list();

    obj1.DeleteAfter(25);
    cout << "Delete element after 25 : \t";
    obj1.display_linked_list();
    
    obj1.DeleteBefore(25);
    cout << "Delete element before 25 : \t";
    obj1.display_linked_list();

    obj1.DeleteAt(25);
    cout << "Delete element with value 25 : \t";
    obj1.display_linked_list();

    obj1.DeleteFront();
    cout << "Delete Front Element : \t";
    obj1.display_linked_list();

    cout << "Search 23 element : \t";
    cout  << obj1.Search(23);

    return 0;
}