#include <iostream>

using namespace std;

int altseq(int A[], int n){
	int S[n], L[n], m = 1;
	S[0] = L[0] = 1;
	for(int i = 1; i < n; i++){
		S[i] = L[i] = 1; 
		for(int j = i - 1; j >= 0; j--){
			if(A[i] > A[j]) L[i] = max(L[i], S[j] + 1);
			else if(A[i] < A[j]) S[i] = max(S[i], L[j] + 1);
		}
		m = max(max(S[i], L[i]), m);
	}
	return m;
}

int main(){
	int t, n, A[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		cout << altseq(A, n) << "\n";
	}
	return 0;
}