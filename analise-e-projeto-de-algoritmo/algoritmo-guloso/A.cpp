#include <iostream>
#include <vector>
#include <algorithm>

#define fori(a, n) for (int i=a; i<n; i++)
#define forj(a, n) for (int j=a; j<n; j++)
#define fork(a, n) for (int k=a; k<n; k++)

using namespace std;

void reorder_names(vector<string>& arr, vector<string>& aux, int K) {
  sort(arr.begin(), arr.end());
		
  fori(0, aux.size()) {
    forj(0, arr.size()) {
      int yep=1;
      fork(0, aux.size()) {
        if(aux[k]==arr[j]){
          if(K >= k-i){
            K-=(k-i);
            while(k>i) swap(aux[k], aux[k-1]), k--;
            arr.erase(arr.begin()+j);
            break;
          }else{
            yep=0;
            break;
          }
        }
      }
      if(yep) break;
    }
  }
}

int main() {
  int t = 1;
  int n, k;

  while (cin >> n >> k && n > 0) {
    vector<string> arr(n);

    fori(0, n) cin >> arr[i];

    vector<string> aux(arr);

    reorder_names(arr, aux, k);

    cout << "Instancia " << t++ << endl;
    fori(0, n) {
      cout << aux[i] << " ";
    }
    cout << endl << endl;
  }

  return 0;
}

