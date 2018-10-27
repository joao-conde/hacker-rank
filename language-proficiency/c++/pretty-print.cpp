#include <bits/stdc++.h>
using namespace std;

//C++ stream manipulators
int main() {
    int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	
    while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;

        /* My code */

        //A - hexadecimal output with prefix no upper cases aligned left
        //Converting to long strips decimal part
        cout << hex << left << showbase << nouppercase << (long) A << endl;

        //B - right aligned 15 width long with blank space filling made of '_' showing signs explicit number with 2 decimal places
        cout << fixed << setprecision(2) << right << setw(15) << setfill('_') << showpos << B << endl;

        //C - 9 decimal precision with uppercase and in scientific notation, not signed
        cout << noshowpos << setprecision(9) << uppercase << scientific << C << endl;
    }
}