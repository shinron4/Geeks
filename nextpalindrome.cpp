#include <iostream>
#include <cstring>

using namespace std;

void nextpalindrome(char a[], int n){
	int mid = (n - 1) >> 1, i = mid;
	while(i >= 0 && a[i] == a[n - i - 1]) i--;
	if(i >= 0 && a[i] > a[n - i - 1]) while(i >= 0) a[n - i - 1] = a[i--];
	else{
		int c = 1;
		for(int j = mid; j >= 0; j--){
			int x = a[j] - '0' + c;
			a[j] = x % 10 + '0';
			c = x / 10;
			a[n - j - 1] = a[j];
		}
		if(c == 1){
			n++;
			a[0] = a[n - 1] = '1';
			for(int j = 1; j < n - 1; j++) a[j] = '0';
		}
	}
}

int main(){
	int t, n;
	char num[1000002];
	cin >> t;
	while (t--){
		cin >> num;
		n = strlen(num);
		nextpalindrome(num, n);
		cout << num << "\n";
	}
	return 0;
}