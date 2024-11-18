#ifndef PriorityQueue
#define PriorityQueue

#include <iostream>
using namespace std;
template <typename T>
class Element {
    public:
        T array[2];
        Element() {}
        Element(T data, T rank) {
            array[0] = data;
            array[1] = rank;
        }
};

template <typename T>
class priorityQueue {
    public:
        Element<T>* array;
        int size = 0;
        int front = -1, rear = -1;
        priorityQueue(int n) {
            array = new Element<T>[n];
            size = n;
        }
        void enqueue(T data, T rank) {
            if (isFull()) {
                cout << "Queue overflow" << endl;
                return;
            }

            if (isEmpty()) { // First element
                front = rear = 0;
                array[rear] = Element<T>(data, rank);
            } else {
                int i = rear;
                rear = (rear + 1) % size;

                // Insert in sorted order based on rank
                while (i != front - 1 && array[i].array[1] > rank) {
                    array[(i + 1) % size] = array[i];
                    i = (i - 1 + size) % size; // Circular decrement
                }
                array[(i + 1) % size] = Element<T>(data, rank);
            }
        }

        T dequeue() {
            if (isEmpty()) {
                cout << "Queue underflow" << endl;
                return T(); // Return default value of T
            }

            T data = array[front].array[0];
            if (front == rear) { // Queue becomes empty
                front = rear = -1;
            } else {
                front = (front + 1) % size; // Move front circularly
            }
            return data;
        }

    
        bool isEmpty() {
            if (rear == -1) {
                return true;
            }
            return false;
        }
        bool isFull() {
            return (rear + 1) % size == front;
        }
        void print() {
            if (isEmpty()) {
                cout << "Queue is empty" << endl;
                return;
            }

            int i = front;
            while (true) {
                cout << "Data: " << array[i].array[0]
                    << ", Rank: " << array[i].array[1] << endl;
                if (i == rear) break;
                i = (i + 1) % size; // Circular increment
            }
        }
        void peek() {
            std::cout << "data -> " << array[0].array[0] << std::endl;
            std::cout << "rank -> " << array[0].array[1] << std::endl;
        }
};

#endif