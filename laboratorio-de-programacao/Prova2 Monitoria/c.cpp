#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// By: mende1

#define endl "\n"
#define int ll

int32_t main() {

	 int tabu[8][8];

	 for (int i=0; i<8; i++) {
	 	for (int j=0; j<8; j++) {
	 		cin >> tabu[i][j];
	 	}
	 }

	 // int i, j;
	 // for (i=0; i < 8; i++) {        
	 // 	for (j=0; j < 7; j++)            
	 // 		cout << i << j << " ";        
	 // 	cout << i << j << endl;    
	 // }

	 int x, y;
	 cin >> x >> y;

	 int inimigos = 0;

	 if (tabu[x][y] != 1) {
	 	cout << 0 << endl;
	 	return 0;
	 }

	 int posx = x;
	 int posy = y;

 	for (int i=posy-1; i>=0; i--) {
 		if (tabu[posx][i]) {
 			if (tabu[posx][i] == 2) {
 				inimigos++;
 			}
 			break;
 		} 
 	}

	 posx = x; posy = y;

 	for (int i=posy+1; i<8; i++) {
 		if (tabu[posx][i]) {
 			if (tabu[posx][i] == 2) {
 				inimigos++;
 			}
 			break;
 		} 
 	}


	 posx = x; posy = y;

 	for (int i=posx-1; i>=0; i--) {
 		if (tabu[i][posy]) {
 			if (tabu[i][posy] == 2) {
 				inimigos++;
 			}
 			break;
 		} 
 	}


	 posx = x; posy = y;

 	for (int i=posx+1; i<8; i++) {
 		if (tabu[i][posy]) {
 			if (tabu[i][posy] == 2) {
 				inimigos++;
 			}
 			break;
 		} 
 	}


	 cout << inimigos << endl;
}