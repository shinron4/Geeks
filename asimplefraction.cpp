#include <iostream>

using namespace std;

int fraction(int n, int d){
	if(d == 0) return 0;
	struct { bool f; int idx;} r[2000];
	int l = 0;
	char s[2000];
	for(int j = 0; j < d; j++) r[j].f = false;
	cout << n / d;
	n %= d;
	if(n == 0) return 0;
	cout << '.';
	while(n > 0 && r[n].f == false){
		r[n].idx = l;
		r[n].f = true;
		s[l] = '0' + n * 10 / d;
		n = (n * 10) % d;
		l++;
	}
	if(n > 0){
		for(int j = 0; j < r[n].idx; j++) cout << s[j];
		cout << '(';
		for(int j = r[n].idx; j < l; j++) cout << s[j];
		cout << ')';
	}
	else for(int j = 0; j < l; j++) cout << s[j];
	return 0;
}

int main(){
	int t, n, d;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> d;
		fraction(n, d); cout << "\n";
	}
	return 0;
}