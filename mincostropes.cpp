#include <iostream>
#include <queue>

using namespace std;

priority_queue< int, vector<int>, greater<int> > q;

int main(){
    int t, n, x;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> x;
            q.push(x);
        }
        int cost = 0;
        while(q.size() > 1){
            int u, v; 
            u= q.top();
            q.pop();
            v = q.top();
            q.pop();
            cost += (u + v);
            q.push(u + v);
        }
        cout << cost << "\n";
        q.pop();
    }
    return 0;
}