#include <iostream>

using namespace std;

int squareroot(int n){
	long long int t, m = n;
	long long int mid, i = 1, j = n;
	while(i < j){
		mid = (i + j) >> 1;
		cout << i << " " << mid << " " << j << "\n";
		t = mid * mid;
		if(t < m) i = mid + 1;
		else j = mid;
	}
	return i * i > m ? --i : i;
}

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << squareroot(n) << "\n";
	}
	return 0;
}