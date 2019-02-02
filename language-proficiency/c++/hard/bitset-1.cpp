#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull getNext(ull prev, ull p, ull q, ull mod) { return prev * p + q % mod; }

int main() {
    int n, s, p, q;
    cin >> n >> s >> p >> q;

    // a[0] = S (modulo 2^31)
    // for i = 1 to N-1
    // 	a[i] = a[i-1]*P+Q (modulo 2^31)

    // floyd's tortoise and hare algorithm
    ull tortoise, hare, mod = pow(2, 31);
    tortoise = getNext(s % mod, p, q, mod); //second val
    hare = getNext(tortoise, p, q, mod);   	//third val

	while(tortoise != hare){
		tortoise = getNext(tortoise, p, q, mod);
		hare = getNext(getNext(hare, p, q, mod), p, q, mod);
	}

	cout << "tort: " << tortoise
			<< "hare: " << hare << endl;
}