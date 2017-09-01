#include <iostream>
#include <cstring>

using namespace std;

char bin[100];

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> bin;
		int n = strlen(bin), sum = 0;
		for(int j = n - 1; j >= 0; j--) if(bin[j] == '1') sum += (j & 1 ? 2 : 1);
		cout << (sum % 3 == 0 ? 1 : 0) << "\n"; 
	}
	return 0;
}