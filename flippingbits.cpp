#include <iostream>

using namespace std;

int A[10000002];

long long int get(int i){
	long long int sum = 0;
	while(i > 0){
		sum += A[i];
		i -= i & -i;
	}
	return sum;
}

void set(int n, int i, int val){
	while(i <= n){
		A[i] += val;
		i += i & -i;
	}
}

int main(){
	int t, n, f[16];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < 16; j++) f[j] = 0;
		for(int j = 0; j < n; j++){
			int l, r;
			cin >> l >> r;
			set(10000001, l, 1);
			set(10000001, r + 1, -1);
		}
		for(int j = 1; j < 10000000; j += 4){
			int m = 8, h = 0;
			for(int k = j; k < j + 4; k++){
				h = h | (get(k) % 2 ? m : 0);
				m >>= 1;
			}
			if(h > 0) cout << j << " " << h << "\n";
			f[h]++;
		}
		for(int j = 0; j < 16; j++) cout << f[j] << " ";
		cout << "\n";
		for(int j = 0; j < 10000000; j++) A[j] = 0;
	}
}