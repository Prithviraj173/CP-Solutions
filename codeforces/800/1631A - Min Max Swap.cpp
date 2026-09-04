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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    vector<ll> brr(n);
    for(ll i = 0; i < n; i++) cin >> brr[i];
    ll ans1 = 0, ans2 = 0;
    for(ll i = 0; i < n; i++) {
        ll maxi = max(arr[i], brr[i]);
        ll mini = min(arr[i], brr[i]);
        ans1 = max(ans1, maxi);
        ans2 = max(ans2, mini);
    }
    cout << 1LL * ans1 * ans2 << endl;
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