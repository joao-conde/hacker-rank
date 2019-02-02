#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s, p, q;
	cin >> n >> s >> p >> q;

	// a[0] = S (modulo 2^31)
	// for i = 1 to N-1
	// 	a[i] = a[i-1]*P+Q (modulo 2^31) 

	unsigned long long mod = pow(2, 31);
	int a = s % mod;

	for(int i = 1; i < 50; i++){
		cout << a << " ";
		a = a * p + q % mod; 
	}

}