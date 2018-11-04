#include <bits/stdc++.h>
using namespace std;

//sliding window of size K
void printKMax(int arr[], int n, int k){

	deque<int> slidingWindow;

	//fill window with biggest of first K
	for(int i = 0; i < k; i++){
		while(!slidingWindow.empty() && arr[i] >= arr[slidingWindow.back()])
			slidingWindow.pop_back();

		slidingWindow.push_back(i);
	}

	for(int i = k; i < n; i++){
		cout << arr[slidingWindow.front()] << " ";

		while(!slidingWindow.empty() && slidingWindow.front() <= i - k)
			slidingWindow.pop_front();

		while(!slidingWindow.empty() && arr[i] >= arr[slidingWindow.back()])
			slidingWindow.pop_back();

		slidingWindow.push_back(i);
	}

	cout << arr[slidingWindow.front()] << endl;
}

int main(){
    int t;
	cin >> t;
	while(t>0) {
		int n, k; cin >> n >> k;
    	int arr[n];
    	for(int i = 0; i < n; i++)
      		cin >> arr[i];
			  
    	printKMax(arr, n, k);
        t--;
  	}
}