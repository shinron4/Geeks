#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct COMP{
	bool operator()(int i, int j){
		char s[100], t[100];
		sprintf(s, "%d%d", i, j);
		sprintf(t, "%d%d", j, i);
		return strcmp(s, t) > 0;
	}
} compare;

string largest(int A[], int n){
	sort(A, A + n, compare);
	string s;
	char t[100];
	for(int i = 0; i < n; i++){
		sprintf(t, "%d", A[i]);
		string p(t);
		s.append(p);
	}
	return s;
}

int main(){
	int t, n, a[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> a[j];
		sort(a, a + n, compare);
		
		cout << largest(a, n) << "\n";
	}
}