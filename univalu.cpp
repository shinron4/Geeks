#include <iostream>
#include <vector>

using namespace std;

int val[30000], color[30000];

vector< vector<int> > G(30000);

pair<int, int> univalue(int u){
	bool f = true;
	int sum = 0, t, p = 0;
	pair<int, int> sub;
	for(int j = 0; j < G[u].size(); j++) if(color[G[u][j]] == 0) sum++;
	if(sum == 0) return make_pair(val[u], 1);
	sum = 0;
	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(color[v] == 0){
			color[v] = 1;
			sub = univalue(v);
			if(p == 0){
				t = sub.first;
				p++;
			}
			else if(t != sub.first) f = false;
			sum += sub.second;
			color[v] = 0;
		}
	}
	if(f){
		return t == val[u] ? make_pair(t, sum + 1) : make_pair(INT_MAX, sum);
	}
	else{
		return make_pair(INT_MAX, sum);
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> val[i];
	for(int i = 0; i < n; i++) color[i] = 0;

	for(int i = 0; i < n - 1; i++){
		int u ,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}	
	color[0] = 1;
	pair<bool, int> sub = univalue(0);
	color[0] = 0;
	cout << sub.second << "\n";
	return 0;
}