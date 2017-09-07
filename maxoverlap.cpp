#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct interval{
	bool type;
	int p;
} it[2 * 100000];

struct COMP{
	bool operator()(const struct interval &p, const struct interval &q){
		if(p.p < q.p) return true;
		else if(p.p == q.p){
			if(p.type != q.type) return p.type == false;
			else return true;
		} 
		else return false;
	}
} compare;

int main(){
	int t, n, sum = 0, ma, mtime;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		int k = 0;
		for(int j = 0; j < n; j++){
			cin >> it[j].p;
			it[j].type = false;
		}
		for(int j = 0; j < n; j++){
			cin >> it[n + j].p;
			it[n + j].type = true;			
		}
		sort(it, it + n << 1, compare);
		ma = -INT_MAX;
		for(int j = 0; j < (n << 1); j++){
			if(it[j].type == false){
				sum++;
				if(sum > ma){
					ma = sum;
					mtime = it[j].p;
				}
			}
			else sum--;
		}
		cout << ma << " " << mtime << "\n";
	}
	return 0;
}