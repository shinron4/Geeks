#include <iostream>

using namespace std;

int main() {
	long long int t, n, a[1000];
	cin >> t;
	while (t--){
	    cin >> n;
	    int p2 = 0, p5 = 0, mi;
	    for(int i = 0; i < n; i++){
	        cin >> a[i];
	        long long int x = a[i];
	        if(x != 0){
    	        while(x % 5 == 0){
    	            x /= 5;
    	            p5++;
    	        }
    	        while(!(x & 1)){
    	            x >>= 1;
    	            p2++;
    	        }
	        }
	    }
	    mi = min(p2, p5);
	    int d2 = 0, d5 = 0;
	    for(int i = 0; i < n; i++){
	        if(a[i] != 0){
    	        while(d5 < mi && a[i] % 5 == 0){
    	            a[i] /= 5;
    	            d5++;
    	        }
    	        while(d2 < mi && !(a[i] & 1)){
    	            a[i] >>= 1;
    	            d2++;
    	        }
	        }
	    }
	    long long int l = 1;
	    for(int i = 0; i < n; i++) l = (a[i] * l) % 10;
	    cout << l << "\n";
	}
	return 0;
}