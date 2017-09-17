#include <iostream>
#include <cstring>

using namespace std;

bool checkinterleave(string A, string B, string C){
	int n = A.length(), m = B.length(), k = C.length();
	if(k != m + n) return false;
	bool dp[n + 1][m + 1];
	dp[0][0] = true;
	bool f = true;
	for(int i = 1; i <= n; i++){
		f = f & (A[i - 1] == C[i - 1]);
		dp[i][0] = f;
	}
	f = true;
	for(int i = 1; i <= m; i++){
		f = f & (B[i - 1] == C[i - 1]);
		dp[0][i] = f;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) dp[i][j] = dp[i - 1][j];
			else if(A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) dp[i][j] = dp[i][j - 1];
			else if(A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			else dp[i][j] = false;
		}
	}
	return dp[n][m];
}

int main(){
	int t;
	string A, B, C;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> A >> B >> C;
		cout << checkinterleave(A, B, C) << "\n";
	}
	return 0;
}