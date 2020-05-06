#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main(){

	int n, num;
	int var;
	
	cin >> n;
	
	vector <int> u;
	vector <int> v;
	vector <int> d;
	vector <int> aux;
	
	int i, j;
	
	for (i=0; i<n; i++){
	
		var = 0;
	
		aux.push_back(var);	
			
	}
	
	for (i=0; i < 3; i++){
	
		for (j=0; j < n; j++){
		
			cin >> num;
			
			if ( i == 0 )
	
				u.push_back(num);
	
			if ( i == 1 )
		
				v.push_back(num);
	
			if ( i == 2 )
		
				d.push_back(num);
		
		}
	
	}
	
	for (i = 0; i < n; i++){
	
		if ((u[i] + v[i]) == d[i] )
		
			aux[i] = 1;
	
	}
	
	int sit = 0;
	
	for (i=0; i<n; i++){
	
		sit += aux[i];
	
	}
	
	if (sit == n)
	
		cout << "OK" << endl;
		
	else
	
		cout << "NOPE :(" << endl;
	
}
