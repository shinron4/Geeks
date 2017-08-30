#include <iostream>

using namespace std;

char TV[1000], O[1000];
long long int val[1000][1000], catalan[52];

int main(){
	int t, n;
	catalan[0] = 1;
	for(int j = 1; j < 52; j++){
		catalan[j] = 0;
		for(int k = 0; k < j; k++) catalan[j] += catalan[k] * catalan[j - k - 1];
	}
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++){
			if(j & 1) cin >> O[j >> 1];
			else cin >> TV[j >> 1];
		}
		for(int j = 0; j < (n + 1) >> 1; j++) val[j][j] = TV[j] == 'T' ? 1 : 0;
		for(int l = 2; l <= (n + 1) >> 1; l++){
			for(int p = 0; p <= ((n + 1) >> 1) - l; p++){
				int q = p + l - 1;
				val[p][q] = 0;
				for(int r = p; r < q; r++){
					switch(O[r]){
						case '|':
							val[p][q] += val[p][r] * catalan[q - r - 1] + catalan[r - p] * val[r + 1][q] - val[p][r] * val[r + 1][q]; 
							break;
						case '&':
							val[p][q] += val[p][r] * val[r + 1][q];
							break;
						case '^':
							val[p][q] += val[p][r] * (catalan[q - r - 1] - val[r + 1][q]) + (catalan[r - p] - val[p][r]) * val[r + 1][q];
							break;
					}
				}
			}
		}
		cout << (val[0][((n + 1) >> 1) - 1] % 1003)<< "\n";
	}
	return 0;
}