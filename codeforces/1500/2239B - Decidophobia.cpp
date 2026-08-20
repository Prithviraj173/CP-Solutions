#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> a3(3 * n);
    for (int i = 0; i < 3 * n; ++i) a3[i] = a[i % n];
    vector<long long> pref(3 * n + 1, 0);
    for (int i = 0; i < 3 * n; ++i) pref[i + 1] = pref[i] + a3[i];
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int mid = n + i;
        int L = mid - d, R = mid + d;
        long long sum = pref[R + 1] - pref[L], W = (2LL * d + 1) * a[i] - sum;
        if (W > 0) ans += W;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}