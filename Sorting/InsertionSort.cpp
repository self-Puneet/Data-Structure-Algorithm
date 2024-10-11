#include <iostream>

using namespace std;
template <typename T>

class SelectionSort {
    public :
        static void sort (T arr[], int size) {
            for (int i = 1; i < size; i++) {
                for (int j = 0; j < i; j++) {
                    if (arr[j] > arr[i]) {
                        T temp = arr[i];
                        for (int k = i; k > j; k--) {
                            arr[k] = arr[k-1];
                        }
                        arr[j] = temp;
                    }
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