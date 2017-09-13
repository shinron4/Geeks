#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
	int t, n, p, A[100], m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		sort(A, A + n);
		p = 1;
		m = -INT_MAX;
		for(int j = 1; j < n; j++){
			if(A[j] == A[j - 1] + 1) p++;
			else{
				m = max(m, p);
				p = 1;
			}
		}
		m = max(m, p);
		cout << m << "\n";
	}
	return 0;
}