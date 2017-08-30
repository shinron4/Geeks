#include <stack>
#include <iostream>

#define OBJ int
#define S stack< OBJ >

using namespace std;

bool isfull();
bool isempty();
bool push(OBJ);
bool pop(OBJ &);
bool getmin(OBJ &);

int main(){
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
		extern int size;
		size = 100;
		cin >> n;
		for(int j = 0; j < n; j++){
			int x;
			cin >> x;
			if(!push(x)) cout << "Stack Full\n", exit(1);
		}
		int x;
		if(!getmin(x)) cout << "Stack Empty\n", exit(1);
		else cout << x << "\n";
		while(pop(x));
	}
	return 0;
}

S s, ss;
int size;

bool isempty(){
	return s.empty();
}

bool isfull(){
	return s.size() == size;
}

bool push(OBJ x){
	if(!isfull()){
		if(isempty()){
			s.push(x);
			ss.push(x);
		}
		else{
			s.push(x);
			if(ss.top() <= x) ss.push(ss.top());
			else ss.push(x);			
		}
		return true;
	}
	else return false;
}

bool pop(OBJ &x){
	if(!isempty()){
		x = s.top();
		s.pop();
		ss.pop();
		return true;
	}
	else return false;
}

bool getmin(OBJ &x){
	if(!isempty()){
		x = ss.top();
		return true;
	}
	else return false;
}