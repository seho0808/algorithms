#include <map>
#include <iostream>

using namespace std;

// hash, unordered set, map all works (O(1))
// map uses red black tree
int main() {
    int n, m;
    cin >> n >> m;
    map<string, int> rbtree;
    for (int i = 0; i < n; i++) {
        string s;
        cin >>  s;
        rbtree.insert(pair<string, int> (s, 1));
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (rbtree[s]) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}