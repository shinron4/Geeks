#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reverseWords(string &a) {
    vector<string> vs;
    int n = a.length(), i = 0;
    while(i < n){
        while(i < n && (a[i] == ' ' || a[i] == '\t')) i++;
        int j = i + 1;
        while(j < n && !(a[j] == ' ' || a[j] == '\t')) j++;
        vs.push_back(a.substr(i, j - i));
        i = j;
    }
    i = vs.size() - 1;
    for(; i > 0; i--) cout << vs[i] << " ";
    cout << vs[i];

}

int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		getline(cin, s);
		reverseWords(s);
	}
	return 0;
}