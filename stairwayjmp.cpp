#include <iostream>
#include <climits>

using namespace std;

int A[1000], B[1000], k, p;

int jump(int n){
	int dpa[n], dpb[n];
	dpa[0] = A[0];
	dpb[0] = B[0];
	for(int i = 1; i < n; i++){
		dpa[i] = dpb[i] = INT_MAX;
		for(int j = i - 1; j >= 0; j--){
			if(j + k >= i){
				dpa[i] = min(min(dpa[j], dpb[j] + p) + A[i], dpa[i]);
				dpb[i] = min(min(dpb[j], dpa[j] + p) + B[i], dpb[i]);
			}
		}
	}
	return min(dpa[n - 1], dpb[n - 1]);
}

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k >> p;
		for(int j = 0; j < n; j++) cin >> A[j];
		for(int j = 0; j < n; j++) cin >> B[j];
		cout << jump(n) << "\n";
	} 
		return 0;
}