#include <iostream>

using namespace std;

int main(){
	int t, n, A[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			cin >> A[j];
			A[j] += j;
		}
		int max = 0, j = 1, newmax = A[0], jmp = 1;
		while(newmax > max && newmax < n - 1){
			max = newmax;
			jmp++;
			for(; j <= max; j++) if(A[j] > newmax) newmax = A[j];
		}
		cout << (newmax < n - 1 ? -1 : jmp) << "\n";

	}
	return 0;
}