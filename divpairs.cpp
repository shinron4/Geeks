#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int A[100000], B[100000];

int main(){
	int t, n, k, sum;
	bool f;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		sum = 0;
		for(int j = 0; j < n; j++){
			cin >> A[j];
			sum += A[j];
		}
		cin >> k;
		f = true;
		memset(B, '\0', 4 * k);
		for(int j = 0; j < n; j++) B[A[j] % k]++;
		if(n & 1) f = false;
		else if(sum % k != 0) f = false;
		else if(B[0] & 1) f = false;
		else{
			for(int j = 1; j < (k >> 1); j++) if(B[j] != B[k - j]) f = false;
			if((k & 1) == 0 && B[k >> 1] & 1) f = false;
			else if(k & 1) if((k >> 1) + 1 < k && B[k >> 1] != B[(k >> 1) + 1]) f = false;
		}
		cout << (f ? "True" : "False") << "\n";
	}
	return 0;
}