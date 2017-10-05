#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
	int t, n, ma;
	stack< pair<char, int> > s;
	string p;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> p;
		ma = 0;
		for(int j = 0; j < p.length(); j++){
			if(p[j] == '(') s.push(make_pair('(', -1));
			else{
				int l = 0;
				bool f = false;
				if(!s.empty() && s.top().first == 'v'){
					l = s.top().second;
					s.pop();
				}
				if(!s.empty() && s.top().first == '('){
					l += 2;
					f = true;
					s.pop();
				}
				if(!s.empty() && s.top().first == 'v'){
					l += s.top().second;
					s.pop();
				}
				if(l > 0) s.push(make_pair('v', l));
				if(f == false && !s.empty()) s.pop();
 				ma = max(l, ma);
			}
		}
		cout << ma << "\n";
		while(!s.empty()) s.pop();
	}
	return 0;
}