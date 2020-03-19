#include <bits/stdc++.h>
using namespace std;

int main() {
    int integers, queries; 
    cin >> integers;
    vector<int> my_ints(integers);

    for(int i = 0; i < integers; i++)
        cin >> my_ints[i];

    cin >> queries; 

    for(int i = 0; i < queries; i++){
        int query; cin >> query;
        auto low = lower_bound(my_ints.begin(), my_ints.end(), query);
        cout << (*low == query ? "Yes " : "No ") << low - my_ints.begin() + 1 << endl; //1-based indexes...
    }
}