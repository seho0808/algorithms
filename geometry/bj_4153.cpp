#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

bool isTri(int hypotenuse, int a, int b) {
    if (pow(a, 2) + pow(b, 2) == pow(hypotenuse, 2)) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        bool right = false;

        if (a > c && a > b) {
            right = isTri(a, b, c);
        } else if (b > a && b > c) {
            right = isTri(b, a, c);
        } else if (c > a && c > b) {
            right = isTri(c, a, b);
        }

        if (right) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }

    return 0;
}