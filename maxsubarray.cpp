#include <iostream>
#include <climits>

using namespace std;

int A[1001], C[1001];

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 1; j <= n; j++) cin >> A[j];
		C[0] = -1000000;
		int max_sum = -1000000;
		for(int j = 1; j <= n; j++){
			C[j] = C[j - 1] + A[j] >= A[j] ? C[j - 1] + A[j] : A[j];
			max_sum = max(C[j], max_sum); 
		}
		cout << max_sum << "\n";
	}
	return 0;
}