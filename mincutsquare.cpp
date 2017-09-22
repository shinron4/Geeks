#include <iostream>
#include <climits>

using namespace std;

int mincut(int a, int b){
	if(a == b) return 1;
	if(a > b && a % b == 0) return a / b;
	else if(a < b && b % a == 0) return b / a;

	int l = max(a, b), s = min(a, b), dp[l][l];
	for(int i = 0; i < l; i++){
		dp[i][0] = i + 1;
		dp[i][i] = 1;
	}
	for(int i = 1; i < l; i++){
		for(int j = 1; j < i; j++){
			if((i + 1) % (j + 1) == 0) dp[i][j] = (i + 1)/(j + 1);
			else{
				int mi = INT_MAX;
				for(int k = 1; k <= (j + 1) >> 1; k++){
					mi = min(mi, (dp[i][k - 1] + dp[i][j - k]));
				}
				for(int k = 1; k <= (i + 1) >> 1; k++){
					mi = min(mi, dp[max(k - 1, j)][min(k - 1, j)] + dp[max(i - k, j)][min(i - k, j)]);
				}
				dp[i][j] = mi;
			}
			 if(i == l - 1 && j == s - 1) return dp[i][j];
		}
	}
}

int main(){
    int t, a, b;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b;
        cout << mincut(a, b) << "\n";
    }
	return 0;
}