#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> count(26, 0);
    for(char c : s) count[c - 'a']++;
    int ones = 0, twos = 0;
    for(int i = 0; i < 26; i++) {
        ones += count[i] % 2;
        twos += count[i] / 2;
    }
    int cur = twos / k, rem = ones + (twos % k) * 2;
    if(rem >= k) cout << 2 * cur + 1 << endl;
    else cout << 2 * cur << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}