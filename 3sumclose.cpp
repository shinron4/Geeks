#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <stdlib.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target){
    int mi = INT_MAX, sum = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++){
        int l = i + 1, r = nums.size() - 1;
        while(l < r){
            if(abs(target - (nums[i] + nums[l] + nums[r])) < mi){
                mi = abs(target - (nums[i] + nums[l] + nums[r]));
                sum = nums[i] + nums[l] + nums[r];
            }
            if(target >= (nums[i] + nums[l] + nums[r])) l++;
            else r--;
        }
    }
    return sum;
}

vector<int> A;

int main(){
    int t, n, sum;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> sum;
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            A.push_back(x);
        }
        cout << threeSumClosest(A, sum) << "\n";
        A.clear();
    }
    return 0;
}