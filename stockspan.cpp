#include <iostream>
#include <stack>

using namespace std;

int main(){
	int t, n;
	int s[200];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		stack< pair<int, int> > S;
		for(int j = 0; j < n; j++){
			int x, c = 1;
			cin >> x;
			while(!S.empty() && x >= S.top().first) (c += S.top().second), S.pop();
			S.push(make_pair(x, c));
			s[j] = c;
		}
		for(int j = 0; j < n; j++) cout << s[j] << " ";
		cout << "\n";
	}
}