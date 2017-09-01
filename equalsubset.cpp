#include <iostream>

using namespace std;

int A[100], V[100];
int B[2][100001];

int knapsack(int n, int W){
	for(int i = 0; i <= W; i++) B[0][i] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= W; j++){
			B[1][j] = max((j - A[i - 1] >= 0 ? B[0][j - A[i - 1]] + V[i - 1]: B[1][j - 1]), B[0][j]);
		}
		for(int j = 1; j <= W; j++) B[0][j] = B[1][j];
	}
	return B[1][W];
}

int main(){
	int t, n, sum;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		sum = 0;
		for(int j = 0; j < n; j++){
			cin >> A[j];
			sum += (V[j] = A[j]);
		}
		if(sum & 1) cout << "NO";
		else cout << (knapsack(n, sum >> 1) == sum >> 1 ? "YES" : "NO");
		cout << "\n";
	}
	return 0;
}