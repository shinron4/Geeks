#include <iostream>

#define MOD 1000000007

using namespace std;

int str(int n){
	long long int dp0[n], dp1[n];
	dp0[0] = 1;
	dp1[0] = 1;
	for(int i = 1; i < n; i++){
		dp0[i] = (dp0[i - 1] + dp1[i - 1]) % MOD;
		dp1[i] = dp0[i - 1];
	}
	return (dp0[n - 1] + dp1[n - 1]) % MOD;
}

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << str(n) << "\n";
	}
	return 0;
}