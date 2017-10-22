#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
 
int candy(vector<int> &ratings){
	vector< pair<int, int> > v;
	int n = ratings.size(), candies[n], tot = 0;
	for(int i = 0; i < n; i++){
		v.push_back(make_pair(ratings[i], i));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		int idx = v[i].second;
		bool l = idx == 0 || ratings[idx - 1] >= v[i].first ? true : false;
		bool r = idx == n - 1 || ratings[idx + 1] >= v[i].first ? true : false;
		if(l && r) tot += (candies[idx] = 1);
		else if(!l && !r) tot += (candies[idx] = max(candies[idx - 1], candies[idx + 1]) + 1);
		else if(!l) tot += (candies[idx] = candies[idx - 1] + 1);
		else tot += (candies[idx] = candies[idx + 1] + 1);
	}
	return tot;
}

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> a(n);
		for(int j = 0; j < n; j++) cin >> a[j];
		cout << candy(a) << "\n";
	} 
	return 0;
}