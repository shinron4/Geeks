#include <iostream>

using namespace std;

int A[1000], dp[1001][1000];

int coin_change(int n, int m){
	for(int i = 0; i <= n; i++) dp[i][0] = 1;
	for(int i = 1; i <= m; i++) dp[0][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = 0;
			for(int k = 0; k <= j; k += A[i - 1]) dp[i][j] += dp[i - 1][j - k];
		}
	}
	return dp[n][m];
}

int main(){
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		cin >> m;
		cout << coin_change(n, m) << "\n";
	}
	return 0;
}