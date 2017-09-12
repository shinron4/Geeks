#include <iostream>
#include <stack>
#include <climits>

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
	int t, n, hist[102];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		hist[0] = hist[n + 1] = 0;
		for(int j = 1; j <= n; j++) cin >> hist[j];
		cout << maxarea(hist, n + 2) << "\n";
	}
	return 0;
}