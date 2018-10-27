#include <bits/stdc++.h>
using namespace std;

int main() {

    int queries;
    cin >> queries;

    set<int> my_ints;
    for(int i = 0; i < queries; i++){
        int type, val;
        cin >> type >> val;

        if(type == 1)
            my_ints.insert(val);
        else 
        if(type == 2)
            my_ints.erase(val);
        else 
        if(type == 3){
            auto it = my_ints.find(val);
            cout << (it != my_ints.end() ? "Yes" : "No") << endl;
        }
    }

}