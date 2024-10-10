#include <iostream>
#include "linked_list.h"
using namespace std;

class CircularLinkedList : LinkedList{
    private:
        Node *head;
    
    public: 

        CircularLinkedList() {
            head = NULL; 
        }

        void display_linked_list() override {
            Node *temp = head;
            if (temp->next_node == head) {
                cout << temp->data;
            }
            else {
                cout << temp->data << " -> ";
                temp = temp->next_node;
                while (temp != head) {
                    if (temp->next_node == head) {
                        cout << temp-> data << endl;
                    }
                    else {
                        cout << temp-> data << " -> ";
                        cout << "hehe";
                    }
                    temp = temp->next_node;
                }
            }
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
        void InsertRear(int d) override {
            if (head == NULL) {    
                head = new Node(d);
                head->next_node = head;
                cout << "head node with value " << d << " is made" << endl;
            }
            else {
                Node *temp = head;
                while (temp->next_node != NULL) {
                    temp = temp->next_node;
                }
                temp->next_node = new Node(d, head);
                cout << "node with value " << d << " is made" << endl;
            }
        }

        void InsertFront(int d) override {
            Node *temp = head;
            temp = temp->next_node;
            while (temp->next_node != head) {
                temp = temp->next_node;
            }
            Node *front_node = new Node(d, head);
            temp->next_node = front_node;
            head = front_node; 
        }


        // Deletion
        void DeleteRear() override {
            if (head == NULL) {
                cout << "This operation is not supported with a empty linked list" << endl;
            }
            else {
                Node *temp = head;
                if (temp->next_node->next_node == head){
                    temp->next_node = head;
                }
                else {
                    while (temp->next_node->next_node != head){
                        temp = temp->next_node;
                    }
                    temp->next_node = head;
                }
            }
        }

        void DeleteFront() override {
            Node *temp = head;
            if (temp->next_node == head) {
                head = NULL;
            }
            else {
                Node *temp = head;
                while (temp->next_node != head) {
                    temp = temp->next_node;
                }
                temp->next_node = head->next_node;
                head = head->next_node;
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
    CircularLinkedList obj1;
    obj1.InsertRear(22);
    // obj1.InsertRear(23);
    // obj1.InsertRear(25);
    // obj1.InsertRear(27);
    obj1.display_linked_list();
    cout << endl;
    obj1.InsertFront(23);
    obj1.display_linked_list();
    obj1.DeleteRear();
    obj1.display_linked_list();


    // cout << "Current Array : \t";
    // obj1.display_linked_list();
// 
    // obj1.InsertAfter(26, 25);
    // cout << "Insert 26 after 25 : \t";
    // obj1.display_linked_list();
// 
    // obj1.InsertBefore(24, 25);
    // cout << "Insert 24 before 25 : \t";
    // obj1.display_linked_list();
// 
    // obj1.InsertAt(-25, 25);
    // cout << "Insert -25 in place of 25 : \t";
    // obj1.display_linked_list();
    // 
    // obj1.InsertFront(-22);
    // cout << "Insert -22 in front : \t";
    // obj1.display_linked_list();
// 
    // obj1.DeleteRear();
    // cout << "Delte Rear most element : \t";
    // obj1.display_linked_list();
// 
    // obj1.DeleteAfter(25);
    // cout << "Delete element after 25 : \t";
    // obj1.display_linked_list();
    // 
    // obj1.DeleteBefore(25);
    // cout << "Delete element before 25 : \t";
    // obj1.display_linked_list();
// 
    // obj1.DeleteAt(25);
    // cout << "Delete element with value 25 : \t";
    // obj1.display_linked_list();
// 
    // obj1.DeleteFront();
    // cout << "Delete Front Element : \t";
    // obj1.display_linked_list();
// 
    // cout << "Search 23 element : \t";
    // cout  << obj1.Search(23);

    return 0;
}