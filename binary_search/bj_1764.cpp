/**
그냥 binary search 두개라서 시간은 nlog(n) 으로 보여짐. 공간은 n

3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton

2
baesangwook
ohhenrie
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool binary_search(vector<string> &v, string a) {
    int low = 0; int high = v.size()-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if (v[mid].compare(a) == 0) {
            return true;
        } else if (v[mid].compare(a) < 0) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; 
    cin >> n >> m;
    vector<string> v1(n, ""); 
    vector<string> v2;
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());

    for (int i = 0; i < m; i++){
        string curr;
        cin >> curr;
        if (binary_search(v1, curr)) {
            v2.push_back(curr);
        }
    }
    sort(v2.begin(), v2.end());

    cout << v2.size() << '\n';
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << '\n';
    }
    
    return 0;
}