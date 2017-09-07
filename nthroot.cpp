#include <iostream>
#include <cmath>
#include <cstdlib>

#define EPSILON 1e-3

using namespace std;


int main(){
	long long int t, n, m;
	double x_old, x_new;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		srand(time(NULL));
		x_new = m >> 1;
		do{
			x_old = x_new;
			x_new = ((n - 1.0) * x_old + (double)m / pow(x_old, n - 1)) / (double)n;
			 // cout << x_old << " " << x_new << "\n";
		}while(fabs(x_old - x_new) > EPSILON);
		cout << x_new << " " << floor(x_new) << "\n";
		cout << (fabs(x_new - floor(x_new)) > EPSILON ? -1 : (int)x_new) << "\n";
	}
	return 0;
}