#include <iostream>

using namespace std;

void visit(int A[][100], int color[][100], int n, int m, int i, int j){
	color[i][j] = 1;
	for(int u = i - 1; u < i + 2; u++){
		for(int v = j - 1; v < j + 2; v++){
			if(u < 0 || u > n - 1 || v < 0 || v > m - 1 || A[u][v] != 1 || color[u][v] != 0) continue;
			else{
				visit(A, color, n, m, u, v);
			}
		}
	}
	color[i][j] = 2;
}

int findIslands(int A[][100], int n, int m){
	int color[100][100], count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			color[i][j] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(A[i][j] == 1 && color[i][j] == 0){
				visit(A, color, n, m, i, j);
				count++;
			}
		}
	}
	return count;
}

int A[100][100];

int main(){
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				cin >> A[j][k];
			}
		}
		cout << findIslands(A, n, m) << "\n";
	}
	return 0;
}