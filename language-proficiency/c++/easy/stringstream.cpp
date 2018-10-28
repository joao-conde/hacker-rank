#include <bits/stdc++.h>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> parsedInts;
    int element;
    char dummy;
    while(ss >> element){
        parsedInts.push_back(element);
        ss >> dummy;
    }
    return parsedInts;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
}