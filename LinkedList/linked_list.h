#ifndef A_H
#define A_H

#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next_node;

        Node(int value);
        Node(int value, Node *head);
};

class LinkedList {
    private:
        Node *head;

    public:
        LinkedList();

        void Menu();

        virtual void display_linked_list();

        int count();

        int rear();

        int front();

        virtual void InsertRear(int d);
        virtual void InsertFront(int d);
        void InsertAfter(int value, int key);
        void InsertBefore(int value, int key);
        void InsertAt(int value, int key);

        virtual void DeleteRear();
        virtual void DeleteFront();
        void DeleteAfter(int key);
        void DeleteBefore(int key);
        void DeleteAt(int key);

        int Search(int key);
};

#endif