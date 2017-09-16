#include <iostream>

using namespace std;

int ways(int A[], int n, int score){
	int dp[n + 1][score + 1];
	for(int i = 0; i <= n; i++) dp[i][0] = 1;
	for(int i = 1; i <= score; i++) dp[0][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= score; j++){
			dp[i][j] = 0;
			for(int k = 0; k <= j; k += A[i - 1]){
				dp[i][j] += dp[i - 1][j - k];
			}
		}
	}
	return dp[n][score];
}

int main(){
	int t, score, A[3] = {3, 5, 10};
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> score;
		cout << ways(A, 3, score) << "\n";
	}
	return 0;
}