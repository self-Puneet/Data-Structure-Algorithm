#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

// Returns (u, weight, v) such that u is in activeVertices, v is not yet in active, and edge(u, v) is min
tuple<int, int, int> SmallestVertex(const vector<int>& activeVertices, const vector<int>& leftVertices, const vector<vector<int>>& AdjMatrix) {
    int minWeight = INT_MAX;
    int u = -1, v = -1;

    for (int i : activeVertices) {
        for (int j : leftVertices) {
            if (AdjMatrix[i][j] != 0 && AdjMatrix[i][j] < minWeight) {
                minWeight = AdjMatrix[i][j];
                u = i;
                v = j;
            }
        }
    }
    return make_tuple(u, minWeight, v);
}

vector<vector<int>> Prims(const vector<vector<int>>& AdjMatrix) {
    int n = AdjMatrix.size();
    vector<vector<int>> MST(n, vector<int>(n, 0));

    vector<int> activeVertices;
    vector<int> leftVertices;

    // Initially, 0 is in the tree
    activeVertices.push_back(0);
    for (int i = 1; i < n; ++i) {
        leftVertices.push_back(i);
    }

    while (!leftVertices.empty()) {
        auto [u, weight, v] = SmallestVertex(activeVertices, leftVertices, AdjMatrix);

        if (u == -1 || v == -1) {
            cout << "Graph is not connected!\n";
            break;
        }

        MST[u][v] = weight;
        MST[v][u] = weight;

        activeVertices.push_back(v);
        leftVertices.erase(remove(leftVertices.begin(), leftVertices.end(), v), leftVertices.end());
    }

    return MST;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> adjacencyMatrix = {
        {0, 2, 3, 0, 6},
        {2, 0, 8, 5, 7},
        {3, 8, 0, 0, 9},
        {0, 5, 0, 0, 4},
        {6, 7, 9, 4, 0}
    };

    auto result = Prims(adjacencyMatrix);

    cout << "Minimum Spanning Tree (Adjacency Matrix):\n";
    printMatrix(result);

    return 0;
}
