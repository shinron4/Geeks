#include <iostream>
#include <cstring>

using namespace std;

int A[1000], B[1000];
char str[1000];

int main(){
	int t,n ;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> str;
		n = strlen(str);
		for(int j = 0; j < n; j++) B[j] = (A[j] = str[j] - '0') + (j > 0 ? B[j - 1] : 0);		
		int len = 0;
		for(int l = 2; l <= n; l += 2){
			for(int p = 0; p <= n - l; p++){
				int q = p + l - 1, mid = (p + q) >> 1;
				int tot = B[q] - (p > 0 ? B[p - 1] : 0), left = B[mid] - (p > 0 ? B[p - 1] : 0);				
				if(left == tot - left) len = l;
			}
		}
		cout << len << "\n";
	}
	return 0;
}