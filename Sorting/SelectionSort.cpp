#include <iostream>

using namespace std;
template <typename T>

class SelectionSort {
    public :
        static void sort (T arr[], int size) {
            for (int i = 0; i < size; i++) {
                int min = i;
                for (int j = i + 1; j < size; j++) {
                    if (arr[min] > arr[j]) {
                        min = j;
                    }
                }
                if (min != i) {
                    T temp = arr[min];
                    arr[min] = arr[i];
                    arr[i] = temp;
                }
            } 
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
};

int main() {
    int arr[6] = {1, 23, -34, 45, -5, -12};
    SelectionSort<int>::sort(arr, 6);
    SelectionSort<int>::print(arr, 6);
    return 0;
}