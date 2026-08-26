#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define vout(A) for(int i = 0; i < A.size(); i++) {cout << A[i] << " ";} cout << endl;
#define ll long long
#define ull unsigned long long
#define yes cout << "YES" <<endl;
#define no cout << "NO" <<endl;
#define inc(a) sort(a.begin(), a.end());
#define rev(a) sort(a.rbegin(), a.rend());
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a * b) / gcd(a, b))
#define f(i,s,e) for(int i = s; i < e; i++)
const int MOD = 1e9 + 7;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll m = -1;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        m = max(m, arr[i]);
    }
    string s;
    cin >> s;
    if(s[0] == s[n - 1]) {
        int idx = -1;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] != s[i + 1]) {
                idx = i + 1;
                break;
            }
        }
        if(idx != -1) {
            rotate(arr.begin(), arr.begin() + idx, arr.end());
            rotate(s.begin(), s.begin() + idx, s.end());
        }
    }
    vector<ll> cur;
    ll maxi = arr[0];
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) maxi = max(maxi, arr[i]);
        else {
            cur.push_back(maxi);
            maxi = arr[i];
        }
    }
    cur.push_back(maxi);
    int total = 0, st = -1;
    for(int i = 0; i < cur.size(); i++) {
        if(cur[i] == m) {
            total++, st = i;
        }
    }
    if(total > 1) cout << 2 * m << endl;
    else {
        ll res = -1;
        for(int i = 0; i < cur.size(); i++) {
            if(i == st) continue;
            res = max(res, cur[i]);
        }
        cout << m + res << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}