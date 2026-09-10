#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define ll long long
#define pr pair<ll, ll>
#define vpr(v,n) vector<pair<ll,ll>>v(n)
#define pb push_back
#define forn(i,n) for(ll i=0;i<n;i++)
#define forsn(i,s,n) for(ll i=s;i<n;i++)
#define rforn(i,n) for(ll i=n-1;i>=0;i--)
#define endl '\n';
#define all(v) v.begin(),v.end()
#define vi(v,n) vector<ll>v(n)
const ll INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9 + 7;
inline ll logvalue(ll n) {
    if (n <= 0) return -1;
    return 31 - __builtin_clz(n);
}
ll sum_n(ll n) { 
    return n * (n+1) / 2;
}
ll fact(ll n){
    ll res = 1;
    while(n > 1){
        res *= n;
        n--;
    }
    return res;
}
ll ncr(ll n, ll r){
    return fact(n)/(fact(n-r)*fact(r));
}
ll npr(ll n, ll r){
    return fact(n)/fact(n-r);
}
ll vmax(vector<ll> &v){
    ll maxi = (-1)*INF;
    for(ll i = 0; i < v.size(); i++){
        if(v[i] > maxi){
            maxi = v[i];
        }
    }
    return maxi;
}
ll vmin(vector<ll> &v){
    ll mini = INF;
    for(ll i = 0; i < v.size(); i++){
        if(v[i] < mini){
            mini = v[i];
        }
    }
    return mini;
}
ll gcdll(ll a, ll b){
    return __gcd(a,b);
}
 
ll lcmll(ll a, ll b){
    return (a/gcdll(a,b))*b;
}
bool isprime(ll n){
    if(n < 2) return false;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
ll power(ll a, ll b){ //O(log(b))
    ll res = 1;
    while(b){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    string s;
    cin >> s;
    vector<int> res;
    int n = s.length();
    for(ll i = 0; i < n; i++) {
        if(s[i] == '@') res.push_back(i);
    }
    if(res.empty()) {
        cout << "No solution" << endl;
        return;
    }
    ll m = res.size();
    if(res[0] == 0 || res[m - 1] == n - 1) {
        cout << "No solution" << endl;
        return;
    }
    for(ll i = 0; i < m - 1; i++) {
        if(res[i + 1] - res[i] < 3) {
            cout << "No solution" << endl;
            return;
        }
    }
    vector<string> ans;
    ll st = 0;
    for(ll i = 0; i < m - 1; i++) {
        int cur = res[i] + 2;
        ans.push_back(s.substr(st, cur - st));
        st = cur;
    }
    ans.push_back(s.substr(st));
    for(ll i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if(i < ans.size() - 1) cout << ",";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}