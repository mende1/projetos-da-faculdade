#include <iostream>
#include <vector>

#define fori(a, n) for (int i=a; i<=n; i++)
#define forj(a, n) for (int j=a; j<=n; j++)
 
using namespace std;

const int MN = 1e+3+35;

int solve(
        vector<vector<int>>& data,
        vector<vector<int>>& sum,
        vector<vector<vector<int>>>& dp,
        int n
    ) {

    int ans = 0;

    fori(1, n)
        forj(1, n)
            dp[i][j][0] = dp[i][j][1] = 0;

    forj(1, n) {
        fori(j, n) {
            dp[i][j][0] = sum[i][j];
            dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][1]+(sum[i][j]-sum[i-1][j-1]));
            ans = max(ans, dp[i][j][0]);
        }

        dp[n][j][1] = dp[n][j][0];

        for(int i=n-1; i>=j; i--)
            dp[i][j][1] = max(dp[i+1][j][1], dp[i][j][0]);
    }
    
    return ans;
}
 
int main() {
    int n;

    vector<vector<int>> data(MN, vector<int>(MN));
    vector<vector<int>>  sum(MN, vector<int>(MN));
    vector<vector<vector<int>>> dp(MN, vector<vector<int>>(MN, vector<int>(2)));

    while(cin >> n && n) {
        fori(1, n)
            forj(1, i)
                cin >> data[i][j];

        fori(1, n)
            forj(1, i)
                sum[i][j]=(sum[i-1][j]+sum[i-1][j-1]-(i-2>=0?sum[i-2][j-1]:0))+data[i][j];

        cout << solve(data, sum, dp, n) << endl;
    }

    return 0;
}