#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> xs(3, 0);
    vector<int> ys(3, 0);
    for (int i = 0; i < 3; i++) {
        cin >>  xs[i] >> ys[i];
    }
    int x;
    int y;
    if (xs[0] == xs[1]) {
        x = xs[2];
    } else if (xs[0] == xs[2]) {
        x = xs[1];
    } else {
        x = xs[0];
    }

    if (ys[0] == ys[1]) {
        y = ys[2];
    } else if (ys[0] == ys[2]) {
        y = ys[1];
    } else {
        y = ys[0];
    }

    cout << x << " " << y;
}