/**
dp - 정렬 LIS
정렬 후 LIS
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i].second > v[j].second) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int max_val = 0;
    for (int i = 0; i < n; i++) {
        max_val = max(max_val, dp[i]);
    }

    cout << n - max_val;

    return 0;
}