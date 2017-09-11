#include <iostream>

using namespace std;

int dp[11][31]; 

int maxstock(int A[], int n, int k){
	for(int i = 0; i <= n; i++) dp[0][i] = 0;
	for(int i = 0; i <= k; i++) dp[i][0] = dp[i][1] = 0;
	for(int i = 1; i <= k; i++){
		for(int j = 2; j <= n; j++){
			int m = -INT_MAX;
			for(int l = 1; l < j; l++){
					m = max(m, A[j - 1] - A[l - 1] + dp[i - 1][l]);
			}
			dp[i][j] = max(dp[i][j - 1], m);
		}
	}
	return dp[k][n];
}

int main(){
	int t, n, k, A[30];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> k >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		cout << maxstock(A, n, k) << "\n";
	}
	return 0;
}