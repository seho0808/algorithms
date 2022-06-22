#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool binary_search(vector<string> &v, string s) {
    int low = 0; int high = v.size()-1;
    while (low <= high) {
        int mid = (low+high)/2;
        int comp = v[mid].compare(s);
        if (comp == 0) {
            return true;
        } else if (comp < 0) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (binary_search(v, s)) cnt++;
    }

    cout << cnt;

    return 0;
}