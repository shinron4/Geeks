#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int find_mid(int A[], int l, int r){
	sort(A + l, A +  r + 1);
	return A[(l + r) >> 1];
}

int partition(int A[], int n, int x){
	int j = -1, idx;
	for(int i = 0; i < n; i++){
		if(A[i] < x){
			j++;
			swap(A[i], A[j]);
		}
		else if(A[i] == x){
			j++;
			swap(A[i], A[j]);
			idx = j;
		}
	}
	swap(A[idx], A[j]);
	return j;
}

int select(int A[], int n, int k){
	int mom;
	if(n > 1){
		int m = ceil(n/5.0), B[m];
		for(int i = 0; i < n; i += 5) B[i/5] = find_mid(A, i, i + 4 < n ? i + 4 : n - 1);
		mom = select(B, m, ceil(m / 2.0));
	}
	else return A[0];
	int m = partition(A, n, mom) + 1, B[max(m, n - m)];
	if(k < m){
		for(int i = 0; i < m - 1; i++) B[i] = A[i];
		return select(B, m - 1, k);
	}
	else if(k == m) return mom;
	else{
		k -= m;
		for(int i = m; i < n; i++) B[i - m] = A[i];
		return select(B, n - m, k);
	}
}

int A[1000];
int main(){
	int t, n, k, x;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int j = 0; j < n; j++) cin >> A[j];
		x = select(A, n, n - k + 1);
		int j = n;
		for(int l = n - 1; l >= 0; l--){
			if(A[l] >= x){
				j--;
				swap(A[j], A[l]);
			}
		}
		sort(A + j, A + n);
		for(int l = n - 1; l >= n - k; l--) cout << A[l] << " ";
		cout << "\n";
	}
	return 0;
}