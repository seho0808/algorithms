#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        s.insert(curr);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int curr;
        cin >> curr;
        if (s.find(curr) != s.end()) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}