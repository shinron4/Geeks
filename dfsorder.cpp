#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

vector< vector<int> > G(1000);
long long int fact[1001];

long long int dfsorder(int u){
	long long int p = 1;
	int sum = 0;
	for(int i = 0; i < G[u].size(); i++){
		int v = G[u][i];
		p = (p * dfsorder(v)) % MOD;
		sum++;
	}
	p = (p * fact[sum]) % MOD;
	return p;
}

int main(){
	int t, n;
	fact[0] = fact[1] = 1;
	for(int i = 2; i <= 1000; i++) fact[i] = (fact[i - 1] * i) % MOD;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			if(j > 0) G[x - 1].push_back(j);
		}
		cout << dfsorder(0) << "\n";
		for(int j = 0; j < n; j++) G[j].clear();
	}
	return 0;
}
