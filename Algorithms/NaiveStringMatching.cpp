#include <iostream>
using namespace std;

bool NaiveStringMatching(string str, string pattern) {
    int n = str.length(); int m = pattern.length();
    for (int i = 0; i < m-n; i++) {
        for (int j = 0; j < n; j++) {
            if (str[i+j] != pattern[j]) break;
        }
    }
}

int main() {
    cout << NaiveStringMatching("puneet", "une");
}