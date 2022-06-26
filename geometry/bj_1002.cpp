#include <cmath>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x1, y1, r1, x2, y2, r2;
    // x1 y1과 x2 y2의 거리가 r1+r2 보다 크면 0, 같으면 1, 작으면 2
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int temp1 = abs(x2-x1);
        int temp2 = abs(y2-y1);
        // this is better cz no double required
        //int d = temp1*temp1+temp2*temp2;
        //int rsum = (r1+r2)*(r1+r2);
        //int rsub = (r1-r2)*(r1-r2);
        double d = sqrt(temp1*temp1+temp2*temp2);
        double rsum = r1+r2;
        double rsub = abs(r1-r2);

        if (d == 0) { // 동심원
            if (rsub == 0) {
                cout << -1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (d == rsum || d == rsub) { // 외접원과 내접원
            cout << 1 << "\n";
        } else  if (rsub < d && d < rsum) {  // 2개의 점이 만나는 원
            cout << 2 << "\n";
        } else {
            cout << 0 << "\n";
        }
    } 

    return 0;
}