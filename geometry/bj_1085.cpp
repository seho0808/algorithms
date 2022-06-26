// 6 2 10 3 => 1
// 653 375 1000 1000 => 347
// 161 181 762 375 => 161
#include <iostream>
using namespace std;
int main() {
    int  x, y, w, h;
    cin >> x >> y >> w >> h;
    int ans = x;
    ans = min(ans, y);
    ans = min(ans, w-x);
    ans = min(ans, h-y);

    cout << ans;

    return 0;
}