#include <iostream>

using namespace std;

int trailing(int n){
	int z = 0;
	for(int i = 5; n / i >= 1; i *= 5) z += n / i;
	return z;
}

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << trailing(n) << "\n";
	}
	return 0;
}