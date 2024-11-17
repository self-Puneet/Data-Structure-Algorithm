#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
template <typename T>

class Queue {
    public:
        T* array;
        int size = 0;
        int front = -1, rear = -1;
        Queue(int n) {
            array = new T[n];
            size = n;
        }
        void enqueue(T data) {
            if (rear == size-1) {
                cout << "array overflow" << endl;
            }
            else if (!isEmpty()) {
                rear += 1;
                array[rear] = data;
            }
            else {
                front = 0;
                rear = 0;
                array[rear] = data;
            }
        }
        T dequeue() {
            if (!isEmpty()) {
                if (rear == front) {
                    rear = front = -1;
                    return array[0]; 
                }
                else {
                    for (int i = 0; i < rear; i++) {
                        array[i] = array[i+1];
                    }
                    rear -= 1;
                    return array[0];    
                }
            }
            else {
                cout << "this operation is not supported with empty queue." << endl;
                return NULL;
            }
        }
        bool isEmpty() {
            if (rear == -1) {
                return true;
            }
            return false;
        }
};

#endif