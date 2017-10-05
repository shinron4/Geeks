#include <iostream>

#define MOD 1000000007

using namespace std;

int numchords(int n){
    long long int c[n + 1];
    c[0] = c[1] = 1;
    for(int i = 2; i <= n; i++){
        c[i] = 0;
        for(int j = 0; j <= i - 1; j++){
            c[i] = (c[i] + (c[j] * c[i - j - 1]) % MOD) % MOD; 
        }
    }
    return c[n];
}

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << numchords(n) << "\n";
	}
	return 0;
}