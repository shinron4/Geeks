#include <map>
#include <iostream>

using namespace std;

int A[1000];
int main(){
	int t, n, k;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int j = 0; j < n; j++) cin >> A[j];
		map<int, int> mp;
		for(int j = 0; j < k; j++){
			if(mp.count(A[j]) > 0) mp[A[j]] += 1;
			else mp[A[j]] = 1; 
		}
		auto ele = mp.cend();
		if(mp.size() >= 1) cout << (--ele)->first << " ";
		for(int j = k; j < n; j++){
			if(mp.count(A[j]) > 0) mp[A[j]] += 1;
			else mp[A[j]] = 1;
			mp[A[j - k]] -= 1;
			if(mp[A[j - k]] == 0) mp.erase(A[j - k]);
			ele = mp.cend();
			if(mp.size() >= 1) cout << (--ele)->first << " ";
		}
		cout << "\n";
	}
	return 0; 
}