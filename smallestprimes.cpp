#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class compare{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.first > b.first;
		}
};

vector<int> solve(int l, int m, int n, int k) {
	vector<int> s, p;
	p.push_back(l);
	p.push_back(m);
	p.push_back(n);
	sort(p.begin(), p.end());
	if(p[0] == p[1]){
		p.erase(p.begin());
		if(p[0] == p[1]) p.erase(p.begin());
	}
	else if(p[1] == p[2]) p.erase(p.begin() + 1);
	priority_queue< pair<int, int>, vector< pair<int, int> >, compare > q;
	q.push(make_pair(1, 0));
	k++;
	while(k){
		int u = q.top().first, j = q.top().second;
		q.pop();
		s.push_back(u);
		k--;
		for(int i = 0; i < p.size(); i++){
			if(p[i] >= j){
				q.push(make_pair(u * p[i], p[i]));
			}
		}
	}
	s.erase(s.begin());
	return s;
}

int main(){
	int t, l, m, n, k;
	vector<int> s;
	cin >> t;
	while(t--){
		cin >> l >> m >> n >> k;
		s = solve(l, m, n, k);
		for(int i = 0; i < s.size(); i++) cout << s[i] << " ";
		cout << "\n";
	}
	return 0;
}