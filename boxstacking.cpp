#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int acmp(pair<int, int> &a, pair<int, int> &b){
	return a.first * a.second - b.first * b.second;
}

struct COMP{
	bool operator()(pair< pair<int, int>, int > &p, pair< pair<int, int>, int > &q){
		return acmp(p.first, q.first) > 0; 
	}

} compare;

int maxHeight(int h[],int w[],int l[],int n){
	vector< pair< pair<int, int>, int > > base;
	for(int j = 0; j < n; j++){
		base.push_back(make_pair(make_pair(max(h[j], w[j]), min(h[j], w[j])), l[j]));
		base.push_back(make_pair(make_pair(max(h[j], l[j]), min(h[j], l[j])), w[j]));
		base.push_back(make_pair(make_pair(max(l[j], w[j]), min(l[j], w[j])), h[j]));
	}
	sort(base.begin(), base.end(), compare);
	int dp[3 * n], m = -INT_MAX;
	dp[0] = base[0].second;
	for(int i = 1; i < 3 * n; i++){
		dp[i] = base[i].second;
		for(int j = i - 1; j >= 0; j--){
			if(base[j].first.first > base[i].first.first && base[j].first.second > base[i].first.second){ 
				dp[i] = max(dp[i], dp[j] + base[i].second);
			}
		}
		m = max(m, dp[i]);
	}
	return m;
}

int main(){
	int t, n, h[100], w[100], l[100];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> h[j] >> w[j] >> l[j];
		cout << maxHeight(h, w, l, n) << "\n";
	}
	return 0;
}