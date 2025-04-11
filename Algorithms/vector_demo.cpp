#include <iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> new_vector(5);                       // initializing with size and by-default value
    vector<int> new_new_vector(new_vector);         // copying 1 array into other
    cout << new_vector.size();

    // operations
    new_vector.push_back(10);                       // append
    new_vector.insert(new_vector.begin() + 2, 30);  // insert(position, value)
    new_vector.pop_back();                          // pop
    new_vector.erase(new_vector.begin() + 2);       // pop at index


    // accessing elements
    cout << new_vector.at(2);
    cout << new_vector.front();
    cout << new_vector.end();
    cout << new_vector[0];

    // 2-D Vectors
    vector<vector<int>> matrix;                         // initialization
    vector<vector<int>> matrix2(3, vector<int>()4,0);   // initialization with fixed size and number
}