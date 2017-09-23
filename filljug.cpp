#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int filljug(int m, int n, int d){
	int r = m + 1, c = n + 1, dist[r][c];
	bool state[r][c];
	queue< pair<int, int> >q;

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			state[i][j] = false;
			dist[i][j] = INT_MAX;
		}
	}
	q.push(make_pair(0, 0));
	state[0][0] = true;
	dist[0][0] = 0;
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		if(x == d || y == d) return dist[x][y];
		q.pop();
		if(state[0][y] == false){
			q.push(make_pair(0, y));
			state[0][y] = true;
			dist[0][y] = dist[x][y] + 1;
		}
		if(state[x][0] == false){
			q.push(make_pair(x, 0));
			state[x][0] = true;
			dist[x][0] = dist[x][y] + 1;
		}
		if(x < m && state[m][y] == false){
			q.push(make_pair(m, y));
			state[m][y] = true;
			dist[m][y] = dist[x][y] + 1;
		}
		if(y < n && state[x][n] == false){
			q.push(make_pair(x, n));
			state[x][n] = true;
			dist[x][n] = dist[x][y] + 1;
		}
		if(state[x - min(x, n - y)][y + min(x, n - y)] == false){
			q.push(make_pair(x - min(x, n - y), y + min(x, n - y)));
			state[x - min(x, n - y)][y + min(x, n - y)] = true;
			dist[x - min(x, n - y)][y + min(x, n - y)] = dist[x][y] + 1;
		}
		if(state[x + min(y, m - x)][y - min(y, m - x)] == false){
			q.push(make_pair(x + min(y, m - x), y - min(y, m - x)));
			state[x + min(y, m - x)][y - min(y, m - x)] = true;
			dist[x + min(y, m - x)][y - min(y, m - x)] = dist[x][y] + 1;
		}
	}
	return -1;
}

int main(){
	int t, n, m, d;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> m >> n >> d;
		cout << filljug(m, n, d) << "\n";
	}
}