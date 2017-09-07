#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dp[100][3];

struct ARR_ELE{
	int e, i;
} m[100][100];

struct COMP{
	bool operator()(struct ARR_ELE p, struct ARR_ELE q){
		return p.e > q.e;
	}
} compare;


int main(){
	int t, n, x, ma_size, ma;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				cin >> m[j][k].e;
				m[j][k].i = k;
			}
		}
		for(int j = 0; j < n; j++) sort(m[j], m[j] + n, compare);
		ma_size = n >= 3 ? 3 : n;
		for(int j = 0; j < ma_size; j++) dp[0][j] = m[0][j].e;
		for(int j = 1; j < n; j++){
			for(int k = 0; k < ma_size; k++){
				ma = -INT_MAX;
				for(int l = 0; l < ma_size; l++){
					if(m[j][k].i != m[j - 1][l].i){
						if(dp[j - 1][l] + m[j][k].e > ma) ma = dp[j - 1][l] + m[j][k].e;
					}
				}
				dp[j][k] = ma;
			}
		}
		ma = -INT_MAX;
		for(int j = 0; j < ma_size; j++) if(dp[n - 1][j] > ma) ma = dp[n - 1][j];
		cout << ma << "\n";
	}
	return 0;
}