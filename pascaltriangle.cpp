#include <iostream>

using namespace std;

long long int c[201][201];

int main(){
	for(int i = 0; i < 201; i++) c[i][0] = c[i][i] = 1;
	for(int i = 2; i < 201; i++){
		for(int j = 1; j < i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
	}
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		cout << c[n + m - 2][m - 1] << "\n"; 
	}

}