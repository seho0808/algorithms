/**
거리의 정의: D(T1,T2) = |x1-x2| + |y1-y2|
이 식대로 손가락을 따라가보면 다이아몬드 형태가 나온다.
주어진 거리만큼 최대한 사용해서 위아래 좌우 가능하기에 
(주어진수*2)**2/2 = n*n*2 하면 다이아몬드의 크기이다.
*/

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double n; // float 왜 안되는지 좀 이상하다. 
    cin >> n;
    cout << fixed;
    cout.precision(6);
    cout << M_PI*n*n << '\n' << n*n*2;

    return 0;
}