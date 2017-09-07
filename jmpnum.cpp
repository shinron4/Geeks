#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(){
	int t, x, p;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> x;
		p = 1;
		q.push(0);
		while(!q.empty()){
			while(!q.empty()){
				int u = q.front(), lastd, v;
				q.pop();
				cout << u << " ";
				lastd = u % 10;
				if(lastd > 0){
					v = u * 10 + (lastd - 1);
					if(v <= x) q.push(v); 
				}
				if(lastd < 9){
					v = u * 10 + (lastd + 1);
					if(v <= x) q.push(v);
				}
			}
			if(p < 9) q.push(++p);
		}
		cout << "\n";
	}
	return 0;
}