#include <bits/stdc++.h>

using namespace std;

int main() {

    int size; cin >> size;
    vector<int> nums(size);

    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    for(int i = 0; i < size-1; i++){
        cout << nums[i] << " ";
    }
    cout << nums[size-1];

}
