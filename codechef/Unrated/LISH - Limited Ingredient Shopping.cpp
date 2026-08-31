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
    ll w, n;
    cin >> w >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    vector<ll> brr = arr;
    vector<ll> ans(2 * n);
    for(ll i = 0; i < n; i++) ans[i] = arr[i];
    for(ll i = n; i < 2 * n; i++) ans[i] = brr[i - n];
    sort(ans.begin(), ans.end());
    ll count = 0, sum = 0;
    for(ll i = (2 * n) - 1; i >= 0; i--) {
        if(sum >= w) break;
        sum += ans[i];
        count++;
    }
    if(sum >= w) cout << count << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}