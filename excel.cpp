#include <iostream>
#include <cmath>

using namespace std;

char str[50];
int main(){
	int t, n, x, p;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		p = (int)ceil((log(n * 25 / 26.0 + 1)/log(26.0)));
		x = n - 1 - 26 * (pow(26, p - 1) - 1)/25;
		for(int j = p - 1; j >= 0; j--){
			str[j] = 'A' + x % 26;
			x /= 26;
		}
		for(int j = 0; j < p; j++) cout << str[j];
		cout << "\n";
	}
	return 0;
}