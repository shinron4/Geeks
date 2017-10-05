#include <iostream>
#include <stack>
#define F first
#define S second
using namespace std;

int main(){
	int t, s[9][9];
	bool  r[9][10], c[9][10], b[3][3][10];
	stack< pair<int, int> > s1;
	stack< pair< pair<int, int>, int > > s2;
	cin >> t;
	for(int i = 0; i < t; i++){
		for(int j = 0; j < 9; j++) for(int k = 1; k < 10; k++) r[j][k] = c[j][k] = false;
		for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) for(int l = 1; l < 10; l++) b[j][k][l] = false;
		for(int j = 0; j < 9; j++){
			for(int k = 0; k < 9; k++){
				cin >> s[j][k];
				if(s[j][k] == 0) s1.push(make_pair(j, k));
				else r[j][s[j][k]] = c[k][s[j][k]] = b[j/3][k/3][s[j][k]] = true;
			}
		}
		while(!s1.empty()){
			pair<int, int> ce = s1.top();
			bool next = false;
			for(int j = 1; j <= 9; j++){
				if(r[ce.F][j] == false && c[ce.S][j] == false && b[ce.F / 3][ce.S / 3][j] == false){
					r[ce.F][j] = c[ce.S][j] = b[ce.F / 3][ce.S / 3][j] = true;
					s[ce.F][ce.S] = j;
					s1.pop();
					s2.push(make_pair(ce, j));
					next = true;
					break;
				}
			}
			if(!next){
				bool f;
				while(!s2.empty()){
					f = false;
					pair< pair<int, int>, int> ce2 = s2.top();
					s2.pop();
					r[ce2.F.F][ce2.S] = c[ce2.F.S][ce2.S] = b[ce2.F.F / 3][ce2.F.S / 3][ce2.S] = false;
					s[ce2.F.F][ce2.F.S] = 0;
					for(int j = ce2.S + 1; j <= 9; j++){
						if(r[ce2.F.F][j] == false && c[ce2.F.S][j] == false && b[ce2.F.F / 3][ce2.F.S / 3][j] == false){
							r[ce2.F.F][j] = c[ce2.F.S][j] = b[ce2.F.F / 3][ce2.F.S / 3][j] = true;
							s[ce2.F.F][ce2.F.S] = j;
							s2.push(make_pair(ce2.F, j));
							f = true;
							break;
						}
					}
					if(!f) s1.push(ce2.F);
					else break;
				}
			}
		}
		while(!s1.empty()) s1.pop();
		while(!s2.empty()) s2.pop();
		for(int j = 0; j < 9; j++) for(int k = 0; k < 9; k++) cout << s[j][k] << " ";
		cout << "\n";
 	}
	return 0;
}