#include <iostream>
#include <queue>

using namespace std;


int main() {
	int n, x, med;
	priority_queue<int, vector<int>> maxh;
	priority_queue<int, vector<int>, greater<int> > minh;
	cin >> n;
	for(int i = 1; i <= n; i++){
	    cin >> x;
	    if(!(i & 1)){
	        if(x <= med){
	            maxh.push(x);
	            minh.push(med);
	        }
	        else{
	            maxh.push(med);
	            minh.push(x);
	        }
	        med = (maxh.top() + minh.top()) >> 1;
	    }
	    else{
	        if(maxh.size() > 0 && x <= maxh.top()){
	            maxh.push(x);
	            med = maxh.top();
	            maxh.pop();
	        }
	        else{
	            minh.push(x);
	            med = minh.top();
	            minh.pop();
	        }
	    }
	    cout << med << "\n";
	}
	return 0;
}