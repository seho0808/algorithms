/**
유클리드 호제법
*/

#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) {
    while(b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a*(b/gcd(a, b));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << '\n';
    }

    return 0;
}