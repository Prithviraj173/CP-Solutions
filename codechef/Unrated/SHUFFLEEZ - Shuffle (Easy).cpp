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
#define endl '\n'
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
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 randll(chrono::steady_clock::now().time_since_epoch().count());

const int M = 998244353, MAXN = 200005;
long long f[MAXN];

void precompute() {
    f[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        f[i] = (f[i - 1] * i) % M;
    }
}

long long power(long long base, long long exp) {
    long long res = 1;
    base %= M;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
    }
    ll ans = power(k, n - k + 1);
    ans = (ans * f[k - 1]) % M;
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}