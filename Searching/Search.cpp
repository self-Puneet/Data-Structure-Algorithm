#include <iostream>
using namespace std;

template <typename T>

class Search {
    public:
        static T LinearSearch (T arr[], int size, T key) {
            for (int i = 0; i < size; i++) {
                if (key == arr[i]) {
                    return arr[i];
                }
            }
            return -1;
        }

        static void print (T arr[], int size) {
            for (int i = 0; i < size; i++) {
                if (i != size - 1) {
                    cout << arr[i] << ", ";
                }
                else {
                    cout << arr[i] << endl;
                }
            }
        }

        static int BinarySearch (T arr[], int size, T key) {
            int first = 0;
            int last = size-1;
            int mid = (first + last) / 2;
            while (key != arr[mid] && last != first) {
                if (key < arr[mid]){
                    last = mid - 1;
                }
                else {
                    first = mid + 1;
                }
                mid = (first + last) / 2; 
                // cout << first << " " << mid << " " << last << endl;
            }
            if (arr[mid] == key) {return mid;}
            else if (arr[last] == key) {return last;}
            else return -1;
        }
};