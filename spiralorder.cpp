#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > generateMatrix(int n){
	vector< vector<int> > m(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			m[i].push_back(0);
		}
	}
	int l = 0, r = n - 1, t = 0, b = n - 1;
	int count = 1;
	while(l <= r && t <= b){
		for(int i = l; i <= r; i++){
			m[t][i] = count++;
		}
		t++;
		for(int j = t; j <= b; j++){
			m[j][r] = count++;
		}
		r--;
		if(t < b){
			for(int i = r; i >= l; i--){
				m[b][i] = count++;
			}
			b--;
		}
		if(l < r){
			for(int j = b; j >= t; j--){
				m[j][l] = count++;
			}
			l++;
		}
	}
	return m;
}

int main(){
	int t, n;
	vector< vector<int> > m;
	cin >> t;
	for (int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			m = generateMatrix(n);
			for(int p = 0; p < n; p++){
				for(int q = 0; q  < n; q++){
					cout << m[p][q] << " ";
				}
				cout << "\n";
			}
		}
	}
	return 0;
}