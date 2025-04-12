// // Given a set of positive integers and a target sum, your task is to find all unique subsets of the given set such that the sum of the elements in each subset is equal to the target sum.

#include <iostream>
#include <vector>
using namespace std;

void _SumOfSubsets(
    vector<vector<int>>& final_array, 
    vector<int>& current_subset, 
    vector<int>& array, 
    vector<int>& status_array, 
    int target, 
    int index
);

vector<vector<int>> SumOfSubsets(vector<int> array, int target) {
    vector<vector<int>> final_array;
    vector<int> current_subset;
    vector<int> status_array(array.size(), 0);
    _SumOfSubsets(final_array, current_subset, array, status_array, target, 0);
    return final_array;
}

void _SumOfSubsets(
    vector<vector<int>>& final_array, 
    vector<int>& current_subset, 
    vector<int>& array, 
    vector<int>& status_array, 
    int target, 
    int index
) {
    int sum = 0;
    for (int i : current_subset) {
        sum += i;
    }
    if (sum == target) {
        final_array.push_back(current_subset);
        return;
    }
    if (sum > target || index == array.size()) {
        return;
    }

    current_subset.push_back(array[index]);
    _SumOfSubsets(final_array, current_subset, array, status_array, target, index + 1);

    current_subset.pop_back();
    _SumOfSubsets(final_array, current_subset, array, status_array, target, index + 1);
}


int main() {
    vector<int> array = {3, 34, 4, 12, 5, 2};
    int target = 9;
    vector<vector<int>> final_array = SumOfSubsets(array, target);
    for (const auto& subset : final_array) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    
}
