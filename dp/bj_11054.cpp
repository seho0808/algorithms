/**
dp-LIS
DP 안쓰는  Brute Force 완탐의 Time Complexity는?
1개 선택 n 
2개 선택 + (n-1) + (n-2) + (n-3) + ... + 1 =>  (n-1)n/2 => about n^2
3개 선택 + n(n-1)(n-2) + ... => about n^3
... => factorial time.
DP => O(n^2) but nlogn with some other algorithm than mine.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);
    
    // count lis from the left
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i ; j++) {
            if (v[i] > v[j]) {
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
    }
    
    // count lis from the right
    for (int i = n-2; i >= 0; i--) {
        for (int j = n-1; j > i; j--) {
            if (v[i] > v[j]) {
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }
    
    // merge
    int ans = dp2[0];
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (v[i] == v[j]) {
                ans = max(ans, dp1[i] + dp2[j]-1);
            } else {
                ans = max(ans, dp1[i] + dp2[j]);
            }
        }
    }
    
    // for (int i = 0; i < n; i++) {
    //     cout << dp1[i] <<" ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << dp2[i] << " ";
    // }
    // cout << endl;
    
    cout << ans;
    
    
    return 0;
}