#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500001

using namespace std;

bool binary_search(vector<int> &v, int wanted) {
    int  low = 0; int high = v.size()-1;
    while(low <= high) {
        int mid = (low+high)/2;
        if (wanted > v[mid])  {
            low = mid+1;
        } else if (wanted == v[mid]){
            return true;
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
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    cin >> m;

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        bool doesExist = binary_search(v, b);
        if (doesExist) {
            cout << 1 << " ";
        } else { 
            cout << 0 << " ";
        }
    }

    return 0;
}