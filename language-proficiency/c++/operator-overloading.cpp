#include <bits/stdc++.h>
using namespace std;

class Matrix{
	public:
		vector<vector<int>> a;
		
		Matrix operator+(Matrix &m1){
			Matrix result;
			for(int i = 0; i < m1.a.size(); i++){
				vector<int> line;
				for(int k = 0; k < m1.a[i].size(); k++){
					line.push_back(m1.a[i][k] + a[i][k]);
				}
				result.a.push_back(line);
			}
			return result;
		}
};


int main () {
	int cases,k;
	cin >> cases;
	for(k=0;k<cases;k++) {
		Matrix x;
		Matrix y;
	  	Matrix result;
		int n,m,i,j;
		cin >> n >> m;
		for(i=0;i<n;i++) {
			vector<int> b;
			int num;
			for(j=0;j<m;j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for(i=0;i<n;i++) {
			vector<int> b;
			int num;
			for(j=0;j<m;j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}
		result = x+y;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}  
}
