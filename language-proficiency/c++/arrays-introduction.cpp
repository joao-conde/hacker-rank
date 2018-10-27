#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[i];        
    }  
    
    for(int i = n-1; i > 0; i--){
        cout << nums[i] << " ";
    }
    cout << nums[0] << endl;
}
