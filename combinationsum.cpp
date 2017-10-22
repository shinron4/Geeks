#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector< vector<int> >combinationSum(vector<int> &a, int t){
	vector< vector<int> > subs;
	sort(a.begin(), a.end());
	int n = a.size(), m[n][2], k = 0, j = a[n - 1];
	m[k][1] = n - 1;
	for(int i = n - 2; i >= 0; i--){
		if(a[i] != j){
			m[k++][0] = i + 1;
			j = a[i];
			m[k][1] = i;
		}
	}
	m[k++][0] = 0;
	for(int i = 0; i < 1 << n; i++){
		int s = 0, shift = 0;
		for(int j = 0; j < k; j++){
			int count = 0;
			for(int l = m[j][1]; l >= m[j][0]; l--){
				if(i & (1 << l)) count++;
			}
			s <<= shift;
			s = s | ((1 << count) - 1);
			shift = j < k - 1 ? m[j + 1][1] - m[j + 1][0] + 1 : 0;
		}
		if(s < i) continue;
		else{
			int sum = 0;
			vector<int> temp;
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					sum += a[j];
					temp.push_back(a[j]);
				}
			}
			if(sum == t) subs.push_back(temp);
		}
	}
	return subs;
}
int main(){
	int test, n, t;
	vector< vector<int> > subs;
	vector<int> a;
	cin >> test;
	while(test--){
		cin >> n;
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		cin >> t;
		subs = combinationSum(a, t);
		for(int i = 0; i < subs.size(); i++){
			for(int j = 0; j < subs[i].size(); j++){
				cout << subs[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}