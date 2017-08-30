#include <iostream>
#include <cmath>

using namespace std;

int search(int A[], int i, int j, int x){
	int mid;
	while(i < j){
		mid = ceil((i + j) / 2.0);
		if(x >= A[mid]) i = mid;
		else j = mid - 1;
	}
	return j;
}

int A[1000], B[1000];
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		int n, m, kth;
		cin >> n >> m >> kth;
		for(int j = 0; j < n; j++) cin >> A[j];
		for(int j = 0; j < m; j++) cin >> B[j];
		int mid, p = 0, q = n - 1, r;
		while(p < q){
			mid = (p + q) >> 1;
			r = search(B, 0, m - 1, A[mid]);
			r = A[mid] >= B[r] ? r : r - 1;
			if(kth <= mid + r + 2) q = mid;
			else p = mid + 1;
		}
		r = search(B, 0, m - 1, A[p]);
		r = A[p] >= B[r] ? r : r - 1;
		if(kth < p + r + 2) p--;
		r = kth - p - 2;
		if(p < 0) cout << B[r];
		else if(r < 0) cout << A[p];
		else if(A[p] < B[r]) cout << B[r];
		else cout << A[p];
		cout << "\n";
	}
	return 0;
}