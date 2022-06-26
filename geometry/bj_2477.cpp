/**
남북 방향은 height. 동서 방향은 width.
height_max*width_max - height_min*width_min 하면됨.
*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>>  v(6, make_pair(0, 0));
    int max_height_index;
    int max_height_val = 0;
    int max_width_index;
    int max_width_val = 0;
    for (int i = 0; i < 6; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
        if (a == 4 || a == 3) {
            if (max_height_val < b) {
                max_height_val = b;
                max_height_index = i;
            }
        } else {
            if (max_width_val < b) {
                max_width_val =  b;
                max_width_index = i;
            }           
        }
    }
    // cout << max_width_index <<" " << max_width_val << " " <<  max_height_index << " " << max_height_val ;
    int res;
    // 기역 / 니은 은 (max_height_index + 3or4)%6을 해야된다.
    // 기역 / 니은 은 max_width가 바로 다음에 온다.
    if ((max_height_index+1)%6 == max_width_index) {
        int temp = v[(max_height_index+3)%6].second * v[(max_height_index+4)%6].second;
        res = max_height_val*max_width_val - temp;
    } else {
    // 좌우반전 기역니은은 width에 해야한다.
        int temp = v[(max_width_index+3)%6].second * v[(max_width_index+4)%6].second;
        res = max_height_val*max_width_val - temp;
    }

    cout << res*n;

    return 0;
}