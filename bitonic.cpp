#include <iostream>

using namespace std;

void longest_inc_seq(int A[], int n, int inc[]){
	int dp[n];
	inc[0] = dp[0] = 1;
	for(int i = 1; i <= n; i++){
		int q = 1;
		for(int j = i - 1; j >= 0; j--) if(A[i] > A[j]) q = max(q, dp[j] + 1);
		inc[i] = dp[i] = q;
	}
}

int main(){
	int t, inc[100], dec[100], A[100], n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		longest_inc_seq(A, n, inc);
		for(int j = 0; j < (n >> 1); j++) swap(A[j], A[n - j - 1]);
		longest_inc_seq(A, n, dec);
		int m = -INT_MAX, idx;
		for(int j = 0; j < n; j++) cout << inc[j] << " ";
		cout << "\n";
		for(int j = 0; j < n; j++) cout << dec[n - j - 1] << " ";
		cout << "\n";
		for(int j = 0; j < n; j++){
			if(inc[j] + dec[n - j - 1] - 1 > m){
				m = inc[j] + dec[n - j - 1] - 1;
				idx = j;
			}
		}
			//m = max(m, inc[j] + dec[n - j - 1] - 1);
		cout << m << " "<< idx << "\n";
	}
	return 0;
}