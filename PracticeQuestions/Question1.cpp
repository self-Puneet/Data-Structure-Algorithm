// Shopping List Management: You have a personal grocery shopping list that you want to manage efficiently. Create a program that allows you to add items to the list, remove items if you change your mind, and display the current list of items. Use an array to store the items, ensuring the program can handle up to 50 items.

#include <iostream>
#include <string>
using namespace std;

class ShoppingList {
    
    public :
        
        int front = -1;
        int rear = -1;
        string array[50] = {};

        void addItems (string itemName) {
            if (front == -1) {
                front = rear = 0;
                array[front] = itemName;
                cout << itemName << " item is added to our database ..." << endl;
            }
            else if (rear < 49) {
                rear ++;
                arr[rear] = itemName;
                cout << itemName << " item is added to our database ..." << endl;
            }
            else {
                fullInventory();
            }
        }

        void removeItems (string itemName) {
            int indexRemove = search(itemName);
            int size = sizeof(this.array) / sizeof(this->array);
            if (indexRemove == -1) {
                cout << "Sorry we can't find this element in our database !! Try again with another one ..." << endl;
            }
            else {
                for (int i = indexRemove; i < rear; i ++) {
                    this.array[i] = this.array[i + 1];
                }
                rear --;
                cout << itemName << " item is removed from our database." << endl;
            }
            
        }

        int search (string itemName) {

            int size = sizeof(this.array) / sizeof(this->array);

            for (int i = 0; i < rear; i++) {
                if (itemName == this.array[i]) {
                    return i;
                }
            }
            return -1;
        }

        void fullInventory() {
            cout << "Sorry there is no space left for more items. TRY removing some of them..." << endl;
        }

        void display () {
            for (int i = 0; i <= rear; i ++) {
                if (i == rear) {
                    cout << this.array[i] << endl;
                }
                else {
                    cout << this.array[i] << ", ";
                }
            }
        }

};