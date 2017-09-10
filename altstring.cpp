#include <iostream>
#include <cstring>

using namespace std;

char s[1000];

int main(){
	int n, f[26], occ[26], m = -INT_MAX;
	cin >> n >> s;
	for(int i = 0; i < 26; i++) f[i] = 0;
	for(int  i = 0; i < n; i++){ 
		if(f[s[i] - 'a'] == 0) occ[s[i] - 'a'] = i;
		f[s[i] - 'a']++;
	}
	for(int i = 0; i < 26; i++){
		for(int j = i + 1; j < 26; j++){
			if(f[i] > 0 && f[j] > 0){
				int p = 0, k = (occ[i] < occ[j] ? i : j), l;
				for(l = occ[k] + 1; l < n; l++){
					if(s[l] - 'a' == k && (p != 1)) break;
					else if(s[l] - 'a' == k) p = 0; 
					else if(s[l] - 'a' == (k == i ? j : i)) p++;
				}
				if((l < n ? p == 1 : p < 2) && (f[i] + f[j] > m)) m = f[i] + f[j]; 
			}
		}
	}
	cout << (m > 0 ? m : 0);
	return 0;
}