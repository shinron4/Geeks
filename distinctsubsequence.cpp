#include <iostream>
#define MAXCHAR 256

using namespace std;

long long int countdistinct(char s[]){
	int n = strlen(s), l[MAXCHAR];
	for(int i = 0; i < MAXCHAR; i++) l[i] = -1;
	int dp[n + 1];
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		dp[i] = dp[i - 1] << 1;
		if(l[s[i - 1]] != -1){
			dp[i] -= dp[l[s[i - 1]]];
		}
		l[s[i - 1]] = i - 1;
	}
	return dp[n];
}
int main(){
	int t, n;
	char s[1000];
	cin >> t;
	while(t--){
		cin >> s;
		cout << countdistinct(s) << "\n";
	}
	return 0;
}