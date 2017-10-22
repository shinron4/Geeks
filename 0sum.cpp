#include <iostream>
#include <map>

using namespace std;

int main(){
	int t, n, a[10000];
	cin >> t;
	while(t--){
		cin >> n;
		bool po = false, ne = false;
		map< pair<int, int> > mp;
		for(int i = 0; i < n; i++){
			cin >> a[j];
			if(a[j] >= 0) p = true;
			else n = true;
		}
		if(po == false || ne == false) cout << "No";
		else{
			int x = a[0];
			mp[x] = 1;
			for(int i = 1; i < n; i++){
				x = x + a[i];
				if(mp.count(x) > 0){
					cout << "Yes";
					break;
				}
				else mp[x] = 1;
			}
		}

	}
	cout << "\n";
	return 0;
}