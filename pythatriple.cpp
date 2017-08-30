#include <iostream>
#include <vector>

using namespace std;

int A[1000];

int main(){
	int t, n, x;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		sort(A, A + n);
		int B[1000], k = A[0], l = 0;
		bool f = false;
		B[l] = k;
		for(int j = 1; j < n; j++) if(k != A[j]) k = B[++l] = A[j];
		for(int j = 0; j < l + 1; j++) cout << B[j] << " ";
		cout << "\n";
		for(int p = 0; p < l + 1; p++){
			for(int q = p + 1; q < l + 1; q++){
				for(int r = q + 1; r < l + 1; r++){
					if(B[p] * B[p] + B[q] * B[q] == B[r] * B[r]){
						f = true;						f = true;
						break;
					}
				}
			}
		}
		cout << (f ? "Yes" : "No") << "\n";
	}
	return 0;
}