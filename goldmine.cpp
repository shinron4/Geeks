#include <iostream>
#include <climits>

using namespace std;

int maxgold(int m[100][100], int r, int c){
	int dp[r][c];
	for(int i = 0; i < r; i++) dp[i][c - 1] = m[i][c - 1];
	for(int i = c - 2; i >= 0; i--){
		for(int j = 0; j < r; j++){
			int ma = -INT_MAX;
			if(j - 1 >= 0) ma = max(dp[j - 1][i + 1], ma);
			if(j + 1 < r) ma = max(dp[j + 1][i + 1], ma);
			ma = max(ma, dp[j][i + 1]);
			dp[j][i] = ma + m[j][i];
		}
	}
	int ma = -INT_MAX;
	for(int i = 0; i < r; i++) ma = max(ma, dp[i][0]);
	return ma;
}

int main(){
	int t, r, c, m[100][100];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> r >> c;
		for(int j = 0; j < r; j++){
			for(int k = 0; k < c; k++){
				cin >> m[j][k];
			}
		}
		cout << maxgold(m, r, c) << "\n";
	}
	return 0;
}