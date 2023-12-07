#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define fori(a, n) for (int i=a; i<=n; i++)
#define forj(a, n) for (int j=a; j<=n; j++)

const int MAX_N = 610;

using namespace std;

int longest_submatrix(	
	vector<vector<int>>& matriz, 
	vector<vector<int>> indice, 
	vector<int>& maximocoluna,
	int N, int M
) {
	int ans = 0;

	vector<int> dp(MAX_N);

	for (int coluna_ini = 1; coluna_ini <= M; coluna_ini++) {
        for (int coluna_fim = M; coluna_fim >= coluna_ini; coluna_fim--) {
            int tam = coluna_fim - coluna_ini + 1;
            if (tam > maximocoluna[coluna_fim]) continue;
            if (tam * M <= ans) continue;
            if (indice[1][coluna_fim] <= coluna_ini) {
                dp[1] = 1;
            } else {
                dp[1] = 0;
            }
            ans = max(dp[1] * tam, ans);
            for (int linha = 2; linha <= N; linha++) {
                if (matriz[linha][coluna_ini] >
                    matriz[linha - 1][coluna_fim]) {
                    dp[linha] = dp[linha - 1];
                } else {
                    dp[linha] = 0;
                }
                if (indice[linha][coluna_fim] <= coluna_ini) {
                    dp[linha]++;
                } else {
                    dp[linha] = 0;
                }
                ans = max(dp[linha] * tam, ans);
            }
        }
    }

	return ans;
}

int main() {
	int N, M;

	vector<int> maximocoluna(MAX_N, 1);
	vector<vector<int>> indice(MAX_N, vector<int>(MAX_N));
	vector<vector<int>> matriz(MAX_N, vector<int>(MAX_N));

	while (scanf("%d %d", &N, &M) && (N || M)) {
        fori(1, N) {
        	scanf("%d", &matriz[i][1]);
            indice[i][1] = 1;
            forj(2, M) {
            	scanf("%d", &matriz[i][j]);
                if (matriz[i][j] > matriz[i][j - 1]) {
                    indice[i][j] = indice[i][j - 1];
                    maximocoluna[j] = max(maximocoluna[j], j - indice[i][j] + 1);
                } else {
                    indice[i][j] = j;
                }
            }
        }

        printf("%d\n", longest_submatrix(matriz, indice, maximocoluna, N, M));
	}

	return 0;
}

