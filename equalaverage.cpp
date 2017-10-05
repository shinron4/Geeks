#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool f[1000][10000];
int sol[1000][10000];

void equalaverage(int A[], int n, int s){
	bool dp[n][n][s + 1];
	for(int i  = 0; i < n; i++){
		for(int j = 1; j < n; j++){
			for(int k = 0; k <= s; k++){
				dp[i][j][k] = false;
			}
		}
	}
	for(int k = 0; k <= s; k++) dp[0][1][k] = false;
	dp[0][1][A[0]] = true;
	f[1][A[0]] = true;
	sol[1][A[0]] = 0;
	for(int i  = 1; i < n; i++){
		for(int k = 0; k <= s; k++) dp[i][1][k] = dp[i - 1][1][k];
		if(f[1][A[i]] == false){
			f[1][A[i]] = true;
			sol[1][A[i]] = i;
		}
		dp[i][1][A[i]] = true;
		for(int j = 2; j < n; j++){
			if(i + 1 >= j){
				for(int k = 0; k <= s; k++){
					dp[i][j][k] = (k >= A[i] ? dp[i - 1][j - 1][k - A[i]] : false) || dp[i - 1][j][k];
					if(dp[i][j][k] == true && f[j][k] == false){
						f[j][k] = true;
						sol[j][k] = i;
					}
				}				
			}
		}
	}
}

int main(){
	int t, n, a[1000], s, sp;
	vector<int> divs, subset;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		s = 0;
		for(int j = 0; j < n; j++){
			cin >> a[j];
			s += a[j];
		}
		sort(a, a + n);
		for(int j = 1; j <= (n / 2); j++) if(s * j % n == 0) divs.push_back(j);
		sp = s * divs[divs.size() - 1] / n;
		for(int j = 1; j < n; j++) for(int k = 0; k <= sp; k++) f[j][k] = false;
		equalaverage(a, n, sp);
		for(auto it = divs.begin(); it != divs.end(); it++){
			int y = *it, sp = s * y / n;
			if(f[y][sp]){
				for(; y > 0; sp -= a[sol[y][sp]], y--) subset.push_back(a[sol[y][sp]]);
				break;
			}
		}
		for(int j = subset.size() - 1; j >= 0; j--) cout << subset[j] << " ";
		cout << "\n";
		divs.clear();
		subset.clear();
	}
	return 0;
}