#include <iostream>
#include <algorithm>

using namespace std;

int bsearch(int a[], int i, int j, int x){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(x <= a[mid]) j = mid;
		else i = mid + 1;
	}
	return i;
}

bool nextperm(int a[], int n){
	int i = n - 1;
	while(i > 0 && a[i - 1] >= a[i]) i--;
	if(i == 0) return false;
	for(int j = 0; j < (n - i) >> 1; j++) swap(a[j + i], a[n - j - 1]);
	int j = bsearch(a, i, n - 1, a[i - 1]);
	while(a[i - 1] == a[j]) j++;
	swap(a[i - 1], a[j]);
	return true;
}

int main(){
	int t, n, a[100000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> a[j];
		sort(a, a + n);
		for(int j = 0; j < n; j++) cout << a[j] << " ";	
		cout << "\n";	
		while(nextperm(a, n)){
			for(int j = 0; j < n; j++) cout << a[j] << " ";
			cout << "\n";
		}
	}
	return 0;
}