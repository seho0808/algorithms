/**
나머지와 공약수
교훈1: 수학문제는 수식으로 푸는게 좋다. 수식으로 적자.
교훈2: r을 제거하면 M으로 무언가를 할 수 있다는 직관.
교훈3: 여러개의 공통 gcd를 구할 때는 gcd를 연속해서 apply하면됨.
교훈4: 약수 빨리뽑기는 i*i으로.
풀이:
v[0] = k0*M + r
v[1] = k1*M + r
v[2] = k2*M + r
...
=> 조건에 따라 위를 만족하는 r이 모두 같은 M이 있다.
v[1] - v[0] = (k1 - k0)*M
v[2] - v[1] = (k2 - k1)*M
v[3] - v[2] = (k3 - k2)*M
...
=> 위처럼 빼준 식에서 v[i] - v[i-1]은 모두 M을 약수로 갖는다.
가능한 가장 큰 M을 찾고 그 M의 약수들을 찾는 것이 답이므로,
v[i] - v[i-1]의 최대공약수의 약수들이
곧 정답이다. (1을 제외한.)
=> 왜 M의 약수들을 찾는지의 이유. M1이 가장 큰 가능한 M
보다 작은 어떤 수라고 했을 때,
v[1] - v[0] = (k1 - k0)*M
v[1] - v[0] = (q1 - q0)*M1
위와 같이 q1, q0으로 값들이 바뀌어야한다. 그런데,
(k1 - k0)*M = (q1 - q0)*M1 이고,
M이 가능한 가장 큰 약수이면, M1의 약수에 포함될 수 있는 모든 수는
M도 약수로 가지고 있어야함으로 M1은 무조건 M의 약수이다.
고로, M1...Mn은 가능한 가장 큰 M의 약수이다.

!!!핵심: r을 제거하면 M으로 무언가를 할 수 있다는 직관
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
    while(b!=0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    int max_gcd = v[1] - v[0];
    for (int i = 2; i < n; i++) {
        max_gcd = gcd(max_gcd, v[i] - v[i-1]);
    }

    // print divisors
    vector<int> divs;
    for (int i = 2; i*i <= max_gcd; i++) {
        if (max_gcd%i == 0) {
            divs.push_back(i);
            if (i*i != max_gcd) divs.push_back(max_gcd/i); // 2*2일 때 2 두 개 push 됨.
        }
    }
    divs.push_back(max_gcd);
    sort(divs.begin(), divs.end());
    for (int i = 0; i < divs.size(); i++) {
        cout << divs[i] << '\n';
    }

    return 0;
}