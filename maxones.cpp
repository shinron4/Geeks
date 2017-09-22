#include <iostream>
#include <climits>

using namespace std;

int A[10000], B[10000];

int maxsubarray(int A[], int n){
    int dp[n], c = 0;
    dp[0] = A[0];
    c = max(c, dp[0]);
    for(int j = 1; j < n; j++){
        dp[j] = max(dp[j - 1] + A[j], A[j]);
        c = max(c, dp[j]);
    }
    return c;
}

int main() {
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
	    cin >> n;
	    for(int j = 0; j < n; j++) cin >> A[j];
	    int k = 0, sum = 0, j = 0;
	    while(j < n){
	        int val = A[j], s = 1;
	        j += 1;
	        while(j < n && A[j] == val){
	            s++; j++;
	        }
	        B[k++] = val == 0 ? s : -1 *s;
	    }
	    for(int j = 0; j < n; j++) if(A[j] == 1) sum++;
	    cout << maxsubarray(B, k) + sum << "\n";
	}
	return 0;
}