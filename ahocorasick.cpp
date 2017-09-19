#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<string> dict;

struct trie{
	int idx;
	struct trie *child[26], *f;
};

bool insert(struct trie *r, string s, int k){
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(r->child[s[i] - 'a'] == NULL){
			r->child[s[i] - 'a'] = (struct trie *) malloc(sizeof(struct trie));
			for(int j = 0; j < 26; j++) r->child[s[i] - 'a']->child[j] = NULL;
			r->child[s[i] - 'a']->f = NULL;
			r->child[s[i] - 'a']->idx = -1;
		}
		r = r->child[s[i] - 'a'];
	}
	r->idx = k;
	return true;
}

bool longsuffix(struct trie *r){
	if(!r) return false;
	queue<struct trie *> q;
	struct trie * root = r;
	r->f = r;
	for(int i = 0; i < 26; i++){
		if(r->child[i]){
			r->child[i]->f = r;
			q.push(r->child[i]);
		}
	}
	while(!q.empty()){
		struct trie * u = q.front();
		q.pop();
		for(int i = 0; i < 26; i++){
			if(u->child[i]){
				struct trie * v = u->f;
				while(v != root && !v->child[i]) v = v->f;
				if(v->child[i]) v = v->child[i];
				u->child[i]->f = v;
				q.push(u->child[i]);
			}
		}
	}
	return true;
}

void matcher(string t, struct trie *r){
	int n = t.length();
	struct trie * temp = r;
	for(int i = 0; i < n; i++){
		while(temp != r && !temp->child[t[i] - 'a']) temp = temp->f;
		if(temp->child[t[i] - 'a']) temp = temp->child[t[i] - 'a'];
		if(temp->idx > -1){
			cout << "Word " << dict[temp->idx] << " occurs from ";
			cout << i - dict[temp->idx].length() + 1 << " to " << i << "\n"; 
		}
	}
}

int main(){
	int n;
	string s, t;
	struct trie *root = (struct trie *) malloc(sizeof(struct trie));
	for(int i = 0; i < 26; i++) root->child[i] = NULL;
	root->idx = -1;
	root->f = NULL;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		insert(root, s, i);
		dict.push_back(s);
	}
	cin >> t;
	longsuffix(root);
	matcher(t, root);
	return 0;
}