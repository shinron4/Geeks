#include <iostream>

using namespace std;

int subsetsum(int A[], int n, int sum){
	long long int dp[sum + 1];
	for(int i = 0; i <= sum; i++) dp[i] = 0;
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = sum - A[i]; j >= 0; j--) dp[A[i] + j] += dp[j];
	}
	return dp[sum];
}

int main(){
	int t, n, A[100000], sum;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		cin >> sum;
		cout << subsetsum(A, n, sum) << "\n";
	}
	return 0;
}