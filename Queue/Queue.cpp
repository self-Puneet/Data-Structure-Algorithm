#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
private:
    T* array;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int n) {
        array = new T[n];
        size = n;
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] array;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(T data) {
        if (isFull()) {
            cout << "Queue overflow" << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        array[rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow" << endl;
            return;
        }

        if (front == rear) { // Single element in the queue
            front = rear = -1;
        } else {
            front = (front + 1) % size; // Move front circularly
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        int i = front;
        while (true) {
            cout << array[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size; // Circular increment
        }
        cout << endl;
    }

    void peek() {
        if (!isEmpty()) {
            cout << array[front] << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }
};