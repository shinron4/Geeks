#include <iostream>
#include <string>

using namespace std;

string inttoroman(int i){
	string s;
	int k = 0;
	while(i > 0){
		if(i >= 1000){
			s.append("M", 1);
			i -= 1000;
		}
		else if(i >= 900){
			s.append("CM", 2);
			i -= 900;
		}
		else if(i >= 500){
			s.append("D", 1);
			i -= 500;
		}
		else if(i >= 400){
			s.append("CD", 2);
			i -= 400;
		}
		else if(i >= 100){
			s.append("C", 1);
			i -= 100; 
		}
		else if(i >= 90){
			s.append("XC", 2);
			i -= 90;
		}
		else if(i >= 50){
			s.append("L", 1);
			i -= 50;
		}
		else if(i >= 40){
			s.append("XL", 2);
			i -= 40;
		}
		else if(i >= 10){
			s.append("X", 1);
			i -= 10;
		}
		else if(i >= 9){
			s.append("IX", 2);
			i -= 9;
		}
		else if(i >= 5){
			s.append("V", 1);
			i -= 5;
		}
		else if(i >= 4){
			s.append("IV", 2);
			i -= 4;
		}
		else{
			s.append("I", 1);
			i -= 1;
		}
	}
	return s;
} 

int main(){
	int t, n;
	string s;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		s = inttoroman(n);
		cout << s << "\n";
	}
	return 0;
}