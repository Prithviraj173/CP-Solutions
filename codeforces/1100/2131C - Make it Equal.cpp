#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define vout(A) for(int i = 0; i < A.size(); i++) {cout << A[i] << " ";} cout << endl;
#define ll long long
#define ull unsigned long long
#define yes cout <<"YES"<<endl;
#define no cout <<"NO"<<endl;
#define inc(a) sort(a.begin(), a.end());
#define rev(a) sort(a.rbegin(), a.rend());
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((a * b) / gcd(a, b))
#define f(i,s,e) for(int i = s; i < e; i++)
const int MOD = 1e9 + 7;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> s(n), t(n);
    for(ll i = 0; i < n; i++) {
        cin >> s[i];
        ll r = s[i] % k;
        s[i] = min(r, (k - r) % k);
    }
    for(ll i = 0; i < n; i++) {
        cin >> t[i];
        ll r = t[i] % k;
        t[i] = min(r, (k - r) % k);
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t) yes
    else no
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