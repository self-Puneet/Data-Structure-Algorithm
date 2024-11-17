#include <iostream>

using namespace std;
template <typename T>

class QuickSort {
    private :
        static void _sort_ (T arr[], int initial, int final) {
            
            int pivot = initial, i = initial + 1, j = final;

            if (initial == final) {
                return;
            }
            else if (final - initial == 1) {
                if (arr[final] < arr[initial]) {
                    T temp = arr[final];
                    arr[final] = arr[initial];
                    arr[initial] = temp;
                }
                return;
            }
            else {
                while (i < j) {
                    while (arr[i] < arr[pivot] && i <= final) {i++;}
                    while (arr[j] > arr[pivot] && j >= initial) {j--;}
                    
                    if (i < j) {
                        T temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                    }
                }

                T temp = arr[pivot];
                
                for (int k = pivot + 1; k <= j; k++) {
                    arr[k-1] = arr[k];
                }

                arr[j] = temp;
            
                _sort_(arr, initial, j - 1);
                _sort_(arr, j + 1, final); 
            }
        }
    public :
        static void sort (T arr[], int size) {
            _sort_(arr, 0, size - 1);
        }

        static void print (T arr[], int initial, int final) {
            for (int i = initial; i <= final; i++) {
                if (i != final) {
                    cout << arr[i] << ", ";
                }
                else {
                    cout << arr[i] << endl;
                }
            }
        }
};

int main() {
    // int arr[6] = {1, 23, -34, 45, -5, -12};
    int arr[6] = {4,7,2,3,0,-1};

    QuickSort<int>::sort(arr, 6);
    QuickSort<int>::print(arr, 0 , 6);
    return 0;
}