#include <iostream>

using namespace std;

int main(){
	int t, n;
	long long int A[100000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
	    long long int sum = 0;
	    for(long long int m = 1; m <= (1l << 32); m <<= 1){
	        int x, y;
	        x = 0;
	        for(int j = 0; j < n; j++){
	            if((m & A[j])) x++;
	        }
	        y = n - x;
	        sum = (sum + 2 * x * y) % 1000000007;
	    }
	    cout << sum << "\n";
	}
	return 0;
}