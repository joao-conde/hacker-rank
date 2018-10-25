#include <bits/stdc++.h>

using namespace std;

int main() {

    int size; cin >> size;
    vector<int> nums(size);

    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }

    int x, a, b;
    cin >> x >> a >> b;

    nums.erase(nums.begin() + x-1);
    nums.erase(nums.begin() + a - 1, nums.begin() + b - 1);
    cout << nums.size() << endl;
    for(int i = 0; i < nums.size()-1; i++){
        cout << nums[i] << " ";
    }
    cout << nums[nums.size()-1];

}
