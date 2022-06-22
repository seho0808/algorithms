/**
Approach: 
2 ways to solve inputs.
1. input is number and return string. =>  vector
2. input is string and return is inputted order integer =>  map

=> we could use two data structures.
=> is there a way to use both in a single data structure?

- reminds me of indexing in DB...

Conclusion:
seems like this is the best solution.

 */

 #include <vector>
 #include <map>
 #include <iostream>

 using namespace std;

 int main() {
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    map<string, int> rbtree;
    vector<string> v(n+1,"");
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        rbtree.insert(pair<string, int> (s, i));
        v[i] = s;
    }

    vector<string> temp;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        temp.push_back(s);
    }
    for (int i = 0; i < m; i++) {
        string s = temp[i];
        // cout << s << " " << s[0] << " " << isdigit(s[0]) << endl;
        if (isdigit(s[0])) {
            cout << v[stoi(s)] << "\n";
        } else {
            cout << rbtree[s] << "\n";
        }
    }

    return 0;
 }