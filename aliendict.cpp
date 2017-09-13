#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector< vector<int> > G(26);

int color[26], sortseq[26], p;

void visit(int u){
	color[u] = 1;
	for(int j = 0; j < G[u].size(); j++){
		int v = G[u][j];
		if(color[v] == 0) visit(v);
	}
	sortseq[--p] = u;
}

void dfs(){
	for (int i = 0; i < 26; i++) if(color[i] == 0) visit(i);
}

string printOrder(string dict[], int n, int k){
	bool sw[26];
	char s[26];
	for(int j = 0; j < 26; j++){
		color[j] = (sw[j] = false);
		G[j].clear();
	}
	p = 26;
	for(int j = 0; j < n; j++){
		int k = 0;
		while(dict[j][k] != '\0') sw[dict[j][k++] - 'a'] = true;
	}
	for(int j = 0; j < n - 1; j++){
		int m = min(dict[j].length(), dict[j + 1].length()), k = 0;
		while(k < m && dict[j][k] == dict[j + 1][k]) k++;
		if(k < m) G[dict[j][k] - 'a'].push_back(dict[j + 1][k] - 'a');
	}
	dfs();
	for(int j = 25; j >= 0; j--) if(sw[sortseq[j]]) s[--k] = (char)(sortseq[j] + 'a');
	return string(s);
}

int main(){
	int t, n, k;
	string dict[100];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int j = 0; j < n; j++) cin >> dict[j];
		cout << printOrder(dict, n, k) << "\n";
	}
	return 0;
}