#include <iostream>
#include <string>

using namespace std;

bool scramblestring(string s, string t){
	int n = s.length();
	if(n == 0) return true;
	int dp[n + 1][n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[1][i][j] = s[i] == t[j];
		}
	}
	for(int l = 2; l <= n; l++){
		for(int i = 0; i <= n - l; i++){
			for(int j = 0; j <= n - l; j++){
				bool f = false;
				for(int k = 1; k < l; k++){
					f |= dp[k][i][j] && dp[l - k][i + k][j + k];
					f |= dp[k][i][j + l - k] && dp[l - k][i + k][j];
				}
				dp[l][i][j] = f;
			}
		}
	}
	return dp[n][0][0];
}

int main(){
	int t, n;
	string p, q;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> p >> q;
		cout << scramblestring(p, q) << "\n";
	}
	return 0;
}