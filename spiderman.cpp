#include <iostream>
#include <queue>

using namespace std;

int grid[100][100], r[100][100], dist[100][100];

class compare{
public:
	bool operator()(pair<int, pair<int, int> > p, pair<int, pair<int, int> > q){
		return p.first > q.first;
	}
};

priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, compare > qu;

void dijkstra(int u, int v, int n, int m, int d){
	qu.push(make_pair(0, make_pair(u, v)));
	while(!qu.empty()){
		pair< int, pair<int, int> > pa = qu.top();
		qu.pop();
		int p = pa.second.first, q = pa.second.second;
		if(r[p][q] == 0){
			r[p][q] = 1;
			dist[p][q] = pa.first;
			if(p - 1 >= 0 && r[p - 1][q] == 0 && abs(grid[p][q] - grid[p - 1][q]) <= d){
				if(dist[p][q] + 1 < dist[p - 1][q]){
					dist[p - 1][q] = dist[p][q] + 1;
					qu.push(make_pair(dist[p - 1][q], make_pair(p - 1, q)));
				}
			}
			if(p + 1 < n && r[p + 1][q] == 0 && abs(grid[p][q] - grid[p + 1][q]) <= d){
				if(dist[p][q] + 1 < dist[p + 1][q]){
					dist[p + 1][q] = dist[p][q] + 1;
					qu.push(make_pair(dist[p + 1][q], make_pair(p + 1, q)));
				}
			}
			if(q - 1 >= 0 && r[p][q - 1] == 0 && abs(grid[p][q] - grid[p][q - 1]) <= d){
				if(dist[p][q] + 1 < dist[p][q - 1]){
					dist[p][q - 1] = dist[p][q] + 1;
					qu.push(make_pair(dist[p][q - 1], make_pair(p, q - 1)));
				}
			}
			if(q + 1 < m && r[p][q + 1] == 0 && abs(grid[p][q] - grid[p][q + 1]) <= d){
				if(dist[p][q] + 1 < dist[p][q + 1]){
					dist[p][q + 1] = dist[p][q] + 1;
					qu.push(make_pair(dist[p][q + 1], make_pair(p, q + 1)));
				}
			}
		}
	}
}

int main(){
	int t, n, m, x, y, d;
	cin >> t;
	for(int i = 0 ; i < t; i++){
		cin >> n >> m >> x >> y >> d;
		x--; y--;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				cin >> grid[j][k];
				r[j][k] = 0;
				dist[j][k] = INT_MAX;
			}
		}
		dijkstra(0, 0, n, m, d);
		cout << (dist[x][y] < INT_MAX ? dist[x][y] : -1) << "\n";
	}
	return 0;
}