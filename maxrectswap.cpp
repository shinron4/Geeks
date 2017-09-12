#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
	int t, r, c, x, B[15][15];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> r >> c;
		for(int j = 0; j < r; j++){
			for(int k = 0; k < c; k++){
				cin >> x;
				B[j][k] = x + (j > 0 ? B[j - 1][k] : 0);
				if(j > 0 && B[j - 1][k] == B[j][k]) B[j][k] = 0;
			}
		}
		for(int j = 0; j < r; j++) sort(B[j], B[j] + c);
		int m = -INT_MAX;
		for(int j = 0; j < r; j++) for(int k = 0; k < c; k++){
				if(B[j][k] * (c - k) > m) m = B[j][k] * (c - k);
		}
		cout << m << "\n";
	}
	return 0;
}