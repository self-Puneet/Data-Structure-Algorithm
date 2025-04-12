// You are given two sequences, X and Y, and your task is to write a program that uses dynamic programming to find the length of the longest subsequence that is common to both sequences. Additionally, reconstruct and print the LCS itself.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

auto LCS_Table(string a, string b) {
    vector<vector<int>> numberTable(a.length() + 1, vector<int>(b.length() + 1, 0));
    vector<vector<int>> arrowTable(a.length() + 1, vector<int>(b.length() + 1, 0));

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (numberTable[i][j-1] > numberTable[i-1][j]) {
                numberTable[i][j] = numberTable[i][j-1];
                arrowTable[i][j] = -1;
            }
            else if (numberTable[i][j-1] < numberTable[i-1][j]) {
                numberTable[i][j] = numberTable[i-1][j];
                arrowTable[i][j] = 1;
            }
            else {
                numberTable[i][j] = numberTable[i-1][j-1] + 1;
                arrowTable[i][j] = 0;
            }
        }
    }

    return make_pair(numberTable, arrowTable);
}

string LCS(string a, string b) {
    vector<vector<int>> numberTable = LCS_Table(a, b).first, arrowTable = LCS_Table(a, b).second;
    string final_string = "";
    int i = a.length(), j = b.length();
    while(i > 0 && j > 0) {
        if (arrowTable[i][j] == 0){ 
            final_string = a[i-1] + final_string; 
            i--; 
            j--; 
        }
        else if (arrowTable[i][j] == 1) i--;
        else j--;
    }
    return final_string;
}

int main() {
    string a = "MLNOM", b = "MNOM";
    string lcs = LCS(a,b);
    cout << lcs << endl;
    return 0;
}