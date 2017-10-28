#include <iostream>

using namespace std;

int maxsubs(int a[], int n, int m){
	int dp[n + 1][m + 1];
	for(int j = 0; j <= m; j++) dp[0][j] = 0;
	for(int j = 0; j <= m; j++){
		if(a[0] > j) dp[1][j] = 0;
		else dp[1][j] = a[0];
	}
	for(int i = 2; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(j == 0) dp[i][j] = 0;
			else if(a[i - 1] > j){
				dp[i][j] = dp[i - 1][j];
			}
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - a[i - 1]] + a[i - 1]);
			}
		}
	}
	return dp[n][m];
}


int main(){
	int t, n, m, a[10001];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> a[i];
		cout << maxsubs(a, n, m) << "\n";
	}
	return 0;
}