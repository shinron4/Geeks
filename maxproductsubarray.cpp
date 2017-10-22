#include <iostream>
#define MAX 50

using namespace std;

bool color[MAX][MAX];
int c;

void visit(bool al[][MAX], int n, int m, int i, int j){
	color[i][j] = true;
	c++;
	for(int p = i - 1; p <= i + 1; p++){
		for(int q = j - 1; q <= j + 1; q++){
			if(p >= 0 && p < n && q >= 0 && q < m && (p != i || q != j) && al[p][q]){
				if(color[p][q] == false){
					visit(al, n, m, p, q);
				}
			}
		}
	}
}

int largestconnected(bool al[][MAX], int n, int m){
	int lc = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			color[i][j] = false;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m ; j++){
			if(color[i][j] == false && al[i][j]){
				c = 0;
				visit(al, n, m, i, j);
				lc = max(lc, c);
			}
		}
	}
	return lc;
}

int main(){
	int t, n, m;
	bool al[50][50];
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m ; j++){
				cin >> al[i][j];
			}
		}
		cout << largestconnected(al, n, m) << "\n";
	}
	return 0;
}