#include <iostream>

using namespace std;

int edit_distance(char s[], char t[], int n, int m){
	int dp[n + 1][m + 1];
	for(int i = 0; i <= n; i++) dp[i][0] = i; 
	for(int i = 0; i <= m; i++) dp[0][i] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int q = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]);
			q = s[i - 1] == t[j - 1] ? min(dp[i - 1][j - 1], q + 1) : q + 1; 
			dp[i][j] = q;
		}
	}
	return dp[n][m];
}

int main(){
	int p, n, m;
	char s[100], t[100];
	cin >> p;
	for(int i = 0; i < p; i++){
		cin >> n >> m;
		cin >> s >> t;
		cout << edit_distance(s, t, n, m) << "\n";
	}
	return 0;
}