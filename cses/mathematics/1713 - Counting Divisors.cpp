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
    return 63 - __builtin_clzll(n);
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
    ll maxi = -INFLL;
    for(ll i = 0; i < (ll)v.size(); i++){
        if(v[i] > maxi){
            maxi = v[i];
        }
    }
    return maxi;
}
ll vmin(vector<ll> &v){
    ll mini = INFLL;
    for(ll i = 0; i < (ll)v.size(); i++){
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
mt19937_64 randll(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1000000;
int spf[MAXN + 1];
vector<int> primes;

void precompute() {
    for (int i = 2; i <= MAXN; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || (ll)i * p > MAXN) break;
            spf[i * p] = p;
        }
    }
}

inline ll countDivisors(int n) {
    ll total_divisors = 1;
    while (n > 1) {
        int p = spf[n];
        int count = 0;
        while (n % p == 0) {
            count++;
            n /= p;
        }
        total_divisors *= (count + 1);
    }
    return total_divisors;
}

void solve() {
    int n;
    cin >> n;
    cout << countDivisors(n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    ll t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}