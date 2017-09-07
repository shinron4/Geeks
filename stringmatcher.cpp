#include <iostream>
#include <cstring>

using namespace std;

void compute_prefix(char P[], int m, int pie[]){
	int k = 0;
	pie[1] = 0;
	for(int i = 2; i <= m; i++){
		while(k > 0 && P[k + 1] != P[i]) k = pie[k];
		if(P[k + 1] == P[i]) k++;
		pie[i] = k;
	}
}

int main(){
	int t, pie[100001];
	char P1[100001], P2[100001];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> P1;
		int n = strlen(P1);
		for(int j = 0; j < n; j++) P2[j + 1] = P1[j];
		compute_prefix(P2, n, pie);
		cout << pie[n] << "\n";
	}
	return 0;
}