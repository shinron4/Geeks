#include <iostream>
#include <vector>

using namespace std;

void shifts(int s[], int i, int j){
	for(int k = j; k > i; k--) swap(s[k - 1], s[k]);
}

vector< vector<int> > generate(vector<int> a){
	int n = a.size(), s[1 << n];
	vector< vector<int> > m;
	for(int i = 0; i < 1 << n; i++) s[i] = i;
	for(int i = 1; i <= 1 << n; i <<= 1){
		bool f = true;
		for(int j = 0; j < (1 << n); j += i, f = !f){
			if(f) shifts(s, j, j + i - 1);
		}
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < 1 << n; i++){
		vector<int> t;
		for(int j = n - 1; j >= 0; j--){
			if(!(s[i] & (1 << j))) t.push_back(a[n - 1- j]);
		}
		m.push_back(t);
	}
	return m;
}

int main(){
	int t, n;
	vector<int> a;
	vector< vector<int> > m;
	cin >> t;
	for(int test = 0; test < t; test++){
		cin >> n;
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			a.push_back(x);
		}
		m = generate(a);
		for(int i = 0; i < m.size(); i++){
			for(int j = 0; j < m[i].size(); j++){
				cout << m[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}