#include <iostream>
#include <cstring>

using namespace std;

int way2decode(char s[], int n){
	int dp[n][n];
	for(int i = 0; i < n; i++) dp[i][i] = (s[i] != '0' ? 1 : 0);
	for(int l = 2; l <= n; l++){
		for(int p = 0; p <= n - l; p++){
			int q = p + l - 1, mid = (p + q) >> 1, l, r, t;
			dp[p][q] = 0;
			l = (mid - p) > 0 ? dp[p][mid - 1] : 1;
			r = (q - mid) > 0 ? dp[mid + 1][q] : 1;
			dp[p][q] += l * r * (s[mid] != '0' ? 1 : 0);
			t = r;
			if(mid + 1 <= q){
				r = (q - mid - 1) > 0 ? dp[mid + 2][q] : 1;
				int m = (s[mid] - '0') * 10 + (s[mid + 1] - '0');
				dp[p][q] += l * r * (m >= 10 && m <= 26 ? 1 : 0); 
			}
			r = t;
			if(mid - 1 >= p){
				l = (mid - p - 1) > 0 ? dp[p][mid - 2] : 1;
				int m = (s[mid - 1] - '0') * 10 + (s[mid] - '0');
				dp[p][q] += l * r * (m >= 10 && m <= 26 ? 1 : 0);
			}
		}
	}
	return dp[0][n - 1];
}

int main(){
	int t, n;
	char d[1000000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> d;
		cout << way2decode(d, n) << "\n";
	}
	return 0;
}