#include <iostream>
#include <algorithm>

using namespace std;

int A[1000000];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	int a = INT_MAX;
	for(int i = 0; i < n - 1; i++){
		if((A[i] ^ A[i + 1]) < a) a = A[i] ^ A[i + 1];
	}
	cout << a << "\n";
	return 0;
}