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
    vector<ll> st(n);
    for(ll i = 0; i < n; i++) cin >> st[i];
    st.erase(unique(st.begin(), st.end()), st.end());
    ll m = st.size();
    if(m == 1) {
        cout << 1 << endl;
        return;
    } else {
        ll ans = 2;
        for(ll i = 1; i < m - 1; i++) {
            if((st[i - 1] < st[i] && st[i] > st[i + 1]) || (st[i - 1] > st[i] && st[i] < st[i + 1])) ans++;
        }
        cout << ans << endl;
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