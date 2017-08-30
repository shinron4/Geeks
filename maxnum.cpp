#include <iostream>
#include <algorithm>

using namespace std;

int lexgrap(int i, int j){
	char ni[100], nj[100];
	int p = 0, q = 0;
	sprintf(ni, "%d%d", i, j);
	sprintf(nj, "%d%d", j, i);
	while(ni[p] != '\0' && nj[q] != '\0'){
		if(ni[p] != nj[q]) return ni[p] - nj[q];
		p++;
		q++;
	}
	return 0;
}

struct COMP{
	bool operator()(int i, int j){
		return lexgrap(i, j) >= 0;
	}
} compare;

int main(){
	int t, n, A[100];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		sort(A, A + n, compare);
		for(int j = 0; j < n; j++) cout << A[j];
		cout << "\n";
	}
	return 0;
}