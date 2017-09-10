#include <iostream>

using namespace std;

int dp[100][100];

int eggdrop(int n, int k){
	for(int i = 0; i <= n; i++) dp[i][0] = 0;
	for(int i = 1; i <= k; i++) dp[1][i] = i;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = INT_MAX;
			for(int p = 1; p <= j; p++){
				int l = max(dp[i - 1][p - 1], dp[i][j - p]) + 1;
				if(l < dp[i][j]) dp[i][j] = l;
			}
		}
	}
	return dp[n][k];
}

int main(){
	int t, n, k;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		cout << eggdrop(n, k) << "\n";
	}
	return 0;
}