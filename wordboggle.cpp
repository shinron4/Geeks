#include <iostream>
#include <algorithm>

using namespace std; 

struct charnode{
	int i;
	struct charnode *ch[127];
} *tr;

void insert(char s[], int j){
	int i = 0;
	struct charnode *temp = tr;
	while(s[i] != '\0'){
		if(temp->ch[s[i]] == NULL){
			temp->ch[s[i]] = (struct charnode *) malloc(sizeof(struct charnode));
			temp->ch[s[i]]->i = -1;
		}
		temp = temp->ch[s[i]];
		i++;
	}
	temp->i = j;
}

struct{
	char c;
	bool f;
} boggle[1000][1000];

struct strarr{
	char s[1000];
	bool f;
} str[1000];

struct COMP{
	bool operator()(struct strarr p, struct strarr q){
		return strcmp(p.s, q.s) < 0;
	}
} compare;

void find(int n, int m, int u, int v, struct charnode *temp){
	boggle[u][v].f = true;
	if(temp->ch[boggle[u][v].c] != NULL){
			if(temp->ch[boggle[u][v].c]->i != -1) str[temp->ch[boggle[u][v].c]->i].f = true;
			for(int i = u - 1; i < u + 2; i++){
				for(int j = v - 1; j < v + 2; j++){
					if((i >= 0 && i < n && j >= 0 && j < m && (i != u || j != v)) && boggle[i][j].f == false){
						find(n, m, i, j, temp->ch[boggle[u][v].c]);
					}
				}
			}
	}
	boggle[u][v].f = false;
}

int main(){
	int t, x, n, m;
	char s[1000];
	bool start[127];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> x;
		for(int j = 0; j < 127; j++) start[j] = false;
		for(int j = 0; j < x; j++) str[j].f = false;
		tr = (struct charnode *) malloc(sizeof(struct charnode));
		tr->i = -1;
		for(int j = 0; j < x; j++){
			cin >> str[j].s;
			start[str[j].s[0]] = true;
			insert(str[j].s, j);
		}
		cin >> n >> m;
		for(int j = 0; j < n; j++) for(int k = 0; k < m; k++){
			cin >> boggle[j][k].c;
			boggle[j][k].f = false;
		}
		for(int j = 0; j < n; j++) for(int k = 0; k < m; k++){
			if(start[boggle[j][k].c]){
				find(n, m, j, k, tr);
			}
		}
		sort(str, str + x, compare);
		bool f = false;
		for(int j = 0; j < x; j++) {
			if(str[j].f == true){
				cout << str[j].s << " ";
			}
			f = f || str[j].f;
		}
		if(!f) cout << -1;
		cout << "\n";
	}
	return 0;
}