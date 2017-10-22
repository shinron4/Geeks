#include <iostream>
#include <string>

using namespace std;

int atoi(string & a){
	int n = a.length(), s = 1, i = 0;
	long long int num = 0;
	while(i < n && (a[i] == ' ' || a[i] == '\t')) i++;
	if(i == n || !(a[i] == '-' || (a[i] >= '0' && a[i] <= '9'))) return 0;
	if(a[i] == '-'){
		s = -1;
		i++;
	}
	while(i < n && (a[i] >= '0' && a[i] <= '9') && (num >= INT_MIN && num <= INT_MAX))
		num = num * 10 + s * (a[i++] - '0');
	if(num > INT_MAX) return INT_MAX;
	else if(num < INT_MIN) return INT_MIN;
	else return num;
}

int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		cout << atoi(s) << "\n";
	}
	return 0;
}