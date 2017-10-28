#include <iostream>

using namespace std;

int maxsum(int a[], int n){
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = a[0];
    for(int i = 2; i <= n; i++){
        dp[i] = max(dp[i - 2] + a[i - 1], dp[i - 1]);
    }
    return dp[n];
}

int main() {
	int t, n, a[1000];
	cin >> t;
	while(t--){
	    cin >> n;
	    for(int i = 0; i < n; i++) cin >> a[i];
	    cout << maxsum(a, n) << "\n";
	}
	return 0;
}