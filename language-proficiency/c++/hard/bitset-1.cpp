#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;


ull getNext(ull prev, ull p, ull q, ull mod) { return (prev * p + q) % mod; }

int main() {
    int n, s, p, q;
    cin >> n >> s >> p >> q;

    // floyd's tortoise and hare algorithm
    ull tortoise, hare, mod = pow(2, 31), initial = s % mod;
    tortoise = getNext(initial, p, q, mod); //second val
    hare = getNext(tortoise, p, q, mod);   	//third val

	//cycle detection
	int vals = 1;
	while(tortoise != hare){
		if(vals >= n){
			cout << n << endl;
			return 0;
		}
		tortoise = getNext(tortoise, p, q, mod);
		hare = getNext(getNext(hare, p, q, mod), p, q, mod);
		vals++;
	}

	//determine cyle start
	ull preCycleLen = 0;
	tortoise = initial;
	while(tortoise != hare){
		tortoise = getNext(tortoise, p, q, mod);
		hare = getNext(hare, p, q, mod);
		preCycleLen++;
	}
	
	//shortest cycle length
	ull cycleLen = 1;
	hare = getNext(tortoise, p, q, mod);
	while(tortoise != hare){
		hare = getNext(hare, p, q, mod);
		cycleLen++;
	}

	cout << preCycleLen + cycleLen << endl;
}