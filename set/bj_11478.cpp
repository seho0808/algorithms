/**
ababc
12
=> 유니크한 부분 문자열 개수 구하기.
1짜리 윈도우로 맵 삽입
2짜리 윈도우로 맵 삽입
3짜리 "
....
=> Time Complexity는 n + n-1 + ... + 1 = n(n+1)/2 => O(n^2) 에다가 insert는 O(1)~O(n)이니까 총 n^2
*/

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
    string str;
    cin >> str;
    unordered_set<string> s;
    int length = str.length();
    for (int i = 1; i <= length; i++) { // i is the window size
        for (int j = 0; j <= length-i; j++) { // j is the starting index
            string curr = str.substr(j, i); // from j to j+i
            s.insert(curr);
        }
    }
    cout << s.size();
    
    return 0;
}