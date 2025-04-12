#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

auto EncodeText (string text) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    vector<int> encode;

    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if(text[i] == alphabet[j]) encode.push_back(j);
        }
    }

    int max = INT8_MIN;
    for (int i = 0; i < encode.size(); i++) {
        if (encode[i] > max) max = encode[i];
    }

    return make_pair(max, encode);
}

int CalcHash(vector<int> encode, int d, int q) {
    int hash = 0;
    int count = 0;
    for (int i = encode.size() - 1; i > -1; i--) {
        hash = encode[i] * pow(d, count) + hash;
    }
    return hash % q;
}

int updateHash(int pre_hash, int added_value, int removed_value, int q, int h, int d) {
    int new_hash = (d * (pre_hash - removed_value * h) + added_value) % q;
    if (new_hash < 0) new_hash = q + new_hash;
    return new_hash;
}

vector<int> RabinKarpStringMatching(string text, string pattern, int q) {
    
    /*
        n : length of text
        m : length of pattern
        q : the prime number
        d : no of distict characters in text
        h : d^(m-1) % q
        patt_has : has of pattern (fixed)
    */

    vector<int> indices;
    int n = text.length(), m = pattern.length();
    int d = EncodeText(text).first;
    int h = (int)pow(d, m-1) % q;
    vector<int> text_encode = EncodeText(text).second;
    int patt_hash = CalcHash(EncodeText(pattern).second, d, q);

    for (int i = 0; i <= n-m; i++) {
        vector<int> temp (text_encode.begin() + i, text_encode.begin() + i + m);
        int window_hash = CalcHash(temp, d, q);
        if (window_hash == patt_hash) {
            indices.push_back(i);
        }
        window_hash = updateHash(window_hash, text_encode[i], text_encode[i+m], q, h, d);
    }

    return indices;
}

int main() {
    string str = "ababcabcabababd";
    string pattern = "ababca";
    vector<int> indices = RabinKarpStringMatching(str, pattern, 13);
    cout << "[";
    for (int i : indices) {
        cout << i << " ";
    }
    cout << "]" << endl;
    return 0;
}