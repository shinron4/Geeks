#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int maxDiff(Node* root){
	int m = 0;
	if(root != NULL){
		if(mp.size() > 0){
	 		auto f = mp.begin(), l = mp.cend();
			m = max(abs(f->first - root->data), abs((--l)->first - root->data));
		}
		if(mp.count(root->data) < 0) mp[root->data] = 1;
		else mp[root->data] += 1;
		m = max(m, maxDiff(root->left));
		m = max(m, maxDiff(root->right));
		if(mp[root->data] > 1) mp[root->data] -= 1;
		else mp.erase(root->data);
	}
	return m;
}

int main(){

	return 0;
}