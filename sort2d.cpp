#include <iostream>

using namespace std;

int main(){
	int t, n, m, x, A[30][30];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				cin >> A[j][k];
			}
		}
		cin >> x;
		int p = m - 1, q = 0;
		bool f = false;
		while(p >= 0 && q < n){
			while(q < n && x > A[q][p]) q++;
			while(q < n && p >= 0 && x < A[q][p]) p--;
			if(q < n && p >= 0 && x == A[q][p]){
				f = true;
				break;
			}
		}
		cout << f << "\n";
	}
	return 0;
}