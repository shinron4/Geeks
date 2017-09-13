#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct event{
	int time;
	int type;
} e[10000];

struct COMP{
	bool operator()(struct event &p, struct event &q){
		if(p.time < q.time) return true;
		else if(p.time == q.time) return p.type == 0;
		else return false;
	}
} compare;

int a[5000], d[5000];
int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		int k = 0;
		for(int j = 0; j < n; j++) cin >> a[j];
		for(int j = 0; j < n; j++) cin >> d[j];
		for(int j = 0; j < n; j++){
			if(a[j] <= d[j]){
				e[k].time = a[j];
				e[k++].type = 0;
				e[k].time = d[j];
				e[k++].type = 1;
			}
			else{
				e[k].time = a[j];
				e[k++].type = 0;
				e[k].time = 2400;
				e[k++].type = 1;
				e[k].time = 0;
				e[k++].type = 0;
				e[k].time = d[j];
				e[k++].type = 1; 
			}
		}
		sort(e, e + k, compare);
		int ptrain = 0, m = -INT_MAX;
		for(int j = 0; j < (n << 1); j++){
			if(e[j].type == 0){
				ptrain++;
				m = max(m, ptrain);
			}
			else ptrain--;
		}
		cout << m << "\n";
	}
	return 0;
}