#include <iostream>
#include <vector>
using namespace std;

// Function to construct the DP table
vector<vector<int>> KnapsackTable(vector<int>& weight, vector<int>& value, int total_weight) {
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(total_weight + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= total_weight; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp;
}

// Function to find the items included in the knapsack
vector<int> TraceKnapsackItems(vector<vector<int>>& dp, vector<int>& weight, vector<int>& value, int total_weight) {
    int n = weight.size();
    vector<int> selected_items;
    int w = total_weight;

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            // Item i-1 was included
            selected_items.push_back(i - 1);
            w -= weight[i - 1];
        }
    }

    return selected_items;
}

int main() {
    // Example input (you can change it)
    vector<int> weight = {2, 3, 3};
    vector<int> value = {1, 2, 4};
    int total_weight = 6;

    // Step 1: Construct the table
    vector<vector<int>> dp = KnapsackTable(weight, value, total_weight);

    // Step 2: Trace back to find selected items
    vector<int> selected = TraceKnapsackItems(dp, weight, value, total_weight);

    // Output the DP table
    cout << "DP Table:\n";
    for (const auto& row : dp) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    // Output selected items
    cout << "\nSelected item indices (0-based): ";
    for (int idx : selected) {
        cout << idx << " ";
    }
    cout << "\n";

    return 0;
}
