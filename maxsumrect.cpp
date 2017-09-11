#include <iostream>
#include <climits>

using namespace std;

int maxsubarray(int t[], int n){
	int dp[n + 1], m = -1000000;
	dp[0] = -100000;
	for(int i = 1; i <= n; i++){
		dp[i] = t[i - 1] + (dp[i - 1] + t[i - 1] > t[i - 1] ? dp[i - 1] : 0); 
		if(dp[i] > m) m = dp[i];
	}
	return m;
}

int main(){
	int t, r, c;
	int A[100][100], B[100][100], C[100];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> r >> c;
		for(int j = 0; j < r; j++){
			for(int k = 0; k < c; k++){
				cin >> A[j][k];
				B[j][k] = A[j][k] + (k > 0 ? B[j][k - 1] : 0); 
			}

		}
		int m = -INT_MAX;
		for(int j = 0; j < c; j++){
			for(int k = j; k < c; k++){
				cout << j << " " << k << "\n";
				for(int p = 0; p < r; p++) cout << (C[p] = B[p][k] - (j > 0 ? B[p][j - 1] : 0)) << " ";
				cout << "\n";
				int l = maxsubarray(C, r);
				cout << l << "\n";
				m = max(m, l);
			}
		}
		cout << m << "\n";
	}
	return 0;
}