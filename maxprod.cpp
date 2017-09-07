#include <iostream>

using namespace std;

long long int A[1000], B[1000], dp[1001][1001];
long long int MaxDotProduct(int m, int n)
{
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=n; i++)
        for (int j=i; j<=m; j++) 
            dp[i][j] = max((dp[i-1][j-1] + (A[j-1]*B[i-1])) ,dp[i][j-1]);
 
    return dp[n][m] ;
}

int main(){
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		for(int j = 0; j < n; j++) cin >> A[j];
		for(int j = 0; j < m; j++) cin >> B[j];
		cout << MaxDotProduct(n, m) << "\n";
	}
	return 0;
}