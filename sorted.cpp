#include <iostream>

using namespace std;

int search(int n, int a[], int x){
	int i = 0;
	while(i < n - 1 && a[i] <= a[i + 1]) i++;
	int l = (i + 1) % n, r = l + n - 1, mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(x <= a[mid % n]) r = mid;
		else l = mid + 1;
	}
	return x < a[l % n] ? -1 : l % n;
}

int main(){
	int t, n, a[100000], x;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> a[j];
		cin >> x;
		cout << search(n, a, x) << "\n"; 
	}
	return 0;
}