#include <iostream>
#include <string>

using namespace std;

int wildCard(string p,string t){
	int pn = p.length(), tn = t.length();
	bool dp[pn][tn];
	for(int i = 0; i < tn; i++){
		if(p[0] == '*') dp[0][i] = true;
		else if(p[0] == '?') dp[0][i] = i > 0 ? false : true;
		else if(i == 0 && p[0] == t[0]) dp[0][0] = true;
		else dp[0][i] = false; 
	}
	int i = 0;
	while(i < pn && p[i] == '*') dp[i++][0] = true;
	if(i < pn && (p[i] == '?' || p[i] == t[0])){
		dp[i][0] = true;
		i++;
	}
	while(i < pn && p[i] == '*') dp[i++][0] = true;
	while(i < pn) dp[i++][0] = false;
	for(int i = 1; i < pn; i++){
		for(int j = 1; j < tn; j++){
			if(p[i] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
			else if(p[i] == '?' || p[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = false;
		}
	}
	return dp[pn - 1][tn - 1];
}

int main(){
	int t;
	string txt, patt;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> patt >> txt;
		cout << wildCard(patt, txt) << "\n";
	}
	return 0;
}