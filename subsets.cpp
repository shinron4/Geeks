#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsets(vector<int> a){
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
			for(int j = 0; j < n; j++){
				if(i & (1 << j)) cout << a[j] << " ";
			}
			cout << "\n";
		}
	}
}

int main(){
	int t, n;
	vector<int> a;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		subsets(a);
	}
	return 0;
}