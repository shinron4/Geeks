#include <iostream>

using namespace std;

int watertapping(int a[], int n){
	int w = 0, lm[n], rm[n];
	for(int i = 0; i < n; i++){
		lm[i] = max(i == 0 ? -1 : lm[i - 1], a[i]);
		rm[n - i - 1] = max(n - i < n ? rm[n - i] : -1, a[n - i - 1]);
	}
	for(int i = 1; i < n - 1; i++){
		int t = min(lm[i - 1], rm[i + 1]);
		if(t > a[i]) w += (t - a[i]);
	}
	return w;
}

int main(){
	int t, n, a[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> a[j];
		cout << watertapping(a, n) << "\n";
	}
}