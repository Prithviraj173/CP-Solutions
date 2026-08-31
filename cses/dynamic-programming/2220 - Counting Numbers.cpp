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

ll dp[2][11][20][2];

ll func(string &s, bool tight, ll prev, ll idx, bool lz) {
    if(idx == s.size()) return 1;
    if(dp[tight][prev][idx][lz] != -1) return dp[tight][prev][idx][lz];
    ll lb = 0, ub = (tight == true) ? (s[idx] - '0') : 9;
    ll res = 0;
    for(ll i = lb; i <= ub; i++) {
        if(i == prev && !lz) continue;
        res += func(s,((tight && i == ub) ? 1 : 0), i, idx + 1, (lz && i == 0));
    }
    return dp[tight][prev][idx][lz] = res;
}

void solve() {
    ll a,b;
    cin >> a >> b;
    string l = to_string(a - 1), r = to_string(b);
    memset(dp, -1, sizeof(dp));
    ll A = func(l,1,10,0,1);
    memset(dp, -1, sizeof(dp));
    ll B = func(r,1,10,0,1);
    cout << B - A << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}