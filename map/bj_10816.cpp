// 10
// 6 3 2 10 10 10 -10 -10 7 3
// 8
// 10 9 -5 2 3 4 5 -10

/**
Time Complexity
rbtree insertion/change worst case => log(n) => n times => nlog(n)
search in rbtree => log(n) => m times => mlog(n)
total => (m+n)log(n)

Space Complexity
rbtree of size n =>  O(n)
total => O(n)

The differences between this and solving with vector + binary search
- map uses pair rather than a single integer so more space complexity.
- rbtree itself will use more memory by default than vector.
- still don't know yet why rbtree takes up 10 times more space and 3 times more time.

*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; 
    cin >> n;
    map<int, int> rbtree;
    // 1. simpler way.
    // for (int i = 0; i < n; i++) {
    //     int a;
    //     cin >> a;
    //     rbtree[a]++;
    // }
    // 2. another way to implement it
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        map<int, int>::iterator it = rbtree.find(a);
        if  (it != rbtree.end()) { // found
            (*it).second += 1;
        } else {
            rbtree.insert(pair<int, int> (a, 1));
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        cout << rbtree[a] << " ";
    }

    return 0;
}