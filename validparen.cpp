#include <iostream>
#define MAX 100

using namespace std;

void pp(int i, int n, int o, int c){
	static char s[MAX];
	if(c == n) cout << s << "\n";
	else {
		if(c < o){
			s[i] = ')';
			pp(i + 1, n, o, c + 1);
		}
		if(o < n){
			s[i] = '(';
			pp(i + 1, n, o + 1, c);
		}
	}
}

int main(){
	int n;
	cin >> n;
	pp(0, n, 0, 0);
	return 0;
}