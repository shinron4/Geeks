#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair< pair<int, int>, int > > M;

struct COMP{
    bool operator()(pair< pair<int, int>, int > &p, pair< pair<int, int>, int > &q){
        return p.first.second < q.first.second;
    }
} compare;

int main(){
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        int dm = 1, et;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            M.push_back(make_pair(make_pair(x, -1), j));
        }
        for(int j = 0; j < n; j++) cin >> M[j].first.second;
        sort(M.begin(), M.end(), compare);
        et = M[0].first.second;
        cout << M[0].second + 1 << " ";
        int j = 1;
        while(j < n){
            while(j < n && M[j].first.first <= et) j++;
            if(j < n){
                et = M[j].first.second;
                cout << M[j].second + 1<< " ";
            }
        }
        cout << "\n";
        M.clear();
    }
    return 0;
}