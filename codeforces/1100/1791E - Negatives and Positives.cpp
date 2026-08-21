#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int count = 0, mini = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(arr[i] < 0) count++;
    }
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += abs(arr[i] - 0);
        mini = min(mini, abs(arr[i] - 0));
    }
    if(count & 1) cout << sum - 2 * mini << endl;
    else cout << sum << endl;
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