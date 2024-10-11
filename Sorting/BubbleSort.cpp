#include <iostream>
using namespace std;

template <typename T>

class BubbleSort {
    public :
        static void sort (T arr[], int size) {
            for (int i = size - 1; i > 0; i--) {
                bool flag = false;
                for (int j = 1; j <= i; j++) {
                    if (arr[j] < arr[j-1]) {
                        T temp = arr[j];
                        arr[j] = arr[j-1];
                        arr[j-1] = temp;
                        flag = true;
                    }
                }
                if (flag == false) {
                    break;
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

int main () {
    int arr[6] = {2, -98, 56, 9, 23, -89};
    BubbleSort<int>::bubbleSort(arr, 6);
    BubbleSort<int>::print(arr, 6);
    return 0;
}