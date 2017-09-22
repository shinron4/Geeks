#include <iostream>
#include <iomanip>

using namespace std;

double dp[101][100][100];

double knightprob(int n, int x, int y, int s){
	int di[8] = {-1, 1, -1, 1, -2, -2, 2, 2};
	int dj[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
	for(int k = 0; k <= s; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
		dp[k][i][j] = 0;
	dp[0][x][y] = 1;
	double sum = 0;
	for(int k = 1; k <= s; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				double p;
				for(int l = 0; l < 8; l++){
					int u = i + di[l], v = j + dj[l];
					p = dp[k - 1][i][j] * 0.125;
					if(u < 0 || u >= n || v < 0 || v >= n) sum += p;
					else dp[k][u][v] += p;
				}
			}
		}
	}
	return 1 - sum; 
}

int main(){
	int t, n, k, x, y;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> x >> y >> k;
		cout << fixed;
		cout << setprecision(6) << knightprob(n, x, y, k) << "\n";
	}
	return 0;
}