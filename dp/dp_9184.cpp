/**
dp - 강제 탑다운
*/
#include <vector>
#include<iostream>
using namespace std;
vector<vector<vector<int>>> dp;
int solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return solve(20, 20, 20);
    }
    if (dp[a][b][c] != -1) return dp[a][b][c]; // use memoized value
    if (a < b && b < c) {
        dp[a][b][c] = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b-1, c);
        return dp[a][b][c];
    }
    dp[a][b][c] = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
    return dp[a][b][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp.assign(51, vector<vector<int>> (51, vector<int> (51, -1)));
    while(true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        int ans = solve(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
    }
    return 0;
}