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
	long long int tot = 0
	for(int i = 0; i < n; i++) tot += (dp0[i] + dp1[i]) % MOD; 
	return tot;
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