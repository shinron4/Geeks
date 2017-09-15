#include <iostream>

using namespace std;


int main(){
	long long int mults[4][6] = {{2, 3, 5, 7, 0, 0}, {6, 10, 14, 15, 21, 35}, {30, 42, 70, 105, 0, 0}, {210, 0, 0, 0, 0, 0}};
	int t, coff[4] = {4, 6, 4, 1};
	long long int n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		long long int sum = 0;
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < coff[j]; k++){
				long long int q = n / mults[j][k];
				if(j & 1) sum -= q;
				else sum += q;
			}
		}
		cout << n - sum << "\n";
	}
	return 0;
}