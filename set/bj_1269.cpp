/**
3 5
1 2 4
2 3 4 5 6
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        vector<int>::iterator it = lower_bound(v.begin(), v.end(), a);
        if (it != v.end() && !(a < *it)) cnt++;
    }

    cout << n+m-cnt*2;

    return 0;
}