// 10
// 6 3 2 10 10 10 -10 -10 7 3
// 8
// 10 9 -5 2 3 4 5 -10

/**
Time Complexity
sort => nlog(n)
upper_bound => log(n) => m times => mlog(n) => + lower_bound => 2mlog(n)
total complexity => (n+2m)log(n)

Space Complexity
vector of size n => O(n)
total => O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(int a, int b) {
    return a<b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; 
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), cmp);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        // upper_bound는 찾고자 하는 값보다 큰 값이 처음으로 나타나는 위치이며,
        // lower_bound는 찾고자 하는 값 이상이 처음 나타나는 위치로써 
        // 두 값을 빼주면 해당 카드가 n개에서 몇 개 존재하는지 알 수 있다.
        long int n_ = upper_bound(v.begin(), v.end(), a) - lower_bound(v.begin(), v.end(), a);
        cout << n_ <<" ";
    }

    return 0;
}