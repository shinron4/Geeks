#include <iostream>
#include <cstring>

using namespace std;

char T[1000], P[1000];
int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> T >> P;
		int nt = strlen(T), np = strlen(P), Ft[26], Fp[26];
		for(int j = 0; j < 26; j++) Ft[j] = Fp[j] = 0;
		for(int j = 0; j < nt; j++) Ft[T[j] - 'a'] += 1;
		for(int j = 0; j < np; j++) Fp[P[j] - 'a'] += 1;
		bool f = true;
		for(int j = 0; j < 26; j++){
			if(Ft[j] < Fp[j]){
				f = false;
				break;
			}
		}
		if(!f) cout << -1;
		else{
			int p = 0, q = nt - 1, winS, winE;
			while(p >= 0){
				while(Ft[T[p] - 'a'] - 1 >= Fp[T[p] - 'a']){
					Ft[T[p] - 'a']--;
					p++;
				}
				while(Ft[T[q] - 'a'] - 1 >= Fp[T[q] - 'a']){
					Ft[T[q] - 'a']--;
					q--;
				}
				winS = p; winE = q;
				Ft[T[p] - 'a']--;
				p++;
				while(p >= 0){
					p--;
					if(p < 0) break;
					Ft[T[p] - 'a']++;
					Ft[T[q] - 'a']--;
					q--;
					bool f = true;
					for(int j = 0; j < 26; j++){
						if(Ft[j] < Fp[j]){
							f = false;
							break;
						}
					}
					if(f) break;
				}
			}
			for(int j = winS; j <= winE; j++) cout << T[j];
		}
		cout << "\n";
	}
	return 0;
}