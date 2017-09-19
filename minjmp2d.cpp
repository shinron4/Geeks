#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int minHops(int matrix[64][64], int m, int n){
	int color[n][m], minjmp[n][m];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		color[i][j] = 0;
		minjmp[i][j] = INT_MAX;
	}
	minjmp[0][0] = 0;
	queue< pair<int, int> > q;
	q.push(make_pair(0, 0));
	color[0][0] = 1;
	while(!q.empty()){
		int u = q.front().first, v = q.front().second, b;
		q.pop();
		color[u][v] = 2;
		b = u + matrix[u][v];
		for(int i = u; i <= (b < n - 1 ? b : n - 1); i++){
			if(color[i][v] == 0){
				minjmp[i][v] = minjmp[u][v] + 1;
				q.push(make_pair(i, v));
				color[i][v] = 1;
			}
		}
		b = v + matrix[u][v];
		for(int i = v; i <= (b < m - 1 ? b : m - 1); i++){
			if(color[u][i] == 0){
				minjmp[u][i] = minjmp[u][v] + 1;
				q.push(make_pair(u, i));
				color[u][i] = 1;
			}
		}
	}
	return (minjmp[n - 1][m - 1] < INT_MAX ? minjmp[n - 1][m - 1] + 1: 0);
}

int main(){
	int n, m, A[64][64];
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		cin >> A[i][j];
	}
	cout << minHops(A, n, m) << "\n";
	return 0;
}