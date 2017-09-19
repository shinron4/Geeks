#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t, n, A[200], F[1001], sum;
	bool f;
	for(int j = 0; j < 1001; j++) F[j] = 0;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> sum;
		for(int j = 0; j < n; j++) cin >> A[j];
		for(int j = 0; j < n; j++) F[A[j]]++;
		sort(A, A + n);
		f = false;
		for(int j = 0; j < n; j++){
			for(int k = j + 1; k < n; k++){
				F[A[j]] -= 1;
				F[A[k]] -= 1;
				if(A[j] + A[k] < sum && sum - A[j] - A[k] < 1000 && F[sum - A[j] - A[k]] > 0) f = true;
				F[A[j]] += 1;
				F[A[k]] += 1;
			}
			if(f) break;
		}
		cout << f << "\n";
		for(int j = 0; j < n; j++) F[A[j]]--;
	}
	return 0;
}