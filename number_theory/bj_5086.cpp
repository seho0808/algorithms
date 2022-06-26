// 약수 문제
#include <vector>
#include <iostream>
using namespace std;
int main() {
    while (true){
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        // factor
        if (b%a == 0) {
            cout << "factor" << '\n';
            continue;
        }
        // multiple
        if (a%b == 0) {
            cout << "multiple" << '\n';
            continue;
        }
        // neither
        cout << "neither" << '\n';
    }
    return 0;
}