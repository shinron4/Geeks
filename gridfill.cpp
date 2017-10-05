#include <iostream>

using namespace std;

int main(){
	int t, n;
	long long int c[81][81], s;
	c[0][0] = 1;
	for(int i = 1; i <= 80; i++){
		c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; j++){
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		int q = n >> 2;
		s = 0;
		for(int j = 0; j <= q; j++) s += c[n - 3 * j][j];
		cout << s << "\n";
	}
	return 0;
}