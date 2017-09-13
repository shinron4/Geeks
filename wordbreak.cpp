#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct trie{
	bool word;
	struct trie *child[26];
} *T;

bool insert(struct trie * t, char s[], int n){
	for(int i = 0; i < n; i++){
		if(t->child[s[i] - 'a'] == NULL){
			t->child[s[i] - 'a'] = (struct trie *) malloc(sizeof(struct trie));
		}
		t = t->child[s[i] - 'a'];
	}
	return t->word = true;
}

bool wordbreak(struct trie * t, char tt[], int n, int j){
	if(j < n){
		if(t->word == true){
			bool f1 = t->child[tt[j] - 'a'] != NULL ? wordbreak(t->child[tt[j] - 'a'], tt, n, j + 1) : false;
			bool f2 = wordbreak(T, tt, n, j);
			return f1 || f2;
		}
		else if(t->child[tt[j] - 'a'] != NULL) return wordbreak(t->child[tt[j]- 'a'], tt, n, j + 1);
		else return false;
	}
	else return t->word;
}

int main(){
	int t, n;
	char s[15], tt[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		T = (struct trie *) malloc(sizeof(struct trie *));
		for(int j = 0; j < n; j++){
			cin >> s;
			insert(T, s, strlen(s));
		}
		cin >> tt;
		cout << wordbreak(T, tt, strlen(tt), 0) << "\n";
	}
	return 0;
}