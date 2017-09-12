#include <iostream>
#include <climits>
#include <stack>

using namespace std;

int maxarea(int A[], int n){
	stack<int> s;
	int left[n], right[n];
	s.push(0);
	for(int j = 0; j < n; j++) cout << A[j] << " ";
	cout << "\n";
	for(int j = 1; j < n; j++){
		while(A[j] < A[s.top()]){
			right[s.top()] = j;
			s.pop();
		}
		left[j] = (A[j] == A[s.top()] ? left[s.top()] : s.top());
		s.push(j);
	}
	while(!s.empty()) s.pop();
	int m = -INT_MAX;
	for(int j = 1; j < n; j++){
		if((right[j] - 1 - left[j]) * A[j] > m) m = (right[j] - 1 - left[j]) * A[j];
	}
	return m;
}

int main(){
	int t, r, c, x, B[52][52];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> r >> c;
		for(int j = 0; j < r; j++) B[j][0] = B[j][c + 1] = 0;
		for(int j = 0; j < r; j++) for(int k = 1; k <= c; k++){
			cin >> x;
			B[j][k] = x + (j > 0 ? B[j - 1][k] : 0);
			if(j > 0 && B[j][k] == B[j - 1][k]) B[j][k] = 0;
		}
		int m = -INT_MAX;
		for(int j = 0; j < r; j++) m = max(maxarea(B[j], c + 2), m);
		cout << m << "\n";
	}
	return 0;
}