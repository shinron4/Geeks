#include <iostream>

#define MOD 1000000007

using namespace std;

long long int perm[101][101][101], sum[101][101][101];

int main(){
	perm[0][0][0] = 1; 
	sum[0][0][0] = 0;
	for(int p = 0; p <= 100; p++){
		for(int q = 0; q <= 100; q++){
			for(int r = 0; r <= 100; r++){
				long long int t, g, w, perms = 0;
				sum[p][q][r] = 0;
				if(p > 0){
					perms = (perms + perm[p - 1][q][r]) % MOD;
					t = (sum[p - 1][q][r] * 10) % MOD;
					g = (perm[p - 1][q][r] * 4) % MOD;
					w = (t + g) % MOD;
					sum[p][q][r] = (sum[p][q][r] + w) % MOD;
				}
				if(q > 0){
					perms = (perms + perm[p][q - 1][r]) % MOD;
					t = (sum[p][q - 1][r] * 10) % MOD;
					g = (perm[p][q - 1][r] * 5) % MOD;
					w = (t + g) % MOD;
					sum[p][q][r] = (sum[p][q][r] + w) % MOD;
				}
				if(r > 0){
					perms = (perms + perm[p][q][r - 1]) % MOD;
					t = (sum[p][q][r - 1] * 10) % MOD;
					g = (perm[p][q][r - 1] * 6) % MOD;
					w = (t + g) % MOD;
					sum[p][q][r] = (sum[p][q][r] + w) % MOD;
				}
				perm[p][q][r] = (p == 0 && q == 0 && r == 0 ? 1 : perms);
			}
		}
	}
	int t, x, y, z;
	long long int s;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> x >> y >> z;
		s = 0;
		for(int p = 0; p <= x; p++)
			for(int q = 0; q <= y; q++)
				for(int r = 0; r <= z; r++)
					s = (s + sum[p][q][r]) % MOD;
		cout << s << "\n";
	}
	return 0;
}