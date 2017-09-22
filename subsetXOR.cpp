#include <iostream>
#include <cmath>

using namespace std;

int numxor(int A[], int n, int k){
	int m = -INT_MAX;
	for(int i = 0; i < n; i++) m = max(m, A[i]);
	m = (1 << (m > 0 ? (int)log2(m) + 1 : 1)) - 1;
	if(k > m) return 0;
	int dp[n + 1][m + 1];
	dp[0][0] = 1;
	for(int i = 1; i <= m; i++) dp[0][i] = 0;
	for(int i = 1; i < n; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j ^ A[i - 1]];
		}
	}
	return dp[n][k];
}

int main(){
	int t, n, k, A[100];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int j = 0; j < n; j++) cin >> A[j];
		cout << numxor(A, n, k) << "\n";
	}
	return 0;

}