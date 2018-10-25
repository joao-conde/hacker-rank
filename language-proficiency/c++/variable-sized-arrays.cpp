#include <vector>
#include <iostream>

using namespace std;

int main(){

    int n, q;
    cin >> n >> q;
    vector<int> arrays[n];
    
    for(int i = 0; i < n; i++){
        int size; cin >> size;        

            int el;
            while(size > 0){
            cin >> el;
                arrays[i].push_back(el);
            size--;        
        }
    }

    for(int i = 0; i < q; i++){
        int j, k;
        cin >> j >> k;
        cout << arrays[j].at(k) << endl;
    }
    
    return 0;
}