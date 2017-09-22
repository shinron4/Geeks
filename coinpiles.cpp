#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n, k, arr[100], idx;
	    cin>>n>>k;
	    int coins = 0;
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	        coins = coins + arr[i];
	    }
	    for(int i=0; i<n; i++){
	        int sum = 0;
	        for(int j=0; j<n; j++){
	            if(i!=j){
	                if(arr[j] < arr[i]){
	                    sum = sum + arr[j];
	                } else if(arr[j]>arr[i]+k) {
	                    sum = sum + (arr[j]-arr[i]-k);
	                }
	            }
	        }
	        if(sum<coins){
	        	idx = i;
	            coins = sum;
	        }
	    }
	    cout<<coins<< " " << idx << endl;
	}
	return 0;
}