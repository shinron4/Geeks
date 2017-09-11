#include <iostream>
#include <vector>

using namespace std;

vector< vector< pair <int, int> > > interval(101);
int maxstock(int A[], int n){
	int dp[101];
	dp[0] = dp[1] = 0;
	for(int i = 2; i <= n; i++){
		int m = -INT_MAX, p;
		for(int l = 1; l < i; l++){
			if(A[i - 1] - A[l - 1] + dp[l] > m){
				m = A[i - 1] - A[l - 1] + dp[l];
				p = l;
			}
		}
		if(m > dp[i - 1]){
			for(int l = 0; l < interval[p].size(); l++){
				interval[i].push_back(interval[p][l]);
			}
			interval[i].push_back(make_pair(p, i));
		}
		else{
			for(int l = 0; l < interval[i - 1].size(); l++){
				interval[i].push_back(interval[i - 1][l]);
			}
		}
		dp[i] = max(m, dp[i - 1]); 
	}
	return dp[n];
}

int main(){
	int t, n, A[100];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		if(maxstock(A, n) == 0){
			cout << "No Profit";
		}
		else{
			for(int j = 0; j < interval[n].size(); j++){
				cout << "(" << (interval[n][j].first - 1) << " " << (interval[n][j].second - 1) << ") ";
			}
		}
		cout << "\n";
		for(int j = 0; j <= n; j++) interval[j].clear();
	}
	return 0;
}